int speaker = 11;
int light = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode (speaker, OUTPUT);
  pinMode (light, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite (speaker, 3830);
  digitalWrite (light, HIGH);
  delay (200);
  analogWrite (speaker, 0);
  digitalWrite (light, LOW);
  delay (100);

}
