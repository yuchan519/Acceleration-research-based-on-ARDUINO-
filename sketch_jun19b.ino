#define NUM_MEASUREMENTS  20
#define PIN_INTERRUPT 2

int times[NUM_MEASUREMENTS];//
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_INTERRUPT,INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_INTERRUPT),interrupt,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tempTime;
  double tempTimesqure;
  if (i >= NUM_MEASUREMENTS){
      for(int j = 1; j < i ; j++){               
          tempTime = times[j] - times[j-1];                 
          Serial.print("The discontinuous time is:");
          Serial.print(tempTime);         
          Serial.println();
      } 
    }
}

void interrupt(){
  if(i < NUM_MEASUREMENTS){
      times[i] = millis();     
      i++;
    }
} 
