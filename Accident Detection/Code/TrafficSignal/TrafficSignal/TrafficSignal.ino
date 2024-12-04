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

digitalWrite(y4, LOW);    
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(g4, HIGH);

delay(9000);



digitalWrite(g4, LOW);
digitalWrite(r4, HIGH);
digitalWrite(r1, LOW);
digitalWrite(y1, HIGH);

delay(1500);



digitalWrite(y1, LOW);
digitalWrite(g1, HIGH);

delay(9000);



digitalWrite(g1, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, LOW);
digitalWrite(y2, HIGH);

delay(1500);



digitalWrite(y2, LOW);
digitalWrite(g2, HIGH);

delay(9000);



digitalWrite(g2, LOW);
digitalWrite(r2, HIGH);
digitalWrite(r3, LOW);
digitalWrite(y3, HIGH);

delay(1500);



digitalWrite(y3, LOW);
digitalWrite(g3, HIGH);

delay(9000);



digitalWrite(g3, LOW);
digitalWrite(r3, HIGH);
digitalWrite(r4, LOW);
digitalWrite(y4, HIGH);

delay(1500);


}
