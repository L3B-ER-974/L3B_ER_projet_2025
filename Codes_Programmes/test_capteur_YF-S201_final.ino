#include <CAN.h>

unsigned int Vitesse_cm_s = 1000; // 0,00ms = 25,00m/s
unsigned int pulseCount = 0; // Nombre de pulses détectés par le capteur
float flowRate = 0.0;
unsigned long lastTime = 0;
const float pipeDiameter = 0.01055; // Diamètre du tuyau en mètres (ex: 1.055 cm)
const float pipePerimeter = 3.14159 * pipeDiameter; // Périmètre du tuyau en m
const float perimeter_cm = pipePerimeter *100;//en cm
void setup() {
  // start the CAN bus at 250 kbps
  CAN.begin(250E3);
  Serial.begin(9600); // Initialisation de la communication série à 9600 bauds
  pinMode(5, INPUT); // Broche 5 en entrée pour le capteur

  TCCR1A = 0;     // Mode normal
  TCCR1B = 0;     
  TCCR1B = 0x06;  // Clock externe sur front montant via T1 (broche D5)
  TCNT1 = 0;      // Remise à zéro du compteur
  
}

void loop() {
  if ((millis() - lastTime) == 1000) { // Toutes les secondes
    lastTime = millis();
    unsigned int count = TCNT1;
    flowRate = (float(count) * perimeter_cm/1.0);  // Calcule le débit en cm/s
    Vitesse_cm_s = int(flowRate) ; 
     TCNT1 = 0;      // Remise à zéro du compteur
   
  
    //transmission sur bus CAN
  
    CAN.beginExtendedPacket(0x9F50301);  
    CAN.write(0xFF);
    CAN.write(Vitesse_cm_s & 0x00FF);     // LSB Vitesse relative sur l'eau x0.01m/s
    CAN.write((Vitesse_cm_s >> 8) & 0x00FF);         // MSB Vitesse relative sur l'eau x0.01m/s
    CAN.write(pulseCount & 0x00FF);
    CAN.write((pulseCount >> 8) & 0x00FF);
    CAN.write(0xFF);
    CAN.write(0xFF);
    CAN.write(0xFF);
    CAN.endPacket();
    pulseCount = 0;// Réinitialisation du compteur
  }
}
