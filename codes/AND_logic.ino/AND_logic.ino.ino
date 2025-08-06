const int Vcc = 2;
const int inputPin1 = 4;
const int inputPin2 = 7;
const int Vout = 8;

int State = 0;

void setup() {
  pinMode(inputPin1, OUTPUT);
  pinMode(inputPin2, OUTPUT);
  pinMode(Vcc, INPUT_PULLUP);
  pinMode(Vout, INPUT);

  Serial.begin(1200);  // Capital 'S' in Serial – this is critical!
}

void loop() {
  digitalWrite(Vcc,HIGH);
  digitalWrite(inputPin1,LOW); 
  digitalWrite(inputPin2,LOW);
  State = digitalRead(Vout);
  if(State){
    Serial.println("H");
  }else{
    Serial.println("L");
    }

}
