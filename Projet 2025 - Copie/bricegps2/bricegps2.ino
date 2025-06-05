#include <SoftwareSerial.h>
#include <CAN.h>

// --- GPS via SoftwareSerial ---
SoftwareSerial gpsSerial(4, 3); // RX, TX (D4 ← GPS TX)

// --- NMEA buffer ---
#define BUFFER_SIZE 128
char nmeaBuffer[BUFFER_SIZE];
int index = 0;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("Initialisation du GPS...");

  // Initialisation du bus CAN à 500 kbps
  if (!CAN.begin(500E3)) {
    Serial.println("Erreur initialisation CAN !");
    while (1);
  } else {
    Serial.println("CAN initialisé à 500 kbps.");
  }
}

void loop() {
  while (gpsSerial.available()) {
    char c = gpsSerial.read();

    if (c == '\n') {
      nmeaBuffer[index] = '\0'; // Fin de chaîne
      if (strstr(nmeaBuffer, "$GPRMC")) {
        parseTimeFromGPRMC(nmeaBuffer);
      }
      index = 0; // Reset du buffer
    } else {
      if (index < BUFFER_SIZE - 1) {
        nmeaBuffer[index++] = c;
      }
    }
  }
}

void parseTimeFromGPRMC(const char* sentence) {
  const char* ptr = strchr(sentence, ','); // Aller au champ de l'heure
  if (ptr != NULL) {
    ptr++; // Champ heure

    char hour[3], minute[3], second[3];
    if (strlen(ptr) >= 6) {
      strncpy(hour, ptr, 2); hour[2] = '\0';
      strncpy(minute, ptr + 2, 2); minute[2] = '\0';
      strncpy(second, ptr + 4, 2); second[2] = '\0';

      // Convertir heure UTC → heure locale (ex: UTC+2)
      int h = atoi(hour);
      h = (h + 2) % 24;

      // Afficher l'heure locale sur port série
      Serial.print("Heure locale : ");
      if (h < 10) Serial.print('0');
      Serial.print(h); Serial.print(":");
      Serial.print(minute); Serial.print(":");
      Serial.println(second);

      // Créer message CAN : HHMMSS (sous forme de chaîne)
      char canMessage[7]; // 6 caractères + null terminator
      snprintf(canMessage, sizeof(canMessage), "%02d%s%s", h, minute, second);

      // Envoyer message sur le bus CAN avec ID 0x100
      CAN.beginPacket(0x100); // ID standard (11 bits)
      for (int i = 0; i < 6; i++) {
        CAN.write(canMessage[i]);
      }
      CAN.endPacket();

      Serial.println("Heure envoyée sur le bus CAN.");
    }
  }
}
