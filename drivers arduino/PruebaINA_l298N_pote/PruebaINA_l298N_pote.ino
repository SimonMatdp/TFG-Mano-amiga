#include <Wire.h>
#include <Adafruit_INA219.h>

#define PIN_POTE A0
//Para control pwm
#define ENA 5
#define ENB 10

//Para control de dirección 
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
/*  
  IN1/IN3 IN2/IN4   Estado
    0         0     OFF
    1         0     DIR1
    0         1     DIR2
    1         1     FRENO ACTIVO (desaconsejado) 
*/

//Para el INA
#define N_MUESTRAS 100
int i=0;

Adafruit_INA219 ina219;
float vector_mA[N_MUESTRAS];

void setup(void) 
{
  //Pinmodes L298N
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  
  //Startup motor A
  analogWrite(ENA,0);//Velocidad inicial =0
  
  //Coms
  Serial.begin(115200);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }

  uint32_t currentFrequency;  

  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
}

void loop(void) 
{
  //Medida del INA
  if(i>N_MUESTRAS-1)
  {
    i=0;
  }
  vector_mA[i++]=ina219.getCurrent_mA();
  float media=0;
  for(int j=0; j<N_MUESTRAS; j++){
    media+=vector_mA[j]/N_MUESTRAS;
  }
  Serial.println(media);
  
  //Control del motor
  if(Serial.available()>0){
    char incomingByte=Serial.read();
    switch(incomingByte){
      case '1':
        digitalWrite(IN1,0);
        digitalWrite(IN2,1);
        Serial.println("modo 1");
      break; 
      
      case '2':
        digitalWrite(IN1,1);
        digitalWrite(IN2,0);
        Serial.println("modo 2");
      break; 

      case '0':
        digitalWrite(IN1,0);
        digitalWrite(IN2,0);
        Serial.println("modo 0");
      break; 
    }   
  }

  //Control de velocidad
  int senial_pote=analogRead(PIN_POTE);
  int velPWM=map(senial_pote,0,1023,0,254);
  analogWrite(ENA, velPWM);
}
