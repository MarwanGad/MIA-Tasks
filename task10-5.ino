#include <Wire.h>

int MPU_ADD = 0x68;  // MPU6050 I2C default address

// Variables to store gyroscope data
int16_t gyro=0;
unsigned long LTime=0;
// Variable to store yaw angle
float yaw = 0.0;

void setup() {
  Wire.begin();  // Start I2C communication
  Serial.begin(9600);
  init();  // Initialize MPU6050
  LTime = millis();  // Initialize time
}

// Function to initialize MPU6050
void init();

// Function to read the raw gyroscope data
int16_t readGyroZ();

// Function to calculate yaw from gyroscope data
void calculateyaw();

void loop() {
  calculateyaw(); 
  Serial.print("Yaw: ");
  Serial.println(yaw);

}


void init() {
  Wire.beginTransmission(MPU_ADD);
  Wire.write(0x6B);  // Access the register
  Wire.write(0);  // Set to 0 TO START 
  Wire.endTransmission();
}

int16_t readGyroZ() {
  Wire.beginTransmission(MPU_ADD);
  Wire.write(0x47);  // Start with the GYRO_ZOUT_H register address
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADD, 2, true);

  int16_t rawGyroZ = Wire.read() << 8 | Wire.read();  
  return rawGyroZ;
}

void calculateyaw() {
  // Calculate the time difference
  unsigned long currentTime = millis();
  float timeDIFF = (currentTime - LTime) / 1000;  // Convert to seconds
  Ltime = currentTime;

  gyroZ = readGyroZ();

  // Convert raw gyro data to degrees/second
  float gyroZ_dps = gyro / 131.0;  

  yaw = gyroZ_dps * timeDIFF;
}