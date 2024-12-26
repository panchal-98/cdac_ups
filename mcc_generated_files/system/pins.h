/**
 * PINS Generated Driver Header File 
 * 
 * @file      pins.h
 *            
 * @defgroup  pinsdriver Pins Driver
 *            
 * @brief     The Pin Driver directs the operation and function of 
 *            the selected device pins using dsPIC MCUs.
 *
 * @skipline @version   Firmware Driver Version 1.0.2
 *
 * @skipline @version   PLIB Version 1.3.0
 *
 * @skipline  Device : dsPIC33CK32MC102
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

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

// Section: Device Pin Macros

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA0 GPIO Pin which has a custom name of IO_RA0 to High
 * @pre      The RA0 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RA0_SetHigh()          (_LATA0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA0 GPIO Pin which has a custom name of IO_RA0 to Low
 * @pre      The RA0 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RA0_SetLow()           (_LATA0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RA0 GPIO Pin which has a custom name of IO_RA0
 * @pre      The RA0 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RA0_Toggle()           (_LATA0 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RA0 GPIO Pin which has a custom name of IO_RA0
 * @param    none
 * @return   none  
 */
#define IO_RA0_GetValue()         _RA0

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA0 GPIO Pin which has a custom name of IO_RA0 as Input
 * @param    none
 * @return   none  
 */
#define IO_RA0_SetDigitalInput()  (_TRISA0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA0 GPIO Pin which has a custom name of IO_RA0 as Output
 * @param    none
 * @return   none  
 */
#define IO_RA0_SetDigitalOutput() (_TRISA0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB1 GPIO Pin which has a custom name of IO_RB1 to High
 * @pre      The RB1 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB1_SetHigh()          (_LATB1 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB1 GPIO Pin which has a custom name of IO_RB1 to Low
 * @pre      The RB1 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB1_SetLow()           (_LATB1 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB1 GPIO Pin which has a custom name of IO_RB1
 * @pre      The RB1 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB1_Toggle()           (_LATB1 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB1 GPIO Pin which has a custom name of IO_RB1
 * @param    none
 * @return   none  
 */
#define IO_RB1_GetValue()         _RB1

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB1 GPIO Pin which has a custom name of IO_RB1 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB1_SetDigitalInput()  (_TRISB1 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB1 GPIO Pin which has a custom name of IO_RB1 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB1_SetDigitalOutput() (_TRISB1 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB3 GPIO Pin which has a custom name of IO_RB3 to High
 * @pre      The RB3 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB3_SetHigh()          (_LATB3 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB3 GPIO Pin which has a custom name of IO_RB3 to Low
 * @pre      The RB3 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB3_SetLow()           (_LATB3 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB3 GPIO Pin which has a custom name of IO_RB3
 * @pre      The RB3 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB3_Toggle()           (_LATB3 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB3 GPIO Pin which has a custom name of IO_RB3
 * @param    none
 * @return   none  
 */
#define IO_RB3_GetValue()         _RB3

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB3 GPIO Pin which has a custom name of IO_RB3 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB3_SetDigitalInput()  (_TRISB3 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB3 GPIO Pin which has a custom name of IO_RB3 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB3_SetDigitalOutput() (_TRISB3 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB4 GPIO Pin which has a custom name of IO_RB4 to High
 * @pre      The RB4 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetHigh()          (_LATB4 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB4 GPIO Pin which has a custom name of IO_RB4 to Low
 * @pre      The RB4 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetLow()           (_LATB4 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB4 GPIO Pin which has a custom name of IO_RB4
 * @pre      The RB4 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB4_Toggle()           (_LATB4 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB4 GPIO Pin which has a custom name of IO_RB4
 * @param    none
 * @return   none  
 */
#define IO_RB4_GetValue()         _RB4

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB4 GPIO Pin which has a custom name of IO_RB4 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetDigitalInput()  (_TRISB4 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB4 GPIO Pin which has a custom name of IO_RB4 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetDigitalOutput() (_TRISB4 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB9 GPIO Pin which has a custom name of IO_RB9 to High
 * @pre      The RB9 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB9_SetHigh()          (_LATB9 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB9 GPIO Pin which has a custom name of IO_RB9 to Low
 * @pre      The RB9 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB9_SetLow()           (_LATB9 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB9 GPIO Pin which has a custom name of IO_RB9
 * @pre      The RB9 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB9_Toggle()           (_LATB9 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB9 GPIO Pin which has a custom name of IO_RB9
 * @param    none
 * @return   none  
 */
#define IO_RB9_GetValue()         _RB9

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB9 GPIO Pin which has a custom name of IO_RB9 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB9_SetDigitalInput()  (_TRISB9 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB9 GPIO Pin which has a custom name of IO_RB9 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB9_SetDigitalOutput() (_TRISB9 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB10 GPIO Pin which has a custom name of IO_RB10 to High
 * @pre      The RB10 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB10_SetHigh()          (_LATB10 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB10 GPIO Pin which has a custom name of IO_RB10 to Low
 * @pre      The RB10 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB10_SetLow()           (_LATB10 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB10 GPIO Pin which has a custom name of IO_RB10
 * @pre      The RB10 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB10_Toggle()           (_LATB10 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB10 GPIO Pin which has a custom name of IO_RB10
 * @param    none
 * @return   none  
 */
#define IO_RB10_GetValue()         _RB10

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB10 GPIO Pin which has a custom name of IO_RB10 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB10_SetDigitalInput()  (_TRISB10 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB10 GPIO Pin which has a custom name of IO_RB10 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB10_SetDigitalOutput() (_TRISB10 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB11 GPIO Pin which has a custom name of IO_RB11 to High
 * @pre      The RB11 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB11_SetHigh()          (_LATB11 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB11 GPIO Pin which has a custom name of IO_RB11 to Low
 * @pre      The RB11 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB11_SetLow()           (_LATB11 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB11 GPIO Pin which has a custom name of IO_RB11
 * @pre      The RB11 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB11_Toggle()           (_LATB11 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB11 GPIO Pin which has a custom name of IO_RB11
 * @param    none
 * @return   none  
 */
#define IO_RB11_GetValue()         _RB11

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB11 GPIO Pin which has a custom name of IO_RB11 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB11_SetDigitalInput()  (_TRISB11 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB11 GPIO Pin which has a custom name of IO_RB11 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB11_SetDigitalOutput() (_TRISB11 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);



#endif
