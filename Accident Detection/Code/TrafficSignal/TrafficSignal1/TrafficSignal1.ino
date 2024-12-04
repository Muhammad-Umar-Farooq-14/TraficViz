int r1 = 2;
int y1 = 3;
int g1 = 4;
int r2 = 5;
int y2 = 6;
int g2 = 7;
int r3 = 8;
int y3 = 9;
int g3 = 10;
int r4 = 11;
int y4 = 12;
int g4 = 13;

unsigned long current0Millis = 0;
unsigned long previous0Millis = 0;
const long interval0 = 10000;

unsigned long current1Millis = 0;
unsigned long previous1Millis = 0;
const long interval1 = 20000;

unsigned long current2Millis = 0;
unsigned long previous2Millis = 0;
const long interval2 = 30000;

unsigned long current3Millis = 0;
unsigned long previous3Millis = 0;
const long interval3 = 40000;

unsigned long current4Millis = 0;
unsigned long previous4Millis = 0;
const long interval4 = 50000;

int count = 0;


void setup() {
  
pinMode (r1, OUTPUT);
pinMode (y1, OUTPUT);
pinMode (g1, OUTPUT);

pinMode (r2, OUTPUT);
pinMode (y2, OUTPUT);
pinMode (g2, OUTPUT);

pinMode (r3, OUTPUT);
pinMode (y3, OUTPUT);
pinMode (g3, OUTPUT);

pinMode (r4, OUTPUT);
pinMode (y4, OUTPUT);
pinMode (g4, OUTPUT);

}

void loop() { 

current0Millis = millis();
current1Millis = millis();
current2Millis = millis();
current3Millis = millis();
current4Millis = millis();

digitalWrite(y4, LOW);    
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(g4, HIGH);

if( (count == 0) && (current0Millis - previous0Millis >= interval0) ){
  
digitalWrite(y4, LOW);    
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(g4, HIGH);

count = 1;

}

if ( (count == 1) && (current1Millis - previous1Millis >= interval1) ){


digitalWrite(g4, LOW);
digitalWrite(r4, HIGH);
digitalWrite(r1, LOW);
digitalWrite(y1, HIGH);

delay(1000);

digitalWrite(y1, LOW);
digitalWrite(g1, HIGH);

previous1Millis = current1Millis;
count = 2;

}


if ( (count == 2) && (current2Millis - previous2Millis >= interval2) ){

digitalWrite(g1, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, LOW);
digitalWrite(y2, HIGH);

delay(1000);

digitalWrite(y2, LOW);
digitalWrite(g2, HIGH);

previous2Millis = current2Millis;
count = 4;

}


if ( (count == 4) && (current3Millis - previous3Millis >= interval3) ) {

digitalWrite(g2, LOW);
digitalWrite(r2, HIGH);
digitalWrite(r3, LOW);
digitalWrite(y3, HIGH);

delay(1000);

digitalWrite(y3, LOW);
digitalWrite(g3, HIGH);

previous3Millis = current3Millis;
count = 5;
}


if ( (count == 5) && (current4Millis - previous4Millis >= interval4) ){

digitalWrite(g3, LOW);
digitalWrite(r3, HIGH);
digitalWrite(r4, LOW);
digitalWrite(y4, HIGH);

delay(1000);

digitalWrite(y4, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(g4, HIGH);

previous4Millis = current4Millis;
count = 0;
}

}
