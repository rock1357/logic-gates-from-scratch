const int inputPin1 = 4; //IN1
const int inputPin2 = 7; //IN2
const int Vout = 8; //Output pin

int State = 0;

void setup() {
  pinMode(inputPin1, OUTPUT); 
  pinMode(inputPin2, OUTPUT);
  pinMode(Vout, INPUT);

  Serial.begin(9600); 
}

void loop() {
  digitalWrite(inputPin1,HIGH); 
  digitalWrite(inputPin2,HIGH);
  State = digitalRead(Vout);
  if(State){
    Serial.println("H");
  }else{
    Serial.println("L");
    }

}
