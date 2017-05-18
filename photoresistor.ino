int light = 13;

int lightSensor = A0;
int lightValue = 0;

void setup() {

}

void loop() {
  lightValue = analogRead (lightSensor);

  if (lightValue > 0)
    digitalWrite (light, HIGH);
  else
    digitalWrite (light, LOW);

}
