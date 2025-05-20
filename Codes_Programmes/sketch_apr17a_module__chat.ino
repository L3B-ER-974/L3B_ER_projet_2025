int sensorPin = 2;
volatile long pulse;
unsigned long lastTime;
float rpm;
unsigned long seconde;        //base de temps à 1 seconde
const int pulsesPerRevolution = 3; // Change ce nombre si ton capteur a plus ou moins d’impulsions par tour

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(sensorPin), increase, RISING);
  seconde=millis();
}

void loop() {
  if (millis()-seconde>=1000); //base de temps d'une seconde
    seconde=millis();
  rpm = (pulse / (float)pulsesPerRevolution); // tours par seconde

  if (millis() - lastTime > 1000) {
    Serial.print("Tours par seconde : ");
    Serial.println(rpm);

    pulse = 0;
    lastTime = millis();
  }
}

void increase() {
  pulse++;
}
