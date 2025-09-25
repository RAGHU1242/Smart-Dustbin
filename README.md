# 🗑️ Smart Dustbin

This project creates a **hands-free smart dustbin** using Arduino.  
It uses an **ultrasonic sensor** to detect motion and a **servo motor** to automatically open and close the lid, making waste disposal **hygienic and convenient**.  
Perfect for **beginners in Arduino and electronics**!

---

## ⚙️ How It Works

- The **ultrasonic sensor** acts as the "eyes" of the dustbin.  
- When it detects an object within **15–20 cm**, it signals the **Arduino Uno**.  
- The **Arduino** controls the **servo motor** to rotate and open the lid.  
- After a short delay, the lid closes automatically.

---

## 📦 Components

- **Arduino Uno** – The brain of the project  
- **HC-SR04 Ultrasonic Sensor** – Measures distance using sound waves  
- **SG90 Servo Motor** – Opens and closes the lid  
- **Jumper Wires** – For connections  
- **Power Source** – USB or battery pack  
- **Dustbin** – With hinged lid  
- **Cardboard/Plastic** – To mount components  

---

## 💻 Arduino Code

```cpp
#include <Servo.h>

// Define sensor pins
#define ECHO_PIN 9
#define TRIG_PIN 10

// Define servo pin
#define SERVO_PIN 6

// Create servo object
Servo myservo;

// Variables
long duration;
int distance;

void setup() {
  // Set up sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Attach servo to pin and set to initial position (closed)
  myservo.attach(SERVO_PIN);
  myservo.write(0); // Closed position

  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send a 10µs pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo time
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert to distance (cm)
  distance = duration * 0.034 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If object is within 20cm → open lid
  if (distance <= 20) {
    myservo.write(90);  // Open lid
    delay(2000);        // Stay open for 2s
    myservo.write(0);   // Close lid
  }
}
