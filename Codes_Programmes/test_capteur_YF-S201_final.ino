#include <CAN.h>

unsigned int Vitesse_cm_s = 1000; // 0,00ms = 25,00m/s
unsigned int pulseCount = 0; // Nombre de pulses détectés par le capteur
float flowRate = 0.0;
unsigned long lastTime = 0;
const float pipeDiameter = 0.01055; // Diamètre du tuyau en mètres (ex: 1.055 cm)
const float pipePerimeter = 3.14159 * pipeDiameter; // Périmètre du tuyau en m

void setup() {
  // start the CAN bus at 500 kbps
  CAN.begin(250E3);
  Serial.begin(9600); // Initialisation de la communication série à 9600 bauds
  pinMode(5, INPUT_PULLUP); // Broche 5 en entrée pour le capteur
  attachInterrupt(digitalPinToInterrupt(5), pulseCounter, FALLING); // Interruption sur front descendant attacher a la broche 5
}

void loop() {
  if (millis() - lastTime >= 1000) { // Toutes les secondes
    lastTime = millis();
    //flowRate = (100*(float(pulseCount) * pipePerimeter)) / 7.5 ; // Calcule le débit en cm/s
    flowRate = (float(pulseCount) * 0.47348) ; // Calcule le débit en cm/s
    pulseCount = 0;// Réinitialisation du compteur
    Vitesse_cm_s = int(flowRate*100) ; // Vitesse en m/s en entier
     
    //int (flowRateKmh) = flowRatemps * 3.6;         // Vitesse en km/h
    //int (flowRateKnots) = flowRatemps * 1.94384;   // Vitesse en nœuds
  
    //transmission sur bus CAN
 
  CAN.beginExtendedPacket(0x9F50301);  
  CAN.write(0xFF);
  CAN.write(Vitesse_cm_s & 0x00FF);     // LSB Vitesse relative sur l'eau x0.01m/s
  CAN.write((Vitesse_cm_s >> 8) & 0x00FF);         // MSB Vitesse relative sur l'eau x0.01m/s
  CAN.write(0xFF);
  CAN.write(0xFF);
  CAN.write(0xFF);
  CAN.write(0xFF);
  CAN.write(0xFF);
  CAN.endPacket();

  }
}

void pulseCounter() {
  pulseCount++; // Incrémentation à chaque impulsion
}
