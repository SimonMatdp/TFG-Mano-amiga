/*
  Programa de prueba para modulo L289N
*/

//-----------------------Defines-----------------------
//Para control pwm
#define ENA 5
#define ENB 10

//Para control de dirección 
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9

/*  
  IN1 IN2 Estado
  0   0   OFF
  1   0   DIR1
  0   1   DIR2
  1   1   FRENO ACTIVO (desaconsejado) 
*/


void setup() {
  //-----------------------Pinmodes-----------------------
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  //-----------------------Coms-----------------------
  //Serial.begin(9600);

  //-----------------------Test-----------------------
  analogWrite(ENA,100); //255 sobre 255
  
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  delay(1000);

  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  delay(200);

  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  delay(1000);

  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  delay(1000);

  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  for(int i=0; i<128; i++){
    analogWrite(ENA,i);
    delay(10);
  }
  
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
