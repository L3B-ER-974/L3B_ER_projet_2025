// GPS + CAN (Neo-6M + MCP2515) avec TinyGPSPlus sans SoftwareSerial
#include <TinyGPSPlus.h>
#include <CAN.h>

TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);  // UART0: utilisé à la fois pour GPS et debug  

  if (!CAN.begin(250E3)) {
   // Serial.println("Erreur: CAN non initialisé !");
    while (1);
  }
}

void loop() {
  while (Serial.available() > 0) {
    char c = Serial.read();
    gps.encode(c);
  }

  if (gps.time.isUpdated()) {
    int h = gps.time.hour();
    int m = gps.time.minute();
    int s = gps.time.second();

    h = (h + 4) % 24; // UTC+4 pour la Réunion

   //. Serial.print("Heure GPS : ");
   // Serial.print(h); Serial.print(":");
   // Serial.print(m); Serial.print(":");
   // Serial.println(s);

    // Envoi CAN
    CAN.beginExtendedPacket(;902); // ID personnalisé pour heure UTC
    CAN.write(h);
    CAN.write(m);
    CAN.write(s);
    CAN.endPacket();

    delay(1000); // pour éviter les envois trop fréquents
  }
}