#include <Wire.h>
#include <Adafruit_INA219.h>

#define PIN_POTE A0

//PWM motor speed
#define ENA 10
//#define ENB

//Motor direction 
#define IN1 8
#define IN2 9
//#define IN3 
//#define IN4 
/*  
  IN1/IN3 IN2/IN4   Estado
    0         0     OFF
    1         0     DIR1
    0         1     DIR2
    1         1     BRAKE (do not use) 
*/

//INA
#define N_SAMPLES 100
Adafruit_INA219 ina219;
float vector_mA[N_SAMPLES];
int i=0;

#define Vm 5
#define STEP_1V 255/Vm

void setup(void) 
{
  //Pinmodes L298N
  pinMode(ENA,OUTPUT);
  //pinMode(ENB,OUTPUT);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  //pinMode(IN3,OUTPUT);
  //pinMode(IN4,OUTPUT);
  
  //Startup motor A
  analogWrite(ENA,0);//Vo=0

  //Debugging
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
  if(i>N_SAMPLES-1)
  {
    i=0;
  }
  vector_mA[i++]=ina219.getCurrent_mA();
  float mAvrg=0; //Moving average (acting as low pass filter)
  for(int j=0; j<N_SAMPLES; j++){
    mAvrg+=vector_mA[j]/N_SAMPLES;
  }

  //Control del motor
  if(Serial.available()>0){
    char incomingByte=Serial.read();
    switch(incomingByte){
      case '1':
        digitalWrite(IN1,0);
        digitalWrite(IN2,1);
        //Serial.println("modo 1");
      break; 
      
      case '2':
        digitalWrite(IN1,1);
        digitalWrite(IN2,0);
        //Serial.println("modo 2");
      break; 

      case '0':
        digitalWrite(IN1,0);
        digitalWrite(IN2,0);
        //Serial.println("modo 0");
      break; 
    }   
  }

  //Control de velocidad
  //int senial_pote=analogRead(PIN_POTE);
  //int velPWM=map(senial_pote,0,1023,0,254);
  //analogWrite(ENA, velPWM);
  analogWrite(ENA, STEP_1V*1);

  //Medida posicion
  float pos = 140-analogRead(PIN_POTE)*0.18;
  //Serial.print("mAvrg [mA]");
  //Serial.print(mAvrg);
  //Serial.print(",");
  //Serial.print("Pos [rad]");
  Serial.print(pos);
  Serial.println("");
  //delay(10);
}
