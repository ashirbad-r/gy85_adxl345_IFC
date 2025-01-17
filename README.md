﻿# gy85_adxl345_IFC
ADXL345 I2C Accelerometer Interface
This project demonstrates how to interface the ADXL345 3-axis accelerometer sensor with an Arduino board using I2C communication. The sensor reads the acceleration data on the X, Y, and Z axes, and displays the readings via the Serial Monitor.

Components Required
Arduino (any model supporting I2C communication)
ADXL345 3-axis Accelerometer
Jumper wires for connecting the ADXL345 to the Arduino
Breadboard (optional)
Wiring
ADXL345 to Arduino (I2C)
VCC -> 3.3V or 5V (depending on your Arduino model)
GND -> GND
SDA -> A4 (on Arduino UNO)
SCL -> A5 (on Arduino UNO)
Code Explanation
The code initializes the ADXL345 sensor, configures it for full resolution mode, and then reads the acceleration values on the X, Y, and Z axes. These values are printed to the Serial Monitor.

Key Functions:
setup():

Initializes the Serial communication and I2C communication.
Configures the ADXL345 sensor by sending the appropriate values to its POWER_CTL and DATA_FORMAT registers.
Verifies the sensor's status by reading the POWER_CTL register.
loop():

Reads acceleration values from the X, Y, and Z axes continuously in a loop.
Outputs these values to the Serial Monitor.
writeTo(byte address, byte value):

A helper function to write a value to a specified register on the ADXL345.
readAxis(byte lowByte, byte highByte):

A helper function to read the 2-byte axis data (16-bit) from the ADXL345 sensor and combine them into a single integer value.
readRegister(byte reg):

A helper function to read a single byte from a specified register on the ADXL345.
ADXL345 Registers Used:
POWER_CTL (0x2D): Controls the power modes of the sensor (used to set measurement mode).
DATA_FORMAT (0x31): Configures the data format, in this case, setting it to full resolution mode (±4g).
DATAX0 (0x32), DATAX1 (0x33): Reads the X-axis acceleration data.
DATAY0 (0x34), DATAY1 (0x35): Reads the Y-axis acceleration data.
DATAZ0 (0x36), DATAZ1 (0x37): Reads the Z-axis acceleration data.
Sensor Initialization
Upon startup, the sensor is configured to:

Wake up from sleep mode and enter measurement mode.
Set the data format to full resolution with a ±4g range.
The sensor status is verified by reading the POWER_CTL register, and the result is displayed on the Serial Monitor.
If the sensor is not responding correctly, the program will print an error message, otherwise, it will confirm that the sensor is initialized successfully.

Output
The Serial Monitor will display the acceleration data from the X, Y, and Z axes at intervals of 500 milliseconds. The output format will be:


X: <value>    Y: <value>    Z: <value>

The values are in units of g (gravitational force), scaled based on the sensor's configuration.

Example output:

X: 123    Y: -56    Z: 890
X: 121    Y: -60    Z: 895

Troubleshooting
Sensor Not Responding: Ensure that the sensor is connected properly and the I2C communication is set up correctly.
Incorrect Readings: Double-check that the correct address (0x53) is used for the ADXL345 sensor.
Serial Monitor Output: Make sure to set the correct baud rate (9600) in your Arduino IDE's Serial Monitor.
Conclusion
This code provides a simple interface to read acceleration data from the ADXL345 3-axis accelerometer over I2C. You can modify this code to perform additional tasks like motion detection or data logging depending on your project needs.

To Upload the Code to Your Arduino:
Open the Arduino IDE.
Select the appropriate board and port.
Copy and paste the code into the Arduino IDE.
Click on Upload to upload the code to your Arduino.
Open the Serial Monitor to view the acceleration data.
Let me know if you need further assistance with the README or code!
