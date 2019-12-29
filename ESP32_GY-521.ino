#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

#define XACC_OFFSET -3456
#define YACC_OFFSET 2838
#define ZACC_OFFSET 829
#define XGYRO_OFFSET 9
#define YGYRO_OFFSET 43
#define ZGYRO_OFFSET -24

MPU6050 accelgyro;
int16_t XAccel, YAccel, ZAccel, XGyro, YGyro, ZGyro;

void setoffset(MPU6050 mpu, int XAccel_offset, int YAccel_offset, int ZAccel_offset, int XGyro_offset, int YGyro_offset, int ZGyro_offset){
  mpu.setXAccelOffset(XAccel_offset);
  mpu.setYAccelOffset(YAccel_offset);
  mpu.setZAccelOffset(ZAccel_offset);
  mpu.setXGyroOffset(XGyro_offset);
  mpu.setYGyroOffset(YGyro_offset);
  mpu.setZGyroOffset(ZGyro_offset);
}

void setup() {
  int XAccel_offset, YAccel_offset, ZAccel_offset, XGyro_offset, YGyro_offset, ZGyro_offset;

  Serial.begin(115200);
  Wire.begin();
  
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  setoffset(accelgyro, XACC_OFFSET, YACC_OFFSET, ZACC_OFFSET, XGYRO_OFFSET, YGYRO_OFFSET, ZGYRO_OFFSET);
}

void loop() {
  accelgyro.getMotion6(&XAccel, &YAccel, &ZAccel, &XGyro, &YGyro, &ZGyro);

  Serial.print("a/g:\t");
  Serial.print(XAccel); Serial.print("\t");
  Serial.print(YAccel); Serial.print("\t");
  Serial.print(ZAccel); Serial.print("\t");
  Serial.print(XGyro); Serial.print("\t");
  Serial.print(YGyro); Serial.print("\t");
  Serial.println(ZGyro);
}
