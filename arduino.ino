const int motorEnablePin = 10; // PWM pin for motor speed control
const int motorInput1 = 8;     // Motor direction pin 1
const int motorInput2 = 7;     // Motor direction pin 2
const int parkingLightsPin = 13; // Pin for parking lights
const int buzzerPin = 12;        // Pin for buzzer

unsigned long lastSignalTime = 0; // Tracks the last time the signal 'A' was received
bool motorStopped = false;        // Tracks whether the motor is stopped

void setup() {
  pinMode(motorEnablePin, OUTPUT);
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(parkingLightsPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(parkingLightsPin, LOW);
  digitalWrite(buzzerPin, LOW);

  Serial.begin(9600);  // Start serial communication
  runMotorForward(255); // Start the motor at full speed by default
}

void loop() {
  // Check if a signal is available from the serial monitor
  if (Serial.available()) {
    char signal = Serial.read(); // Read the incoming signal

    if (signal == 'A') {
      // Stop the motor and activate parking lights and buzzer
      stopMotor();
      motorStopped = true; // Mark motor as stopped
      lastSignalTime = millis(); // Record the current time
      digitalWrite(parkingLightsPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      delay(350);
      digitalWrite(parkingLightsPin, LOW);
      digitalWrite(buzzerPin, LOW);
    }
    else if (signal == 'S') {
      motorStopped = false; // If 'S' is pressed, stop the motor and everything
      stopMotor(); // Call function to stop the motor
      digitalWrite(parkingLightsPin, LOW);
      digitalWrite(buzzerPin, LOW);
      while (true); // Halt Arduino execution
    }
  }

  // Check if the motor should restart
  if (motorStopped) {
    unsigned long currentTime = millis();
    if (currentTime - lastSignalTime >= 1100) { // 1000 ms after last 'A' signal
      motorStopped = false; // Reset the motor stopped flag
      runMotorForward(255); // Restart the motor
    }
  } else {
    // Ensure the motor keeps running unless explicitly stopped
    runMotorForward(255);
  }
}

// Function to run the motor forward at a specified speed
void runMotorForward(int speed) {
  digitalWrite(motorInput1, HIGH); // Set motor direction
  digitalWrite(motorInput2, LOW);  // Set motor direction
  analogWrite(motorEnablePin, speed); // Control motor speed using PWM
}

// Function to stop the motor completely
void stopMotor() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  analogWrite(motorEnablePin, 0); // Ensure speed is 0 (motor stops)
}
