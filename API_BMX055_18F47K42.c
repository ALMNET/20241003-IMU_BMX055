

#include "API_BMX055_18F47K42.h"

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif


void BMX055_Init(void) {
    
    // Accelerometer initialization
    
//    dataWriteArray[0] = 0x0F; // PMU_Range register
//    dataWriteArray[1] = 0x03; // ±2g range
//    dataWriteArray[2] = 0x11; // Dummy data
//    while(!I2C1_Write(ACCEL_ADDRESS, dataWriteArray, 2));
    
    BMX055_Write(ACCEL_ADDRESS, 0x0F, 0x03);
            
//    dataWriteArray[0] = 0x10; // PMU_BW register
//    dataWriteArray[1] = 0x08; // Bandwidth 7.81 Hz
//    dataWriteArray[2] = 0x22; // Dummy data
//    while(!I2C1_Write(ACCEL_ADDRESS, dataWriteArray, 2));
    
    BMX055_Write(ACCEL_ADDRESS, 0x10, 0x08);
    
//    dataWriteArray[0] = 0x11; // PMU_BW register
//    dataWriteArray[1] = 0x00; // Bandwidth 7.81 Hz
//    dataWriteArray[2] = 0x33; // Dummy data
//    while(!I2C1_Write(ACCEL_ADDRESS, dataWriteArray, 2));
    
    BMX055_Write(ACCEL_ADDRESS, 0x11, 0x00);
    
    
    // Gyroscope initialization
    
//    dataWriteArray[0] = 0x0F; // Range register
//    dataWriteArray[1] = 0x04; // 125 °/s
//    dataWriteArray[2] = 0x44; // Dummy data
//    while(!I2C1_Write(GYRO_ADDRESS, dataWriteArray, 2));
    
    
    BMX055_Write(GYRO_ADDRESS, 0x0F, 0x04);
//            
//    dataWriteArray[0] = 0x10; // Bandwidth register
//    dataWriteArray[1] = 0x07; // Bandwidth 32 Hz
//    dataWriteArray[2] = 0x55; // Dummy data
//    while(!I2C1_Write(GYRO_ADDRESS, dataWriteArray, 2));
    
    BMX055_Write(GYRO_ADDRESS, 0x10, 0x07);
//    
//    dataWriteArray[0] = 0x11; // LPM1 register
//    dataWriteArray[1] = 0x00; // Normal mode
//    dataWriteArray[2] = 0x66; // Dummy data
//    while(!I2C1_Write(GYRO_ADDRESS, dataWriteArray, 2));
    
    BMX055_Write(GYRO_ADDRESS, 0x11, 0x00);
//    
//    
//    // Magnetometer initialization
//    
//    dataWriteArray[0] = 0x4B; // Power Control register
//    dataWriteArray[1] = 0x83; // Soft reset
//    dataWriteArray[2] = 0x77; // Dummy data
//    while(!I2C1_Write(MAG_ADDRESS, dataWriteArray, 2));
//    __delay_ms(50);
    
    BMX055_Write(MAG_ADDRESS, 0x4B, 0x83);
    __delay_ms(50);
//            
//    dataWriteArray[0] = 0x4B; // Power Control register
//    dataWriteArray[1] = 0x01; // Set power to normal mode
//    dataWriteArray[2] = 0x88; // Dummy data
//    while(!I2C1_Write(MAG_ADDRESS, dataWriteArray, 2));
//    __delay_ms(50);
    
    BMX055_Write(MAG_ADDRESS, 0x4B, 0x01);
    __delay_ms(50);
//    
//    dataWriteArray[0] = 0x4C; // Op Mode register
//    dataWriteArray[1] = 0x00; // Continuous measurement mode
//    dataWriteArray[2] = 0x99; // Dummy data
//    while(!I2C1_Write(MAG_ADDRESS, dataWriteArray, 2));
    
    BMX055_Write(MAG_ADDRESS, 0x4C, 0x00);
//    
//    dataWriteArray[0] = 0x4E; // Rep_XY register
//    dataWriteArray[1] = 0x84; // X-Y repetitions
//    dataWriteArray[2] = 0xAA; // Dummy data
//    while(!I2C1_Write(MAG_ADDRESS, dataWriteArray, 2));
    
    BMX055_Write(MAG_ADDRESS, 0x4E, 0x84);
//    
//    dataWriteArray[0] = 0x51; // Rep_Z register
//    dataWriteArray[1] = 0x04; // Z repetitions
//    dataWriteArray[2] = 0xBB; // Dummy data
//    while(!I2C1_Write(MAG_ADDRESS, dataWriteArray, 2));
    
    BMX055_Write(MAG_ADDRESS, 0x51, 0x04);
    
            
}



void BMX055_Write(uint8_t address, uint8_t reg, uint8_t data) {
        
    uint8_t dataWriteArray[2];
    
    dataWriteArray[0] = reg;
    dataWriteArray[1] = data;
    
    while(!I2C1_Write(address, dataWriteArray, 2));
    
    __delay_ms(1);
}

uint8_t BMX055_Read(uint8_t deviceAddress, uint8_t reg, int16_t * valueX, int16_t * valueY, int16_t * valueZ) {
    
    uint8_t dataWriteArray[2];
    uint8_t dataReadArray[6];
    
    dataWriteArray[0] = reg;
    dataWriteArray[1] = 0x55; // Dummy datadata;
    
    while(!I2C1_WriteRead(deviceAddress, dataWriteArray, 1, dataReadArray, 6));
    
    __delay_ms(1);
    
    
    
    switch(deviceAddress)
    {
        case ACCEL_ADDRESS:
            
            *valueX = (dataReadArray[0] | (dataReadArray[1] << 8)) >> 4;
            *valueY = (dataReadArray[2] | (dataReadArray[3] << 8)) >> 4;
            *valueZ = (dataReadArray[4] | (dataReadArray[5] << 8)) >> 4;

            printf("Accel: %d, %d, %d | ", *valueX, *valueY, *valueZ);
    
            break;
            
        case GYRO_ADDRESS:
            
            *valueX = dataReadArray[0] | (dataReadArray[1] << 8);
            *valueY = dataReadArray[2] | (dataReadArray[3] << 8);
            *valueZ = dataReadArray[4] | (dataReadArray[5] << 8);

            printf("Gyro: %d, %d, %d | ", *valueX, *valueY, *valueZ);
            break;
            
        case MAG_ADDRESS:
            
            *valueX = (dataReadArray[0] | (dataReadArray[1] << 8));
            *valueY = (dataReadArray[2] | (dataReadArray[3] << 8));
            *valueZ = (dataReadArray[4] | (dataReadArray[5] << 8));

            printf("Mag: %d, %d, %d \n", *valueX, *valueY, *valueZ);
            break;
            
                        
    }
    
    
    
//    printf("WriteRead Result -> ax: %u ,", (dataReadArray[0] | (dataReadArray[1] << 8)));
//    printf("ay: %u ,", (dataReadArray[2] | (dataReadArray[3] << 8)));
//    printf("az: %u\n", (dataReadArray[4] | (dataReadArray[5] << 8)));
    
    return 0;
}