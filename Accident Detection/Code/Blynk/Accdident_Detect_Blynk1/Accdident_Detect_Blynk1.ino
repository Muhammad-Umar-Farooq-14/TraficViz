#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



char auth[] = "k7Pg-6AzTrjMN0-0kyPpRaTuTpKiy_dj";

//char ssid[] = "IamNotAvailable";
//char pass[] = "TelenorAvailable";

char ssid[] = "IamVirus";
char pass[] = "XiaomiVirus";


Adafruit_MPU6050 mpu;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(13, 15);  // RXPin = 13, TXPin = 15

#define vibr_pin 14
#define led 0
#define btn 16

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;

const long interval = 60000;

bool acdnt = false;
bool btnvalue = false;

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
//    while (1) {
//      delay(10);
//    }
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

   currentMillis = millis();
  
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);


  long measurement = TP_init();
  
  delay(50);


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

      acdnt = true;

      
    }


    if(acdnt == true){

      btnvalue = digitalRead(btn);

      if (currentMillis - previousMillis >= interval) {
    
        previousMillis = currentMillis;

        Serial.println();
        Serial.print(gps.location.lat(), 6);
        Serial.print(F(","));
        Serial.println(gps.location.lng(), 6);

        String body = String("Latitude: ") + gps.location.lat() + ", " + "Longitute: " + gps.location.lng();

      Blynk.email("maroofahmed@gmail.com", "Accident Detect", body);

      Serial.println("Mail Sending");
      digitalWrite(led, LOW);
      acdnt = false;

      }

      else if(btnvalue == true){

        acdnt = false;
        digitalWrite(led, LOW);
        Serial.println("No Big Damage");
        
      }
      
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
    Serial.print(F("GPS OK"));
  }
  else
  {
    Serial.print(F("GPS INVALID"));
  }

  Serial.println();

  delay(200);
  
}
