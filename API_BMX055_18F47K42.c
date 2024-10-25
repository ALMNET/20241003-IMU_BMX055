

#include "API_BMX055_18F47K42.h"


void BMX055_Write(uint8_t reg, uint8_t data) {
//    I2C_Start();
//    I2C_Write(BMX055_ADDRESS << 1);
//    I2C_Write(reg);
//    I2C_Write(data);
//    I2C_Stop();
    
        
    uint8_t dataWriteArray[3];
    
    dataWriteArray[0] = reg;
    dataWriteArray[1] = data;
    dataWriteArray[2] = 0x55; // Dummy data
    
    while(!I2C1_Write(ACCEL_ADDRESS, dataWriteArray, 2));
}

uint8_t BMX055_Read(uint8_t reg) {
    
    uint8_t dataWriteArray[2];
    uint8_t dataReadArray[6];
    
    // char buffer[128];
    
    
    dataWriteArray[0] = reg;
    dataWriteArray[1] = 0x55; // Dummy datadata;
    
    
    
    while(!I2C1_WriteRead(ACCEL_ADDRESS, dataWriteArray, 1, dataReadArray, 6));
    
    printf("ax: %u ,", (dataReadArray[0] | dataReadArray[1] << 8));
    printf("ay: %u ,", (dataReadArray[2] | dataReadArray[3] << 8));
    printf("az: %u\n", (dataReadArray[4] | dataReadArray[5] << 8));
    
    
    
    // I2C1_Read(uint16_t address, &data , 1)

    return dataReadArray[0];
}

void BMX055_Init(void) {
    
    uint8_t dataWriteArray[3];
    // Accelerometer initialization
    
    dataWriteArray[0] = 0x0F; // PMU_BW register
    dataWriteArray[1] = 0x03; // Bandwidth 7.81 Hz
    dataWriteArray[2] = 0x55; // Dummy data
    I2C1_Write(ACCEL_ADDRESS, dataWriteArray, 2);
            
    dataWriteArray[0] = 0x10; // PMU_BW register
    dataWriteArray[1] = 0x08; // Bandwidth 7.81 Hz
    dataWriteArray[2] = 0x55; // Dummy data
    I2C1_Write(ACCEL_ADDRESS, dataWriteArray, 2);
    
    dataWriteArray[0] = 0x11; // PMU_BW register
    dataWriteArray[1] = 0x00; // Bandwidth 7.81 Hz
    dataWriteArray[2] = 0x55; // Dummy data
    I2C1_Write(ACCEL_ADDRESS, dataWriteArray, 2);
    
    
    // Gyroscope initialization
    
    dataWriteArray[0] = 0x0F; // Range register
    dataWriteArray[1] = 0x04; // 125 °/s
    dataWriteArray[2] = 0x55; // Dummy data
    I2C1_Write(GYRO_ADDRESS, dataWriteArray, 2);
            
    dataWriteArray[0] = 0x10; // Bandwidth register
    dataWriteArray[1] = 0x07; // Bandwidth 32 Hz
    dataWriteArray[2] = 0x55; // Dummy data
    I2C1_Write(GYRO_ADDRESS, dataWriteArray, 2);
    
    dataWriteArray[0] = 0x11; // LPM1 register
    dataWriteArray[1] = 0x00; // Normal mode
    dataWriteArray[2] = 0x55; // Dummy data
    I2C1_Write(GYRO_ADDRESS, dataWriteArray, 2);
    
    
    // Magnetometer initialization
    
    dataWriteArray[0] = 0x4B; // Power Control register
    dataWriteArray[1] = 0x83; // Soft reset
    dataWriteArray[2] = 0x55; // Dummy data
    I2C1_Write(MAG_ADDRESS, dataWriteArray, 2);
            
    dataWriteArray[0] = 0x4B; // Power Control register
    dataWriteArray[1] = 0x01; // Set power to normal mode
    dataWriteArray[2] = 0x55; // Dummy data
    I2C1_Write(MAG_ADDRESS, dataWriteArray, 2);
    
    dataWriteArray[0] = 0x4C; // Op Mode register
    dataWriteArray[1] = 0x00; // Continuous measurement mode
    dataWriteArray[2] = 0x55; // Dummy data
    I2C1_Write(MAG_ADDRESS, dataWriteArray, 2);
    
    dataWriteArray[0] = 0x4E; // Rep_XY register
    dataWriteArray[1] = 0x84; // X-Y repetitions
    dataWriteArray[2] = 0x55; // Dummy data
    I2C1_Write(MAG_ADDRESS, dataWriteArray, 2);
            
    
            
}
