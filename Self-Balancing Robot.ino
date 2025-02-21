#include <Wire.h>
#include <MPU6050.h>

// MPU6050 setup
MPU6050 mpu;

// Motor pins
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor2Pin1 = 9;
const int motor2Pin2 = 10;

// PID variables
float Kp = 2.5, Ki = 0.8, Kd = 1.2; // Tune these values for your robot
float setpoint = 0; // Desired angle (upright position)
float input, output;
float previousError = 0, integral = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize MPU6050
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    while (1);
  }

  // Set motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}

void loop() {
  // Read angle from MPU6050
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  float angle = atan2(ay, az) * 180 / PI; // Calculate tilt angle

  // PID control
  float error = setpoint - angle;
  integral += error;
  float derivative = error - previousError;
  output = Kp * error + Ki * integral + Kd * derivative;
  previousError = error;

  // Control motors based on PID output
  if (output > 0) {
    // Move forward
    analogWrite(motor1Pin1, output);
    analogWrite(motor1Pin2, 0);
    analogWrite(motor2Pin1, output);
    analogWrite(motor2Pin2, 0);
  } else {
    // Move backward
    analogWrite(motor1Pin1, 0);
    analogWrite(motor1Pin2, -output);
    analogWrite(motor2Pin1, 0);
    analogWrite(motor2Pin2, -output);
  }

  delay(10); // Adjust loop speed
}
