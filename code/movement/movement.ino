#include <Servo.h>
// Servos have to be calibrated before assembly to ensure correct physical mounting
// Servo Pins (all PWM-capable)
const int LEFT_HIND_HIP_PIN = 2;  // Pin for the left hind hip servo
const int LEFT_HIND_KNEE_PIN = 3; // Pin for the left hind knee servo
const int RIGHT_HIND_HIP_PIN = 4; // Pin for the right hind hip servo
const int RIGHT_HIND_KNEE_PIN = 5; // Pin for the right hind knee servo

// Movement Ranges
const int HIP_MIN_ANGLE = 0;   // Right hind hip minimum angle
const int HIP_MAX_ANGLE = 65;  // Right hind hip maximum angle
const int KNEE_MIN_ANGLE = 0;  // Right hind knee minimum angle
const int KNEE_MAX_ANGLE = 90; // Right hind knee maximum angle

Servo rightHindHip;  // Servo object for right hind hip
Servo rightHindKnee; // Servo object for right hind knee
Servo leftHindHip;   // Servo object for left hind hip
Servo leftHindKnee;  // Servo object for left hind knee

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Quadruped Servo Control Initialized.");

  // Attach servos
  rightHindHip.attach(RIGHT_HIND_HIP_PIN);
  rightHindKnee.attach(RIGHT_HIND_KNEE_PIN);
  leftHindHip.attach(LEFT_HIND_HIP_PIN);
  leftHindKnee.attach(LEFT_HIND_KNEE_PIN);

  // Set initial positions
  rightHindHip.write(HIP_MIN_ANGLE);
  rightHindKnee.write(KNEE_MIN_ANGLE);
  leftHindHip.write(HIP_MAX_ANGLE);  // Reverse initial position for left hip
  leftHindKnee.write(KNEE_MAX_ANGLE); // Reverse initial position for left knee

  Serial.println("Servos initialized at starting positions.");
}

void loop() {
  Serial.println("Waiting for user input to move servos...");
  while (Serial.available() == 0) {} // Wait for user input

  while (Serial.available() > 0) {
    Serial.read(); // Clear the input buffer
  }

  Serial.println("Moving servos to maximum angles...");
  rightHindHip.write(HIP_MAX_ANGLE);
  rightHindKnee.write(KNEE_MAX_ANGLE);
  leftHindHip.write(HIP_MIN_ANGLE);  // Reverse movement for left hip
  leftHindKnee.write(KNEE_MIN_ANGLE); // Reverse movement for left knee
  delay(1000); // Wait for the servos to reach their positions

  Serial.println("Moving servos back to minimum angles...");
  rightHindHip.write(HIP_MIN_ANGLE);
  rightHindKnee.write(KNEE_MIN_ANGLE);
  leftHindHip.write(HIP_MAX_ANGLE);  // Reverse movement for left hip
  leftHindKnee.write(KNEE_MAX_ANGLE); // Reverse movement for left knee
  delay(1000); // Wait for the servos to reach their positions
}
