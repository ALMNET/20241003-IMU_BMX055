 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif


#include "mcc_generated_files/system/system.h"
#include "API_BMX055_18F47K42.h"




/*
    Main application
*/

// Function prototypes
void BMX055_Init(void);
void BMX055_ReadAccelerometer(int16_t *x, int16_t *y, int16_t *z);
uint8_t BMX055_ReadRegister(uint8_t reg);
void BMX055_WriteRegister(uint8_t reg, uint8_t data);void BXM055_I2C_Write(uint8_t bmx055_reg, uint8_t bmx055_data);
uint8_t BXM055_I2C_Read(uint8_t bmx055_reg);

float application_accelerometer(ADXL_Level_t * ADXL_Level);


// Delay in milliseconds
void delay_ms(unsigned long delay_value){
    for(unsigned long x=0; x < delay_value; x++) __delay_ms(1);
}

void PPS_Init(void) {
    // Unlock PPS registers
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0; // Unlock sequence

    // Configure RB2 as SDA and RB3 as SCL for I2C1
    SSP1DATPPS = 0x0A;  // Set RB2 (pin 10) as I2C1 SDA input
    SSP1CLKPPS = 0x0B;  // Set RB3 (pin 11) as I2C1 SCL input
    RB2PPS = 0x14;      // Set RB2 as I2C1 SDA output
    RB3PPS = 0x13;      // Set RB3 as I2C1 SCL output

    // Lock PPS registers
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 1; // Lock sequence
}



int main(void)
{
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 
    
    
    
    
    
    
    BMX055_Init();
    
    //BMX055_Write(START_REGISTER_ACCEL, 0x08);
    // BMX055_Read(START_REGISTER_ACCEL);
    //BMX055_Write(0x50, 0x32);
    // BMX055_Init();

    LED_SYS_SetDigitalOutput();
    while(1)
    {
        LED_SYS_SetHigh();
        delay_ms(100);
        LED_SYS_SetLow();
        delay_ms(900);
        BMX055_Read(START_REGISTER_ACCEL);
    }    
}

//
//void BXM055_I2C_Write(uint8_t bmx055_reg, uint8_t bmx055_data) {
//    
//    uint8_t bmx055_address = 0x18;
//    
//    uint8_t dataarray[2];
//    
//    dataarray[0] = bmx055_reg;
//    dataarray[1] = bmx055_data;
//    
//    I2C1_Write(bmx055_address, dataarray, 2);
//}
//
//uint8_t BXM055_I2C_Read(uint8_t bmx055_reg) {
//    
//    uint8_t bmx055_Data[];
//    
//    uint8_t bmx055_address = 0x18;
//    
//    
//    //I2C1_WriteRead(bmx055_address | 0x01, bmx055_reg, &bmx055_Data, 1);
//    I2C1_WriteRead(bmx055_address, &bmx055_reg, 1, &bmx055_Data, 1);
//    
////    I2C1_MasterStart();
////    I2C1_MasterWrite(address);
////    I2C1_MasterWrite(reg);
////    I2C1_MasterRestart();
////    I2C1_MasterWrite(address | 0x01);
////    data = I2C1_MasterRead(NACK);
////    I2C1_MasterStop();
//    return bmx055_Data;
//}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////// AUXILIARY FUNCTIONS /////////////////////////////
///////////////////////////////////////////////////////////////////////////////

float application_accelerometer(ADXL_Level_t * ADXL_Level)
{
    int16_t axisX, axisY, axisZ;
    
    static float movementMagnitude, previousMagnitude;
    int deltaMagnitude;
    
    BMX055_ReadAccel(&axisX, &axisY, &axisZ);
        
    movementMagnitude = resultMagnitude(axisX, axisY, axisZ);

    deltaMagnitude = abs((int)(movementMagnitude - previousMagnitude));

    if(deltaMagnitude < ADXL_LOW_THRESHOLD)
        *ADXL_Level = ADXL_LOW;

    else if(deltaMagnitude > ADXL_LOW_THRESHOLD && deltaMagnitude < ADXL_HIG_THRESHOLD)
        *ADXL_Level = ADXL_MEDIUM;

    else if(deltaMagnitude > ADXL_HIG_THRESHOLD)
        *ADXL_Level = ADXL_HIGH;

    previousMagnitude = movementMagnitude;

    return deltaMagnitude;
}



