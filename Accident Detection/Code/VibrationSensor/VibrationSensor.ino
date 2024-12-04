#define vibr_pin 14

void setup() {

  Serial.begin(115200);
  
  pinMode(vibr_pin,INPUT);
}

void loop() {
  
  long measurement =TP_init();
  delay(50);
 // Serial.print("measurment = ");
  Serial.println(measurement);
  if (measurement > 700){
    Serial.println("Vibration");
  }
  else{
    Serial.println("----------");
  }

  delay(500);
  
}


long TP_init(){
  
  delay(10);
  long measurement = pulseIn (vibr_pin, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
  
}
