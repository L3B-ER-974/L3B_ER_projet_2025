// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <CAN.h>
int Vitesse_m_s = 1000; // 0,00ms=25,00m/s
int Vitesse_Km_h;
int Vitesse_Nds;
void setup() {
  // start the CAN bus at 500 kbps
  if (!CAN.begin(250E3)) {
  
    while (1);
  }
}

void loop() {
  // send packet: id is 29 bits, packet can contain up to 8 bytes of data
  CAN.beginExtendedPacket(0x9F50301);  //sending water's temperature at 29°C = 30200 centi°K = 0x75
  CAN.write(0xFF);
  CAN.write(Vitesse_m_s & 0x00FF); //LSB Vitesse relative sur l'eau x0.01m/s
  CAN.write(Vitesse_m_s >> 8); //Vitesse relative sur l'eau x0.01m/s
  CAN.write(0xFF);
  CAN.write(0xFF);
  CAN.write(0xFF);
  CAN.write(0xFF);
  CAN.write(0xFF);
  CAN.endPacket();



  delay(1000);

  // send extended packet: id is 29 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending extended packet ... ");

  CAN.beginExtendedPacket(0x9F50301);
  CAN.write('w');
  CAN.write('o');
  CAN.write('r');
  CAN.write('l');
  CAN.write('d');
  CAN.endPacket();

  Serial.println("done");

  delay(1000);
}
