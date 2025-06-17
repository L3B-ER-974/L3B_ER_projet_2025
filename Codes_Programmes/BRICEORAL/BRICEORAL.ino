#include <CAN.h>               // Bibliothèque CAN (MCP2515)
#include <TinyGPSPlus.h>       // Bibliothèque GPS

TinyGPSPlus GPS;

// Variables pour assembler les trames GPS
String inputString = "";
bool stringComplete = false;

void setup() {
  Serial.begin(9600);           // UART partagé entre GPS et debug

  if (!CAN.begin(250E3)) {      // Initialisation CAN à 250 kbps
    while (1);                  // Bloqué si CAN non détecté
  }
}

void loop() {
  // Lecture série du GPS caractère par caractère
  if (Serial.available() > 0) {
    char inChar = (char)Serial.read();
    GPS.encode(inChar);
    inputString += inChar;

    if (inChar == '\n') {
      if (inputString.startsWith("$GPRMC")) {
        stringComplete = true;
      } else {
        inputString = "";
      }
    }
  }

  if (stringComplete && GPS.time.isValid()) {
    char heure = GPS.time.hour(); 
    char minute = GPS.time.minute();
    char seconde = GPS.time.second();

    // Calcul du temps en tranches de 100 µs
    long totalSeconds = long(heure * 3600) + long(minute * 60) + seconde;
    long timestamp100us = long(totalSeconds * 10000);  // 1 s = 10 000 x 100 µs

    // Extraction des 4 octets (MSB à LSB)
    byte MSB = (timestamp100us >> 24) & 0x000000FF;
    byte MIDMSB = (timestamp100us >> 16) & 0x000000FF;
    byte MIDLSB = (timestamp100us >> 8) & 0x000000FF;
    byte LSB = timestamp100us & 0x000000FF;

    // Trame CAN NMEA2000 : 8 octets
  byte heureData[8] = {
  0xFF,  // DATA8
  0xFF,  // DATA7
  LSB,  // DATA6
  MIDLSB,   // DATA5
  MIDMSB,   // DATA4
  MSB,   // DATA3
  0xFF,  // DATA2
  0x7F   // DATA1
};

    // Envoi sur le bus CAN avec identifiant étendu NMEA2000
CAN.beginExtendedPacket(0x0DF80902);
CAN.write(heureData, 8);
CAN.endPacket();

    // (Optionnel) Affichage debug
    /*
    Serial.print("UTC : ");
    Serial.print(h); Serial.print(":");
    Serial.print(m); Serial.print(":");
    Serial.println(s);

    Serial.print("Trame CAN : ");
    for (int i = 0; i < 8; i++) {
      Serial.print(heureData[i], HEX); Serial.print(" ");
    }
    Serial.println();
    */

    // Réinitialisation
    inputString = "";
    stringComplete = false;
    delay(1000); // Anti-spam
  }
}
