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

