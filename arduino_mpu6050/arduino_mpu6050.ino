#include <MPU6050_tockn.h>
#include <Wire.h>

#define BAUD 9600

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(BAUD);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();
  Serial.print(mpu6050.getAngleX());
  Serial.print(" ");
  Serial.print(mpu6050.getAngleY());
  Serial.print(" ");
  Serial.print(mpu6050.getAngleZ());
  Serial.print(" ");
  Serial.print("\n");

}
