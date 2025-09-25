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
#include Servo.h    Include servo library
Servo servoMotor;     
int trigPin = 2;    
int echoPin = 3;   
int servoPin = 9; 
long duration, distance;   
void setup() {       
    servoMotor.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servoMotor.write(10);          Close lid on power on
    delay(2000);
    servoMotor.detach();
} 
void measureDistance()
 {  
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(15);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration  2)  29.1;     Calculate distance
}
void loop() { 
    measureDistance();    Measure distance   
    if (distance  8) 
{
        servoMotor.attach(servoPin);
        delay(1);
        servoMotor.write(80);   Open the lid
        delay(4000);        Wait for 4 seconds
        servoMotor.write(170);     Close the lid
        delay(4000);
        servoMotor.detach();     Detach the servo
    }
        delay(50);   Delay between measurements
}

