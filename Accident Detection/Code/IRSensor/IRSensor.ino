int irsensor = A0;

int sensorvalue = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensorvalue = analogRead(irsensor);
  Serial.println(sensorvalue);
  delay(500);

}
