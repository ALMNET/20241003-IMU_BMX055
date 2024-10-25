/* 
 * File:        API_ADLX345.h
 * Author:      Armando Almarales (ALMNET ELECTRONICS)
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef API_BMX055_H
#define	API_BMX055_H

#include <xc.h>         // include processor files - each processor file is guarded.  
#include <math.h>       // Allows to calculate resulting magnitude

//#include "API_I2C.h"    // I2C Bus Library for communication
// #include "../mssp1.h"

#include <string.h>
#include <stdio.h>

#include "mcc_generated_files/i2c_host/mssp1.h"

// BMX055 I2C addresses
#define ACCEL_ADDRESS       0x18
#define GYRO_ADDRESS        0x68
#define MAG_ADDRESS         0x12


#define START_REGISTER_ACCEL    0x02
#define START_REGISTER_GYRO     0x02
#define START_REGISTER_MAG      0x42



#define ADXL_LOW_THRESHOLD      30
#define ADXL_MED_THRESHOLD      100
#define ADXL_HIG_THRESHOLD      150


typedef enum
{
    ADXL_LOW,
    ADXL_MEDIUM,
    ADXL_HIGH
} ADXL_Level_t;

void BMX055_Write(uint8_t address, uint8_t reg, uint8_t data);
uint8_t BMX055_Read(uint8_t deviceAddress, uint8_t reg, int16_t * valueX, int16_t * valueY, int16_t * valueZ);
void BMX055_Init(void) ;


#endif	/* API_BMX055_H */

