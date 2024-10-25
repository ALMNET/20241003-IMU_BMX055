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


#include <string.h>
#include <stdio.h>

// I2C Library for PIC18F47K40/42
#include "mcc_generated_files/i2c_host/mssp1.h"

#define START_REGISTER_ACCEL        0x02
#define START_REGISTER_GYRO         0x02
#define START_REGISTER_MAG          0x42

//////////////////////////// Accelerometer Registers ///////////////////////////

// BMX055 Accelerometer I2C address
#define BMX055_ACC_ADDRESS          0x18

// Accelerometer Register Addresses
#define BMX055_ACC_WHO_AM_I         0x00
#define BMX055_ACC_D_X_LSB          0x02
#define BMX055_ACC_D_X_MSB          0x03
#define BMX055_ACC_D_Y_LSB          0x04
#define BMX055_ACC_D_Y_MSB          0x05
#define BMX055_ACC_D_Z_LSB          0x06
#define BMX055_ACC_D_Z_MSB          0x07
#define BMX055_ACC_TEMP             0x08
#define BMX055_ACC_INT_STATUS_0     0x09
#define BMX055_ACC_INT_STATUS_1     0x0A
#define BMX055_ACC_INT_STATUS_2     0x0B
#define BMX055_ACC_INT_STATUS_3     0x0C
#define BMX055_ACC_FIFO_STATUS      0x0E
#define BMX055_ACC_PMU_RANGE        0x0F
#define BMX055_ACC_PMU_BW           0x10
#define BMX055_ACC_PMU_LPW          0x11
#define BMX055_ACC_PMU_LOW_POWER    0x12
#define BMX055_ACC_DATA_CTRL        0x13
#define BMX055_ACC_SOFTRESET        0x14
#define BMX055_ACC_INT_ENABLE_0     0x16
#define BMX055_ACC_INT_ENABLE_1     0x17
#define BMX055_ACC_INT_ENABLE_2     0x18
#define BMX055_ACC_INT_MAP_0        0x19
#define BMX055_ACC_INT_MAP_1        0x1A
#define BMX055_ACC_INT_MAP_2        0x1B
#define BMX055_ACC_INT_SRC          0x1E
#define BMX055_ACC_INT_OUT_CTRL     0x20
#define BMX055_ACC_INT_RST_LATCH    0x21
#define BMX055_ACC_INT_0            0x22
#define BMX055_ACC_INT_1            0x23
#define BMX055_ACC_INT_2            0x24
#define BMX055_ACC_INT_3            0x25
#define BMX055_ACC_INT_4            0x26
#define BMX055_ACC_INT_5            0x27
#define BMX055_ACC_INT_6            0x28
#define BMX055_ACC_INT_7            0x29
#define BMX055_ACC_INT_8            0x2A
#define BMX055_ACC_INT_9            0x2B
#define BMX055_ACC_INT_A            0x2C
#define BMX055_ACC_INT_B            0x2D
#define BMX055_ACC_INT_C            0x2E
#define BMX055_ACC_INT_D            0x2F
#define BMX055_ACC_FIFO_CONFIG_0    0x30
#define BMX055_ACC_PMU_SELF_TEST    0x32
#define BMX055_ACC_TRIM_NVM_CTRL    0x33
#define BMX055_ACC_BGW_SPI3_WDT     0x34
#define BMX055_ACC_OFC_CTRL         0x36
#define BMX055_ACC_OFC_SETTING      0x37
#define BMX055_ACC_OFC_OFFSET_X     0x38
#define BMX055_ACC_OFC_OFFSET_Y     0x39
#define BMX055_ACC_OFC_OFFSET_Z     0x3A
#define BMX055_ACC_TRIM_GP0         0x3B
#define BMX055_ACC_TRIM_GP1         0x3C
#define BMX055_ACC_TRIM_GP2         0x3D
#define BMX055_ACC_TRIM_GP3         0x3E
#define BMX055_ACC_TRIM_BIST        0x3F
#define BMX055_ACC_FIFO_CONFIG_1    0x3F
#define BMX055_ACC_FIFO_DATA        0x42



////////////////////////////// Gyroscope Registers /////////////////////////////

// BMX055 Gyroscope I2C address
#define BMX055_GYRO_ADDRESS         0x68

