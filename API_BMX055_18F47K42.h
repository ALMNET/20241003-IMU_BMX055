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


const int BMX055_ADDRESS = (0x53);

//unsigned char _buff[6];
//char POWER_CTL = 0x2D;
//char DATA_FORMAT = 0x31;
//char DATAX0 = 0x32;   //X-Axis_0
//char DATAX1 = 0x33;   //X-Axis_1
//char DATAY0 = 0x34;   //Y-Axis_0
//char DATAY1 = 0x35;   //Y-Axis_1
//char DATAZ0 = 0x36;   //Z-Axis_0
//char DATAZ1 = 0x37;   //Z-Axis_1

// Define BMX055 registers
#define BMX055_DEVID        0x00
#define BMX055_POWER_CTL    0x2D
#define BMX055_DATAX0       0x32
#define BMX055_DATAX1       0x33
#define BMX055_DATAY0       0x34
#define BMX055_DATAY1       0x35
#define BMX055_DATAZ0       0x36
#define BMX055_DATAZ1       0x37
#define BMX055_DATA_FORMAT  0x31
#define BMX055_BW_RATE      0x2C

typedef enum
{
    ADXL_LOW,
    ADXL_MEDIUM,
    ADXL_HIGH
} ADXL_Level_t;

void BMX055_Write(uint8_t reg, uint8_t data);
uint8_t BMX055_Read(uint8_t reg);
void BMX055_ReadMultiple(uint8_t reg, uint8_t* buffer, uint8_t len);
void BMX055_ReadAccel(int16_t* x, int16_t* y, int16_t* z);
float resultMagnitude(int16_t x, int16_t y, int16_t z);
void BMX055_Init(void) ;


#endif	/* API_BMX055_H */

