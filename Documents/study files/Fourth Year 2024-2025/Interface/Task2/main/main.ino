#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  // Print initialization message to Serial Monitor
  Serial.println("MPU6050 initialized. Starting measurements...");
}

void loop() {
  mpu6050.update();

  // Print angle data to Serial Monitor
  Serial.print("angleX: ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY: ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ: ");
  Serial.println(mpu6050.getAngleZ());

  delay(100);
}