// Gyroscope Register Addresses
#define BMX055_GYRO_WHO_AM_I        0x00
#define BMX055_GYRO_RATE_X_LSB      0x02
#define BMX055_GYRO_RATE_X_MSB      0x03
#define BMX055_GYRO_RATE_Y_LSB      0x04
#define BMX055_GYRO_RATE_Y_MSB      0x05
#define BMX055_GYRO_RATE_Z_LSB      0x06
#define BMX055_GYRO_RATE_Z_MSB      0x07
#define BMX055_GYRO_INT_STATUS_0    0x09
#define BMX055_GYRO_INT_STATUS_1    0x0A
#define BMX055_GYRO_INT_STATUS_2    0x0B
#define BMX055_GYRO_INT_STATUS_3    0x0C
#define BMX055_GYRO_FIFO_STATUS     0x0E
#define BMX055_GYRO_RANGE           0x0F
#define BMX055_GYRO_BW              0x10
#define BMX055_GYRO_LPM1            0x11
#define BMX055_GYRO_LPM2            0x12
#define BMX055_GYRO_RATE_HBW        0x13
#define BMX055_GYRO_SOFTRESET       0x14
#define BMX055_GYRO_INT_ENABLE_0    0x15
#define BMX055_GYRO_INT_ENABLE_1    0x16
#define BMX055_GYRO_INT_MAP_0       0x17
#define BMX055_GYRO_INT_MAP_1       0x18
#define BMX055_GYRO_INT_MAP_2       0x19
#define BMX055_GYRO_INT_SRC_1       0x1A
#define BMX055_GYRO_INT_SRC_2       0x1B
#define BMX055_GYRO_INT_RST_LATCH   0x21
#define BMX055_GYRO_HIGH_TH_X       0x22
#define BMX055_GYRO_HIGH_DUR_X      0x23
#define BMX055_GYRO_HIGH_TH_Y       0x24
#define BMX055_GYRO_HIGH_DUR_Y      0x25
#define BMX055_GYRO_HIGH_TH_Z       0x26
#define BMX055_GYRO_HIGH_DUR_Z      0x27
#define BMX055_GYRO_SOC             0x31
#define BMX055_GYRO_A_FOC           0x32
#define BMX055_GYRO_TRIM_NVM_CTRL   0x33
#define BMX055_GYRO_BGW_SPI3_WDT    0x34
#define BMX055_GYRO_OFFSET_X        0x36
#define BMX055_GYRO_OFFSET_Y        0x37
#define BMX055_GYRO_OFFSET_Z        0x38
#define BMX055_GYRO_TRIM_GP0        0x3A
#define BMX055_GYRO_TRIM_GP1        0x3B
#define BMX055_GYRO_BIST            0x3C
#define BMX055_GYRO_FIFO_CONFIG_0   0x3D
#define BMX055_GYRO_FIFO_CONFIG_1   0x3E
#define BMX055_GYRO_FIFO_DATA       0x3F


//////////////////////////// Magnetometer Registers ////////////////////////////

// BMX055 Magnetometer I2C address
#define BMX055_MAG_ADDRESS          0x12 // 0x10

// Magnetometer Register Addresses
#define BMX055_MAG_WHO_AM_I         0x40
#define BMX055_MAG_DATA_X_LSB       0x42
#define BMX055_MAG_DATA_X_MSB       0x43
#define BMX055_MAG_DATA_Y_LSB       0x44
#define BMX055_MAG_DATA_Y_MSB       0x45
#define BMX055_MAG_DATA_Z_LSB       0x46
#define BMX055_MAG_DATA_Z_MSB       0x47
#define BMX055_MAG_RHALL_LSB        0x48
#define BMX055_MAG_RHALL_MSB        0x49
#define BMX055_MAG_INT_STATUS       0x4A
#define BMX055_MAG_POWER_CONTROL    0x4B
#define BMX055_MAG_OP_MODE          0x4C
#define BMX055_MAG_INT_ENABLE       0x4D
#define BMX055_MAG_AXIS_REP_XY      0x4E
#define BMX055_MAG_AXIS_REP_Z       0x51






void BMX055_Write(uint8_t address, uint8_t reg, uint8_t data);
uint8_t BMX055_Read(uint8_t deviceAddress, uint8_t reg, int16_t * valueX, int16_t * valueY, int16_t * valueZ);
void BMX055_Init(void) ;


#endif	/* API_BMX055_H */

