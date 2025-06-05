#include <CAN.h>               // Bibliothèque CAN (MCP2515)
#include <TinyGPSPlus.h>       // Bibliothèque GPS

TinyGPSPlus GPS;

// Variables pour assembler les trames GPS
String inputString = "";
bool stringComplete = false;

void setup() {
  Serial.begin(9600);           // UART matériel partagé entre GPS et debug

  if (!CAN.begin(250E3)) {      // Initialisation CAN à 250 kbps
    while (1); // Bloqué si CAN non détecté
  }
}

void loop() {
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
    int h = GPS.time.hour();
    int m = GPS.time.minute();
    int s = GPS.time.second();

    h = (h + 4) % 24; // passage UTC → UTC+4

    // Affichage sur moniteur série
    //Serial.print("Heure GPS : ");
    //Serial.print(h); Serial.print(":");
    //Serial.print(m); Serial.print(":");
    //Serial.println(s);

    // Préparer les données
    byte heureData[8] = {0};
    heureData[0] = h;
    heureData[1] = m;
    heureData[2] = s;

    // Envoi CAN
    CAN.beginExtendedPacket(0x0DF80902); // ID personnalisé pour heure UTC
    CAN.write(heureData, 8);             // On peut aussi envoyer juste 3 octets
    CAN.endPacket();

    // Reset
    inputString = "";
    stringComplete = false;
    delay(1000); // Anti-spam
  }
}



