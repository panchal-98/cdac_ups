/**
 * CONFIGURATION_BITS Generated Driver Source File 
 * 
 * @file      configuration_bits.c
 *            
 * @defgroup  config_bitsdriver CONFIGBITS Driver
 *            
 * @brief     Device Configuration Bits using dsPIC MCUs
 *
 * @version   Firmware Driver Version 1.0.1
 *
 * @version   PLIB Version 1.2.3
 *
 * @skipline  Device : dsPIC33CK32MC102
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

// Configuration bits: selected in the GUI

// FSEC
#pragma config BWRP = OFF    //Boot Segment Write-Protect bit->Boot Segment may be written
#pragma config BSS = DISABLED    //Boot Segment Code-Protect Level bits->No Protection (other than BWRP)
#pragma config BSEN = OFF    //Boot Segment Control bit->No Boot Segment
#pragma config GWRP = OFF    //General Segment Write-Protect bit->General Segment may be written
#pragma config GSS = DISABLED    //General Segment Code-Protect Level bits->No Protection (other than GWRP)
#pragma config CWRP = OFF    //Configuration Segment Write-Protect bit->Configuration Segment may be written
#pragma config CSS = DISABLED    //Configuration Segment Code-Protect Level bits->No Protection (other than CWRP)
#pragma config AIVTDIS = OFF    //Alternate Interrupt Vector Table bit->Disabled AIVT

// FBSLIM
#pragma config BSLIM = 0x1fff    //Boot Segment Flash Page Address Limit bits

// FOSCSEL
#pragma config FNOSC = FRC    //Oscillator Source Selection->Internal Fast RC (FRC)
#pragma config IESO = OFF    //Two-speed Oscillator Start-up Enable bit->Start up with user-selected oscillator source

// FOSC
#pragma config POSCMD = NONE    //Primary Oscillator Mode Select bits->Primary Oscillator disabled
#pragma config OSCIOFNC = ON    //OSC2 Pin Function bit->OSC2 is general purpose digital I/O pin
#pragma config FCKSM = CSDCMD    //Clock Switching Mode bits->Both Clock switching and Fail-safe Clock Monitor are disabled
#pragma config PLLKEN = ON    //PLL Lock Enable->PLL clock output will be disabled if LOCK is lost
#pragma config XTCFG = G3    //XT Config->24-32 MHz crystals
#pragma config XTBST = ENABLE    //XT Boost->Boost the kick-start

// FWDT
#pragma config RWDTPS = PS2147483648    //Run Mode Watchdog Timer Post Scaler select bits->1:2147483648
#pragma config RCLKSEL = LPRC    //Watchdog Timer Clock Select bits->Always use LPRC
#pragma config WINDIS = ON    //Watchdog Timer Window Enable bit->Watchdog Timer in Non-Window mode
#pragma config WDTWIN = WIN25    //Watchdog Timer Window Select bits->WDT Window is 25% of WDT period
#pragma config SWDTPS = PS2147483648    //Sleep Mode Watchdog Timer Post Scaler select bits->1:2147483648
#pragma config FWDTEN = ON_SW    //Watchdog Timer Enable bit->WDT controlled via SW, use WDTCON.ON bit

// FPOR
#pragma config BISTDIS = DISABLED    //Memory BIST Feature Disable->mBIST on reset feature disabled

// FICD
#pragma config ICS = PGD3    //ICD Communication Channel Select bits->Communicate on PGC3 and PGD3
#pragma config JTAGEN = OFF    //JTAG Enable bit->JTAG is disabled

// FDMTIVTL
#pragma config DMTIVTL = 0x0    //Dead Man Timer Interval low word

// FDMTIVTH
#pragma config DMTIVTH = 0x0    //Dead Man Timer Interval high word

// FDMTCNTL
#pragma config DMTCNTL = 0x0    //Lower 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF)

// FDMTCNTH
#pragma config DMTCNTH = 0x0    //Upper 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF)

// FDMT
#pragma config DMTDIS = OFF    //Dead Man Timer Disable bit->Dead Man Timer is Disabled and can be enabled by software

// FDEVOPT
#pragma config ALTI2C1 = OFF    //Alternate I2C1 Pin bit->I2C1 mapped to SDA1/SCL1 pins
#pragma config SMB3EN = SMBUS3    //SM Bus Enable->SMBus 3.0 input levels
#pragma config SPI2PIN = PPS    //SPI2 Pin Select bit->SPI2 uses I/O remap (PPS) pins

// FALTREG
#pragma config CTXT1 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits->Not Assigned
#pragma config CTXT2 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits->Not Assigned
#pragma config CTXT3 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 3 bits->Not Assigned
#pragma config CTXT4 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 4 bits->Not Assigned

/**
 End of File
*/