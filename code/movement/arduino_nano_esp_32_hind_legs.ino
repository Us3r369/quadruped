#include <ESP32Servo.h>

// Give meaningful names to the pins
const int left_hind_knee_pin = 3;  // Left hind knee
const int right_hind_hip_pin = 4;  // Right hind hip
const int right_hind_knee_pin = 5; // Right hind knee
const int left_hind_hip_pin = 6;   // Left hind hip

// Create servo objects with matching names
Servo left_hind_knee;
Servo right_hind_hip;
Servo right_hind_knee;
Servo left_hind_hip;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Servo Control Initialized.");
  Serial.println("All servos moving to neutral position (90°).");

  // Attach and move all to neutral (90°)
  left_hind_knee.attach(left_hind_knee_pin);
  right_hind_hip.attach(right_hind_hip_pin);
  right_hind_knee.attach(right_hind_knee_pin);
  left_hind_hip.attach(left_hind_hip_pin);

  left_hind_knee.write(90);
  right_hind_hip.write(90);
  right_hind_knee.write(90);
  left_hind_hip.write(90);

  delay(1000); // Wait for the servos to reach position
  Serial.println("All servos in neutral position (90°).");
}

void loop() {
  // If ANY serial data is available, treat it as a "button press"
  if (Serial.available() > 0) {
    // Read and discard the incoming string; we only need to detect the press
    Serial.readStringUntil('\n');

    // Move right side servos from 90° to 110° (+20°)
    right_hind_hip.write(110);
    right_hind_knee.write(110);

    // Move left side servos from 90° to 70° (-20°)
    left_hind_knee.write(70);
    left_hind_hip.write(70);

    delay(1000);

    // Now move them all back to 90° (neutral)
    right_hind_hip.write(90);
    right_hind_knee.write(90);
    left_hind_knee.write(90);
    left_hind_hip.write(90);

    delay(1000);
    Serial.println("Servos returned to 90° (neutral).");
  }
}