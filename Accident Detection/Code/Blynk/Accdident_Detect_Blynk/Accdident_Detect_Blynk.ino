#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



char auth[] = "k7Pg-6AzTrjMN0-0kyPpRaTuTpKiy_dj";

char ssid[] = "IamNotAvailable";
char pass[] = "TelenorAvailable";


Adafruit_MPU6050 mpu;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(13, 15);  // RXPin = 13, TXPin = 15

#define vibr_pin 14
#define led 0

void setup() {
  
  Serial.begin(115200);

  ss.begin(9600);

  pinMode(vibr_pin,INPUT);
  pinMode(led, OUTPUT);

  Blynk.begin(auth, ssid, pass);

  
  while (!Serial)
    delay(10);

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  

  Serial.println("");
  delay(100);
}

void loop() {

   Blynk.run();
  
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.println("");

  long measurement =TP_init();
  
  delay(50);
  
  Serial.print("measurment = ");
  Serial.println(measurement);
  
  if (measurement > 700){
    Serial.println("Vibration");
  }
  else{
    Serial.println("----------");
  }


  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }


  
  
  

    if( (a.acceleration.x > 5) || (a.acceleration.x < -5) || (a.acceleration.y > 5) || (a.acceleration.y < -5) || (measurement > 700) ){

      Serial.println("Accident Detect");

      digitalWrite(led, HIGH);

      Serial.println();
      Serial.print(gps.location.lat(), 6);
      Serial.print(F(","));
      Serial.println(gps.location.lng(), 6);

      String body = String("Latitude: ") + gps.location.lat() + ", " + "Longitute: " + gps.location.lat();

      Blynk.email("maroofahmed@gmail.com", "Accident Detect", body);
      
    }else{

      digitalWrite(led, LOW);
      
    }

  delay(500);
  
}


long TP_init(){
  
  delay(10);
  long measurement = pulseIn (vibr_pin, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
  
}


void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();

  delay(200);
  
}
