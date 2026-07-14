# 🤖 Arduino Nano One-Motor Walker (Modified BEAM Bot)
This repository contains the code, circuit layout, and design documentation for our modified **One-Motor Walker**. 

An Arduino Nano (or any other microcontroller you seem familiar with) adaptation of the classic One-Motor Walker, a bot which walks with only one motor! This design is base on the principal of B.E.A.M robotics! Building simple and elegant robot inspired by insect.

Instead of freeforming the traditional analog 74HCT240/74AC240 BEAM bicore circuit, we re-engineered the robot's "brain" using an **Arduino Nano**. 

By switching to a microcontroller, we can precisely tune the robot's stride length and oscillation patterns directly in the code without physically swapping hardware components like resistors or capacitors.

---

## 🛠 Features & Engineering Modifications

- **Microcontroller Brain:** An Arduino Nano replaces the vintage analog IC chip for smarter, programmable control.
- **Time-Delay Gait Control:** Because a modified continuous servo lacks position feedback, the physical boundaries of the stride are managed using software `delay()` timings.
- **Mechanical Stress Reduction:** The code includes brief 100ms pauses (`write(90)`) between direction reversals. This minimizes current spikes and protects the plastic gears from harsh torque snaps (gear backlash).

---

## 📋 Components & Hardware List

- **Microcontroller:** Arduino Nano
- **Actuator:** 1 x Modified Continuous Rotation Servo
- **Gears:** 1 x 2-inch Plastic Gear (secured directly to the main servo shaft)
- **Chassis & Legs:** 8 to 14-gauge copper wire (or metal coat hangers)
- **Mechanical Pivots:** rigid plastic tubing 
- **Power Source:** External Battery Pack (4.8V – 6V DC)

---

## 🔌 Circuit & Wiring Layout

The circuit simplifies power routing by sharing a common ground and utilizing the Nano to feed the logic signal.

- **Servo Signal (Yellow/White)** ➡️ Arduino Nano **Pin D9**
- **Servo VCC (Red)** ➡️ Battery Positive (`+`) / Arduino `5V`
- **Servo GND (Black/Brown)** ➡️ Battery Negative (`-`) & Arduino **GND** *(Common Ground)*
- **Battery Pack Positive** ➡️ Arduino Nano **VIN**

---

## 💻 The Code (`one_motor_walker.ino`)

The loop relies on time constants to determine how far the legs swing before pivoting back. 

```cpp
#include <Servo.h>

Servo walkerServo;  // Create servo object

void setup() {
  walkerServo.attach(9);  // Attaches the servo on pin 9
}

void loop() {
  // Move forward/clockwise
  walkerServo.write(180); 
  delay(500);            // Adjust this time to change the left step length
  
  // Stop briefly to reduce mechanical stress
  walkerServo.write(90);  
  delay(100);
  
  // Move backward/counter-clockwise
  walkerServo.write(0);   
  delay(500);            // Adjust this time to match the first delay
  
  // Stop briefly
  walkerServo.write(90);  
  delay(100);
}
