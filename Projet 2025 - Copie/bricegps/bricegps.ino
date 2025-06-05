#include <SoftwareSerial.h>

SoftwareSerial gpsSerial(4, 3); // RX, TX (Arduino reçoit sur D4)

// --- Configuration ---
#define BUFFER_SIZE 128
char nmeaBuffer[BUFFER_SIZE];
int index = 0;

void setup() {
  Serial.begin(9600);       // Pour communiquer avec le PC
  gpsSerial.begin(9600);    // Pour communiquer avec le GPS Neo-6M
  Serial.println("Initialisation du GPS...");
}

void loop() {
  while (gpsSerial.available()) {
    char c = gpsSerial.read();

    if (c == '\n') {
      nmeaBuffer[index] = '\0'; // Fin de ligne
      if (strstr(nmeaBuffer, "$GPRMC")) {
        parseTimeFromGPRMC(nmeaBuffer); // On traite la ligne
      }
      index = 0; // Réinitialise le buffer
    } else {
      if (index < BUFFER_SIZE - 1) {
        nmeaBuffer[index++] = c;
      }
    }
  }
}

void parseTimeFromGPRMC(const char* sentence) {
  // Exemple de trame : $GPRMC,123519.00,A,...
  const char* ptr = strchr(sentence, ','); // Va au premier champ (heure)
  if (ptr != NULL) {
    ptr++; // On est sur le champ de l'heure UTC

    char hour[3], minute[3], second[3];
    if (strlen(ptr) >= 6) {
      strncpy(hour, ptr, 2); hour[2] = '\0';
      strncpy(minute, ptr + 2, 2); minute[2] = '\0';
      strncpy(second, ptr + 4, 2); second[2] = '\0';

      // Conversion en entier pour ajuster le fuseau horaire
      int h = atoi(hour);
      h = (h + 4) % 24; // UTC+2 pour la France (en été)

      // Affichage formaté
      Serial.print("Heure locale : ");
      if (h < 10) Serial.print('0');
      Serial.print(h); Serial.print(":");
      Serial.print(minute); Serial.print(":");
      Serial.println(second);
    }
  }
}