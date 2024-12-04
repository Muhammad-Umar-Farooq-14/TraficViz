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

int ir1 = A1;
int ir2 = A2;
int ir3 = A3;
int ir4 = A4;

bool ir1Read = true;
bool ir2Read = true;
bool ir3Read = true;
bool ir4Read = true;

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

detection();

for(int i = 0; i <= 20; i++){

detection();
  
digitalWrite(y4, LOW);    
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(g4, HIGH);

delay(500);

}


digitalWrite(g4, LOW);
digitalWrite(r4, HIGH);
digitalWrite(r1, LOW);
digitalWrite(y1, HIGH);

delay(1000);



for(int i = 0; i <= 20; i++){
  
  detection();

digitalWrite(y1, LOW);
digitalWrite(g1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(r4, HIGH);
  
  delay(500);

}



digitalWrite(g1, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, LOW);
digitalWrite(y2, HIGH);

delay(1000);



for(int i = 0; i <= 20; i++){
  
  detection();

digitalWrite(y2, LOW);
digitalWrite(g2, HIGH);
digitalWrite(r1, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(r4, HIGH);
  
  delay(500);

}



digitalWrite(g2, LOW);
digitalWrite(r2, HIGH);
digitalWrite(r3, LOW);
digitalWrite(y3, HIGH);

delay(1000);





for(int i = 0; i <= 20; i++){
  
  detection();

digitalWrite(y3, LOW);
digitalWrite(g3, HIGH);
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r4, HIGH);
  
  delay(500);

}



digitalWrite(g3, LOW);
digitalWrite(r3, HIGH);
digitalWrite(r4, LOW);
digitalWrite(y4, HIGH);

delay(1000);


}


void detection(){

    ir1Read = digitalRead(ir1);
    ir2Read = digitalRead(ir2);
    ir3Read = digitalRead(ir3);
    ir4Read = digitalRead(ir4);

    if(ir1Read == false){

      digitalWrite(g1, HIGH);
      digitalWrite(r2, HIGH);
      digitalWrite(r3, HIGH);
      digitalWrite(r4, HIGH);

      digitalWrite(r1, LOW);
      digitalWrite(g2, LOW);
      digitalWrite(g3, LOW);
      digitalWrite(g4, LOW);
      digitalWrite(y1, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(y3, LOW);
      digitalWrite(y4, LOW);

      delay(3000);

      digitalWrite(g1, LOW);
      digitalWrite(r2, LOW);
      digitalWrite(r3, LOW);
      digitalWrite(r4, LOW);

      
      
    }

    else if(ir2Read == false){

      digitalWrite(g2, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r3, HIGH);
      digitalWrite(r4, HIGH);

      digitalWrite(r2, LOW);
      digitalWrite(g1, LOW);
      digitalWrite(g3, LOW);
      digitalWrite(g4, LOW);
      digitalWrite(y1, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(y3, LOW);
      digitalWrite(y4, LOW);

      delay(3000);

      digitalWrite(g2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r3, LOW);
      digitalWrite(r4, LOW);
      
    }

    else if(ir3Read == false){

      digitalWrite(g3, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, HIGH);
      digitalWrite(r4, HIGH);

      digitalWrite(r3, LOW);
      digitalWrite(g1, LOW);
      digitalWrite(g2, LOW);
      digitalWrite(g4, LOW);
      digitalWrite(y1, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(y3, LOW);
      digitalWrite(y4, LOW);

      delay(3000);

      digitalWrite(g3, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);
      digitalWrite(r4, LOW);
      
    }

    else if(ir4Read == false){

      digitalWrite(g4, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, HIGH);
      digitalWrite(r3, HIGH);

      digitalWrite(r4, LOW);
      digitalWrite(g1, LOW);
      digitalWrite(g2, LOW);
      digitalWrite(g3, LOW);
      digitalWrite(y1, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(y3, LOW);
      digitalWrite(y4, LOW);

      delay(3000);

      digitalWrite(g4, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);
      digitalWrite(r3, LOW);
      
    }

}
