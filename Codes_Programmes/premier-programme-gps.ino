/* /MonProjet_GPS_CAN/
├── main.cpp              ← Ton programme principal
├── TinyGPS++.cpp         ← Librairie GPS
├── TinyGPS++.h
├── SoftwareSerial.cpp    ← Librairie série logicielle
├── SoftwareSerial.h
├── mcp_can.cpp           ← Librairie CAN MCP2515
├── mcp_can.h#include <SoftwareSerial.h>
*/

#include <CAN.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// === Pins ===
#define GPS_RX 4  // NEO-6M TX -> Arduino RX (Soft)
#define GPS_TX 3  // NEO-6M RX -> Arduino TX (Soft, optionnel)

SoftwareSerial gpsSerial(GPS_RX, GPS_TX);
TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
  while (!Serial);  // attendre port série

  gpsSerial.begin(9600); // GPS baudrate

  Serial.println("Initialisation CAN...");

  if (!CAN.begin(500E3)) {
    Serial.println("Échec init CAN !");
    while (1);  // stop programme
  }

  Serial.println("CAN prêt !");
}

void loop() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isUpdated()) {
    Serial.print("GPS: ");
    Serial.print(gps.location.lat(), 6);
    Serial.print(", ");
    Serial.println(gps.location.lng(), 6);

    float lat = gps.location.lat();
    float lon = gps.location.lng();

    int32_t lat_i = lat * 1e7;
    int32_t lon_i = lon * 1e7;

    byte data[8];

    // Longitude
    data[0] = (lon_i >> 24) & 0xFF;
    data[1] = (lon_i >> 16) & 0xFF;
    data[2] = (lon_i >> 8) & 0xFF;
    data[3] = lon_i & 0xFF;

    // Latitude
    data[4] = (lat_i >> 24) & 0xFF;
    data[5] = (lat_i >> 16) & 0xFF;
    data[6] = (lat_i >> 8) & 0xFF;
    data[7] = lat_i & 0xFF;

    // Envoi standard ID (11 bits)
    CAN.beginPacket(0x123);  // identifiant standard
    CAN.write(data, 8);
    CAN.endPacket();
    Serial.println("Trame CAN envoyée.");

    delay(1000); // 1 Hz
  }
}
