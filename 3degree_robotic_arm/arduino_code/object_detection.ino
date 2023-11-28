#include <Servo.h>
// Define the pin for the IR sensor

const int irSensorPin = 2;  // Change this to the pin your sensor is connected to
Servo servo_3;

Servo servo_5;

Servo servo_base;

Servo servo_hook;
void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(irSensorPin, INPUT);  // Set the IR sensor pin as input
  servo_3.attach(10, 500, 2500);
  servo_5.attach(5, 500, 2500);
  servo_base.attach(6, 500, 2500);
  servo_hook.attach(9, 500, 2500);

  servo_3.write(90);
  // servo_5.write(90);
  servo_base.write(0);
  servo_hook.write(90);
}

void loop() {
  // Read the digital signal from the IR sensor
  int objectDetected = digitalRead(irSensorPin);

  // Check if an object is detected
  if (objectDetected == LOW) {
    Serial.println("Object detected!");
    servo_base.write(180);
    delay(100);
    // servo_5.write(0);
    delay(1000);
    servo_3.write(160);
    delay(1000); 
    servo_hook.write(0);
    delay(1000);
    servo_base.write(180);
    delay(100); // Wait for 1000 millisecond(s)

  } else {
    Serial.println("No object detected.");
    delay(500);
    servo_hook.write(90);
    delay(100);
    
    servo_3.write(90);
    delay(1000);
    
    servo_5.write(90);
    delay(100);
    servo_base.write(0);

  }

  delay(1000);  // Delay for a second to avoid rapid serial prints
}
