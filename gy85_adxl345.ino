#include <Wire.h>

#define ADXL345_ADDRESS 0x53 // ADXL345 I2C address

#define POWER_CTL 0x2D
#define DATA_FORMAT 0x31
#define DATAX0 0x32
#define DATAX1 0x33
#define DATAY0 0x34
#define DATAY1 0x35
#define DATAZ0 0x36
#define DATAZ1 0x37

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Wake up the ADXL345 sensor
  writeTo(POWER_CTL, 0x08);  // Put the sensor in measurement mode
  writeTo(DATA_FORMAT, 0x08); // Set to full resolution mode (±4g)

  // Verify the sensor's status
  byte value = readRegister(POWER_CTL);
  Serial.print("POWER_CTL register: ");
  Serial.println(value, HEX);

  if (value != 0x08) {
    Serial.println("Sensor not responding correctly or not initialized.");
  } else {
    Serial.println("Sensor initialized correctly.");
  }
}

void loop() {
  int x = readAxis(DATAX0, DATAX1);
  int y = readAxis(DATAY0, DATAY1);
  int z = readAxis(DATAZ0, DATAZ1);

  // Output the readings
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("\tY: ");
  Serial.print(y);
  Serial.print("\tZ: ");
  Serial.println(z);

  delay(500);  // Delay to make the readings readable
}

void writeTo(byte address, byte value) {
  Wire.beginTransmission(ADXL345_ADDRESS);
  Wire.write(address);
  Wire.write(value);
  Wire.endTransmission();
}

int readAxis(byte lowByte, byte highByte) {
  Wire.beginTransmission(ADXL345_ADDRESS);
  Wire.write(lowByte);
  Wire.endTransmission();

  Wire.requestFrom(ADXL345_ADDRESS, 2);

  int value = Wire.read();
  value |= Wire.read() << 8;

  return value;
}

byte readRegister(byte reg) {
  Wire.beginTransmission(ADXL345_ADDRESS);
  Wire.write(reg);
  Wire.endTransmission();

  Wire.requestFrom(ADXL345_ADDRESS, 1);
  return Wire.read();
}
