Here’s a clean, self-contained write-up of your test, matching the structure you showed.

Diagram (rewritten for clarity):

less
Copy
Edit
[Btn1]              (buttons is normally open; it blocks +5 V)
  |         
 [10 kΩ]               
  |-------         
 [C_inp]   | 
         [Z-oscilloscope]
           |
          [gnd]

The buttons is fed from a GPIO that you drive HIGH (named Vcc in this sketch, actually pin 4).


What the Arduino sketch does is simply:

const int Vcc  = 4;  // drives the buttons (acts as +5 V source)
const int Vout = 8;  // reads the diode-OR output

void setup() {
  pinMode(Vcc, OUTPUT);
  pinMode(Vout, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(Vcc, HIGH);     // source the buttons from pin 4
  int State = digitalRead(Vout);
  Serial.println(State ? "H" : "L");
}

Pin 4 is continuously driven HIGH to source the buttons.

Pin 8 is a high-impedance (a capacitor only) input that senses V_out and prints H/L.

🧠 Logic behavior

No button pressed → the 10 kΩ pull-down holds V_out = LOW → the sketch prints L.

Button pressed: the corresponding diode becomes forward-biased and sources current into V_out → V_out = HIGH → the sketch prints H.

The equation governing the charging of the capacitor is reported in the other document hand written, see images-> Arduino Input Pin capacitance estimation.