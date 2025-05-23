volatile int pulseCount = 0; //Nombre de pulse detectés par le capteur
float flowRate = 0.0;
unsigned long lastTime = 0;
const float pipeDiameter = 0.01055; //Diamètre du tuyau en mètre  (exemple: 1.055cm)
const float pipePerimeter = 3.14159 * pipeDiameter; //Perimetre en m/tr

void setup(){
  Serial.begin(9600); //Initialisation de la communication série à 9600 bauds
  pinMode(3,INPUT); //Définition de la broche 3 comme entrée pour le capteur
  attachInterrupt(digitalPinToInterrupt(2),pulseCounter, FALLING);//Déclenche l'interruption sur un front descendant
}

void loop() {
  if (millis()- lastTime >= 1000){//Toutes les secondes //Vérifie si une secondde s'est écoulée
    lastTime = millis();
    flowRate = pulseCount / 7.5; //Calcule le débit en tr/s (7.5 pulses = 1 tr/s)
    float flowRateMps = (flowRate * pipePerimeter); //Convertit le débit en m/s

    Serial.print("Vitesse:");
    Serial.print(flowRateMps, 6); //Affiche avec 6 décimales
    Serial.println("m/s");
    pulseCount = 0; //Réinitialise le compteur d'impultions
  }
}

void pulseCounter(){
  pulseCount++; //Incrémente le compteur d'impulsions à chaque appel
}
