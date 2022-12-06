template <int order> // order is 1 or 2
class LowPass
{
  private:
    float a[order];
    float b[order+1];
    float omega0;
    float dt;
    bool adapt;
    float tn1 = 0;
    float x[order+1]; // Raw values
    float y[order+1]; // Filtered values

  public:  
    LowPass(float f0, float fs, bool adaptive){
      // f0: cutoff frequency (Hz)
      // fs: sample frequency (Hz)
      // adaptive: boolean flag, if set to 1, the code will automatically set
      // the sample frequency based on the time history.
      
      omega0 = 6.28318530718*f0;
      dt = 1.0/fs;
      adapt = adaptive;
      tn1 = -dt;
      for(int k = 0; k < order+1; k++){
        x[k] = 0;
        y[k] = 0;        
      }
      setCoef();
    }

    void setCoef(){
      if(adapt){
        float t = micros()/1.0e6;
        dt = t - tn1;
        tn1 = t;
      }
      
      float alpha = omega0*dt;
      if(order==1){
        a[0] = -(alpha - 2.0)/(alpha+2.0);
        b[0] = alpha/(alpha+2.0);
        b[1] = alpha/(alpha+2.0);        
      }
      if(order==2){
        float alphaSq = alpha*alpha;
        float beta[] = {1, sqrt(2), 1};
        float D = alphaSq*beta[0] + 2*alpha*beta[1] + 4*beta[2];
        b[0] = alphaSq/D;
        b[1] = 2*b[0];
        b[2] = b[0];
        a[0] = -(2*alphaSq*beta[0] - 8*beta[2])/D;
        a[1] = -(beta[0]*alphaSq - 2*beta[1]*alpha + 4*beta[2])/D;      
      }
    }

    float filt(float xn){
      // Provide me with the current raw value: x
      // I will give you the current filtered value: y
      if(adapt){
        setCoef(); // Update coefficients if necessary      
      }
      y[0] = 0;
      x[0] = xn;
      // Compute the filtered values
      for(int k = 0; k < order; k++){
        y[0] += a[k]*y[k+1] + b[k]*x[k];
      }
      y[0] += b[order]*x[order];

      // Save the historical values
      for(int k = order; k > 0; k--){
        y[k] = y[k-1];
        x[k] = x[k-1];
      }
  
      // Return the filtered value    
      return y[0];
    }
};
//-----------------------Start-----------------------

//-----------------------Defines-----------------------
//Para control pwm
#define ENA 5
#define ENB 10

//Para control de dirección 
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9

float PWM_signal;

/*  
  IN1 IN2 Estado
  0   0   OFF
  1   0   DIR1
  0   1   DIR2
  1   1   FRENO ACTIVO (desaconsejado) 
*/

LowPass<1> lp(0.5,1e3,true);
LowPass<1> lp2(2,1e3,true);
LowPass<1> lp3(3,1e3,true);

void setup() {
  analogReference(INTERNAL);
  //-----------------------Pinmodes-----------------------
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  //-----------------------Coms-----------------------
  Serial.begin(9600);

  //-----------------------Test-----------------------
  analogWrite(ENB,0); //255 sobre 255
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
}

void loop() {
  float pos_actuator = lp3.filt(analogRead(A0))*-0.22+160;
  float pos_finger=lp2.filt(analogRead(A1)*-0.5625+371);
  float mA=lp.filt(analogRead(A2))*1.1/255*(1/1.6);
  
  float target = 0.8;

  float error = target-mA;
  PWM_signal+=1000*error;
  analogWrite(ENB,PWM_signal);
  Serial.print(target);
  Serial.print(" ");
  Serial.println(mA);
   
}
