#include <ESP32Servo.h>

// Define servo pins for the hind legs
const int left_hind_knee_pin = 3;
const int right_hind_hip_pin = 4;
const int right_hind_knee_pin = 5;
const int left_hind_hip_pin = 6;

// Define servo pins for the front legs
const int front_left_knee_pin = 7;
const int front_right_hip_pin = 8;
const int front_right_knee_pin = 9;
const int front_left_hip_pin = 10;

// Create servo objects
Servo left_hind_knee, right_hind_hip, right_hind_knee, left_hind_hip;
Servo front_left_knee, front_right_hip, front_right_knee, front_left_hip;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Servo Control Initialized.");
  Serial.println("All servos moving to neutral position (90°).");

  // Attach and move all servos to neutral (90°)
  left_hind_knee.attach(left_hind_knee_pin);
  right_hind_hip.attach(right_hind_hip_pin);
  right_hind_knee.attach(right_hind_knee_pin);
  left_hind_hip.attach(left_hind_hip_pin);

  front_left_knee.attach(front_left_knee_pin);
  front_right_hip.attach(front_right_hip_pin);
  front_right_knee.attach(front_right_knee_pin);
  front_left_hip.attach(front_left_hip_pin);

  setAllServos(90); // Move all servos to neutral position
  delay(1000); // Wait for movement
  Serial.println("All servos in neutral position.");
}

void loop() {
  // Detect any button press (serial input)
  if (Serial.available() > 0) {
    Serial.readStringUntil('\n'); // Read and discard input

    Serial.println("Moving servos...");
    // Move right side (hind + front) to 110° and left side to 70°
    moveServos(110, 70);

    delay(1000);

    // Return all servos to neutral (90°)
    Serial.println("Returning servos to neutral...");
    setAllServos(90);

    delay(1000);
  }
}

// Function to set all servos to the same angle
void setAllServos(int angle) {
  left_hind_knee.write(angle);
  right_hind_hip.write(angle);
  right_hind_knee.write(angle);
  left_hind_hip.write(angle);

  front_left_knee.write(angle);
  front_right_hip.write(angle);
  front_right_knee.write(angle);
  front_left_hip.write(angle);
}

// Function to move servos to mirrored angles
void moveServos(int rightAngle, int leftAngle) {
  // Move right side servos to rightAngle
  right_hind_hip.write(rightAngle);
  right_hind_knee.write(rightAngle);
  front_right_hip.write(rightAngle);
  front_right_knee.write(rightAngle);

  // Move left side servos to leftAngle
  left_hind_knee.write(leftAngle);
  left_hind_hip.write(leftAngle);
  front_left_knee.write(leftAngle);
  front_left_hip.write(leftAngle);
}