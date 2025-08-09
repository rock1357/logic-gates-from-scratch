const int Vcc = 4; //IN2
const int Vout = 8; //Output pin

int State = 0;

void setup() {
  pinMode(Vcc, OUTPUT); 
  pinMode(Vout, INPUT);

  Serial.begin(9600); 
}

void loop() {
  digitalWrite(Vcc,HIGH); 

  State = digitalRead(Vout);
  if(State){
    Serial.println("H");
  }else{
    Serial.println("L");
    }

}
