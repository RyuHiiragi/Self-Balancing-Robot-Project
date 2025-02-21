# Self-Balancing Robot Project

This repository contains the Arduino code, configuration, and assembly instructions for building a self-balancing robot. A self-balancing robot is designed to maintain its balance on two wheels using a gyroscope and accelerometer for orientation sensing, along with control algorithms to stabilize itself. This project is ideal for hobbyists and engineers interested in robotics, control systems, and sensor integration.

---

## Table of Contents
1. [Overview](#overview)
2. [Components Used](#components-used)
3. [Robot Dimensions](#robot-dimensions)
4. [Assembly Instructions](#assembly-instructions)
5. [Arduino Code Explanation](#arduino-code-explanation)
6. [How to Simulate on Wokwi](#how-to-simulate-on-wokwi)
7. [Contributing](#contributing)
8. [License](#license)

---

## Overview
The self-balancing robot uses a combination of sensors and motor control to maintain its upright position. It relies on a gyroscope and accelerometer (typically combined in an IMU module) to measure the robot's tilt angle and angular velocity. A PID (Proportional-Integral-Derivative) control algorithm processes this data to adjust the motors' speed and direction, ensuring the robot remains balanced <button class="citation-flag" data-index="1">.

---

## Components Used
To build this self-balancing robot, you will need the following components:
- **Microcontroller**: Arduino Uno (or any compatible board like Arduino Nano or Mega).
- **Motor Driver**: L298N Motor Driver Module.
- **DC Motors**: 2 x High-Torque DC Motors with Wheels.
- **IMU Sensor**: MPU6050 Gyroscope and Accelerometer.
- **Power Supply**: 7.4V LiPo Battery (or equivalent).
- **Chassis**: Custom 3D-printed or laser-cut chassis, or a pre-made chassis kit.
- **Wheels**: 2 x Compatible Wheels for DC Motors.
- 

---

## Robot Dimensions
For an ideal self-balancing robot:
- **Height**: 20–25 cm
- **Width**: 10–15 cm
- **Length**: 10–15 cm

These dimensions ensure that the robot is stable while balancing and allows enough space for mounting all components.

---

## Assembly Instructions
Follow these steps to assemble your self-balancing robot:
*Prepare the Chassis*
If using a custom design, 3D print or laser-cut the parts.
Attach mounting points for the motors, Arduino, motor driver, and IMU sensor.
*Attach Motors*
Mount the two DC motors at the bottom of the chassis, ensuring they are aligned properly.
Attach the wheels to the motors.
*Mount the IMU Sensor*
Secure the MPU6050 sensor to the top of the chassis. Ensure it is level and centered to accurately measure the robot's tilt.
Connect the Motor Driver
Connect the DC motors to the L298N motor driver module.
Connect the motor driver's input pins to the Arduino's digital pins (e.g., D5, D6, D9, D10).
Connect the IMU Sensor
Connect the MPU6050 sensor to the Arduino using I2C communication:
VCC → 5V
GND → GND
SDA → A4
SCL → A5
*Power Connections*
Connect the battery to the motor driver's power input.
Connect the motor driver's 5V output to the Arduino's VIN pin to power the microcontroller.
*Final Assembly*
Double-check all connections to ensure proper wiring.
Secure all components to the chassis using screws or adhesive.

---

## Arduino Code Explanation
The provided Arduino code uses the MPU6050 sensor to measure the robot's tilt angle and applies a PID control algorithm to adjust the motors' speed and direction. The PID parameters (`Kp`, `Ki`, `Kd`) can be tuned to achieve optimal balance.

---

## How to Simulate on Wokwi
1. Go to [Wokwi](https://wokwi.com/).
2. Create a new project and select "Arduino Uno" as the board.
3. Add the MPU6050 sensor and two DC motors to the project.
4. Copy and paste the provided Arduino code into the editor.
5. Connect the components to the appropriate pins as defined in the code.
6. Run the simulation to see the self-balancing robot in action.

---

## Contributing
Feel free to fork this repository and contribute improvements or new features. If you have suggestions or find bugs, please open an issue.

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

By following this guide, you should be able to simulate and build your own self-balancing robot using Arduino and Wokwi. Happy tinkering! 🚀
