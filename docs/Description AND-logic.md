Diagram (rewritten for clarity):
     5V
      |
    [10kΩ] Pull-up
      |
      +-------+--------> V_out
      |       |
     [>]     [>]       (diodes: anodes to 5V, cathodes to buttons)
      |       |
     [Btn1]    [Btn2]
      |         |
    [GND/Vin1] [GND/Vin2]




- The **buttons are normally open** and connected to **GND**.
- The **diodes’ cathodes** are connected to the buttons.
- When a button is **pressed**, it pulls the corresponding diode’s cathode to **GND**, allowing current to flow → **V_out is pulled LOW**.

---

### 🧠 Logic Behavior

- When **both buttons are not pressed** → no current flows through the diodes (they're reverse biased) → the **pull-up resistor pulls `V_out` HIGH**.
- If **either button is pressed**, it conducts current through the corresponding diode → **`V_out` drops to LOW**.

🔎 This behaves like a **diode AND gate**, but in **active-low logic**:

- Only when **both buttons are not pressed**, `V_out` is HIGH.
- Pressing **either button** forces `V_out` LOW.

---

### 🧪 Truth Table

| Button1      | Button2      | V_out | Logic Interpretation        |
|--------------|--------------|-------|-----------------------------|
| Not pressed  | Not pressed  | HIGH  | 1 AND 1 → 1                 |
| Pressed      | Not pressed  | LOW   | 0 AND 1 → 0                 |
| Not pressed  | Pressed      | LOW   | 1 AND 0 → 0                 |
| Pressed      | Pressed      | LOW   | 0 AND 0 → 0                 |

---

✔️ This is equivalent to an **AND gate with active-low inputs** (i.e., logic `1` = not pressed, logic `0` = pressed).  
