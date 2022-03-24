
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;
int incomingByte = 0;
const int buzzer = 22;
void setup() 
{
  Serial.begin(115200);
  pinMode(buzzer,OUTPUT);
  // Initialize MPU6050
  //Serial.println("Initialize MPU6050");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  

  mpu.calibrateGyro();


  mpu.setThreshold(3);
  

}



void loop()
{
  Vector rawGyro = mpu.readRawGyro();
  Vector normGyro = mpu.readNormalizeGyro();

//Serial.print(" X = ");
  Serial.print(rawGyro.XAxis);
  Serial.print(" ");
  Serial.print(rawGyro.YAxis);
  Serial.print("\n");
//  Serial.print(" Zraw = ");
//  Serial.println(rawGyro.ZAxis);
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    
    if(incomingByte == 'E') {
      
      tone(buzzer, 500, 500);
    }
  }
  
  delay(100);
}
