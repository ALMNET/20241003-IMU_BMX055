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
� [2024] Microchip Technology Inc. and its subsidiaries.

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

/*
    Main application
*/

// Function prototypes
void BMX055_Init(void);
void BMX055_ReadAccelerometer(int16_t *x, int16_t *y, int16_t *z);
uint8_t BMX055_ReadRegister(uint8_t reg);
void BMX055_WriteRegister(uint8_t reg, uint8_t data);


// Delay in milliseconds
void delay_ms(unsigned long delay_value){
    for(unsigned long x=0; x < delay_value; x++) __delay_ms(1);
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

    LED_SYS_SetDigitalOutput();
    while(1)
    {
        LED_SYS_SetHigh();
        delay_ms(100);
        LED_SYS_SetLow();
        delay_ms(900);
        printf("\nReady");
    }    
}

void BXM055_I2C_Write(uint8_t bmx055_reg, uint8_t bmx055_data) {
    
    uint8_t bmx055_address = 0x18;
    
    uint8_t dataarray[2];
    
    dataarray[0] = bmx055_reg;
    dataarray[1] = bmx055_data;
    
    I2C1_Write(bmx055_address, dataarray, 2);
}

uint8_t BXM055_I2C_Read(uint8_t bmx055_reg) {
    
    uint8_t bmx055_address = 0x18;
    uint8_t readData;
    
    
    I2C1_WriteRead(address | 0x01, bmx055_reg, &readData, 1);
    // I2C1_WriteRead(bmx055_address, )
    
//    I2C1_MasterStart();
//    I2C1_MasterWrite(address);
//    I2C1_MasterWrite(reg);
//    I2C1_MasterRestart();
//    I2C1_MasterWrite(address | 0x01);
//    data = I2C1_MasterRead(NACK);
//    I2C1_MasterStop();
    return data;
}
