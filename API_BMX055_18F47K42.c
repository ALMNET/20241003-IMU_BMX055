

#include "API_BMX055_18F47K42.h"

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif


void BMX055_Init(void) {
    
    /////////////////////// Accelerometer initialization ///////////////////////
    
    // PMU_Range register, ±2g range    
    BMX055_Write(BMX055_ACC_ADDRESS, 0x0F, 0x03);
            
    // PMU_BW register, Bandwidth 7.81 Hz    
    BMX055_Write(BMX055_ACC_ADDRESS, 0x10, 0x08);
    
    // PMU_LPW register, Normal mode, sleep duration 0.5ms
    BMX055_Write(BMX055_ACC_ADDRESS, 0x11, 0x00);
    
    ///////////////////////// Gyroscope initialization /////////////////////////
    
    // Range register, 125 °/s    
    BMX055_Write(BMX055_GYRO_ADDRESS, 0x0F, 0x04);
    
    // Bandwidth register, Bandwidth 32 Hz
    BMX055_Write(BMX055_GYRO_ADDRESS, 0x10, 0x07);
    
    // LPM1 register, Normal mode    
    BMX055_Write(BMX055_GYRO_ADDRESS, 0x11, 0x00);
    
    /////////////////////// Magnetometer initialization ////////////////////////
    
    // Power Control register, Soft reset
    BMX055_Write(BMX055_MAG_ADDRESS, 0x4B, 0x83);
    __delay_ms(50);
            
    // Power Control register, Set power to normal mode
    BMX055_Write(BMX055_MAG_ADDRESS, 0x4B, 0x01);
    __delay_ms(50);
    
    // Op Mode register, Continuous measurement mode
    BMX055_Write(BMX055_MAG_ADDRESS, 0x4C, 0x00);
    
    // Rep_XY register, X-Y repetitions
    BMX055_Write(BMX055_MAG_ADDRESS, 0x4E, 0x84);
    
    // dataWriteArray[0] = 0x51; // Rep_Z register, Z repetitions
    BMX055_Write(BMX055_MAG_ADDRESS, 0x51, 0x04);
    
    ////////////////////////////////////////////////////////////////////////////
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
        case BMX055_ACC_ADDRESS:
            
            *valueX = (dataReadArray[0] | (dataReadArray[1] << 8)) >> 4;
            *valueY = (dataReadArray[2] | (dataReadArray[3] << 8)) >> 4;
            *valueZ = (dataReadArray[4] | (dataReadArray[5] << 8)) >> 4;

            printf("Accel: %d, %d, %d | ", *valueX, *valueY, *valueZ);
    
            break;
            
        case BMX055_GYRO_ADDRESS:
            
            *valueX = dataReadArray[0] | (dataReadArray[1] << 8);
            *valueY = dataReadArray[2] | (dataReadArray[3] << 8);
            *valueZ = dataReadArray[4] | (dataReadArray[5] << 8);

            printf("Gyro: %d, %d, %d | ", *valueX, *valueY, *valueZ);
            break;
            
        case BMX055_MAG_ADDRESS:
            
            *valueX = (dataReadArray[0] | (dataReadArray[1] << 8));
            *valueY = (dataReadArray[2] | (dataReadArray[3] << 8));
            *valueZ = (dataReadArray[4] | (dataReadArray[5] << 8));

            printf("Mag: %d, %d, %d \n", *valueX, *valueY, *valueZ);
            break;
                                    
    }
    
    return 0;
}