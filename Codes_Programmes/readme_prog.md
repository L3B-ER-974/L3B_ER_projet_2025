/*
 * GPS → CAN NMEA2000 (29-bit ID: 0x09F80102)
 * MCU: ATmega328P
 * GPS: NEO-6M (USART)
 * CAN: via <CAN.h>
 * Résolution: 0.1 µ°
 * Auteur : Nathan AURE (modifié)
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <CAN.h> // Bibliothèque officielle Arduino CAN (remplace mcp2515.h)

// === Variables GPS ===
char gps_buffer[100];
uint8_t gps_index = 0;
float latitude = 0.0;
float longitude = 0.0;

// === USART (pour GPS) ===
void USART_init(uint16_t ubrr) {
    UBRR0H = (ubrr >> 8);
    UBRR0L = ubrr;
    UCSR0B = (1 << RXEN0); // Activer réception
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8N1
}

char USART_receive(void) {
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

// === Parseur GPS NMEA ($GPGGA ou $GPGLL) ===
bool parse_gps_data(void) {
    if (strncmp(gps_buffer, "$GPGGA", 6) != 0 && strncmp(gps_buffer, "$GPGLL", 6) != 0)
        return false;

    char *ptr = gps_buffer;
    char lat_str[15] = {0}, lon_str[15] = {0};
    char ns = 'N', ew = 'E';
    uint8_t commas = 0, i = 0;

    while (*ptr && commas < 6) {
        if (*ptr == ',') commas++, ptr++;

        if (commas == 2 && *ptr != ',') {
            i = 0;
            while (*ptr != ',' && *ptr != '\0') lat_str[i++] = *ptr++;
            lat_str[i] = '\0';
        }
        if (commas == 3 && *ptr != ',') ns = *ptr;
        if (commas == 4 && *ptr != ',') {
            i = 0;
            while (*ptr != ',' && *ptr != '\0') lon_str[i++] = *ptr++;
            lon_str[i] = '\0';
        }
        if (commas == 5 && *ptr != ',') ew = *ptr;
    }

    float lat_raw = atof(lat_str);
    float lon_raw = atof(lon_str);

    int lat_deg = (int)(lat_raw / 100);
    float lat_min = lat_raw - (lat_deg * 100);
    latitude = lat_deg + lat_min / 60.0;
    if (ns == 'S') latitude = -latitude;

    int lon_deg = (int)(lon_raw / 100);
    float lon_min = lon_raw - (lon_deg * 100);
    longitude = lon_deg + lon_min / 60.0;
    if (ew == 'W') longitude = -longitude;

    return true;
}

// === Envoi CAN (via <CAN.h>) ===
void send_can_position(void) {
    int32_t lat_int = (int32_t)(latitude * 1e7);
    int32_t lon_int = (int32_t)(longitude * 1e7);

    // Paquet CAN étendu (ID 29 bits)
    CAN.beginExtendedPacket(0x09F80102);
    CAN.write((lon_int >> 24) & 0xFF);
    CAN.write((lon_int >> 16) & 0xFF);
    CAN.write((lon_int >> 8) & 0xFF);
    CAN.write(lon_int & 0xFF);
    CAN.write((lat_int >> 24) & 0xFF);
    CAN.write((lat_int >> 16) & 0xFF);
    CAN.write((lat_int >> 8) & 0xFF);
    CAN.write(lat_int & 0xFF);
    CAN.endPacket();
}

// === Setup / loop (remplace main) ===
void setup() {
    Serial.begin(9600);
    while (!Serial);

    Serial.println("Initialisation GPS + CAN");

    USART_init(103); // 9600 bauds @ 16 MHz

    if (!CAN.begin(500E3)) {
        Serial.println("Erreur CAN !");
        while (1);
    }
    Serial.println("CAN prêt");
}

void loop() {
    char c = USART_receive();

    if (c == '$') {
        gps_index = 0;
        gps_buffer[gps_index++] = c;
    } else if (c == '\n') {
        gps_buffer[gps_index] = '\0';
        if (parse_gps_data()) {
            Serial.print("Latitude: ");
            Serial.print(latitude, 7);
            Serial.print(" | Longitude: ");
            Serial.println(longitude, 7);
            send_can_position();
        }
    } else {
        if (gps_index < sizeof(gps_buffer) - 1) {
            gps_buffer[gps_index++] = c;
        }
    }
}
