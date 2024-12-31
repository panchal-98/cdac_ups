/* My Name is Rahul Panchal 
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

#include <stdio.h>
#include <math.h>
#include <xc.h> // Include header for device-specific registers
#include <stdint.h> // Include for standard integer types
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/system/clock.h"
#define FCY CLOCK_PeripheralFrequencyGet()
#include <libpic30.h>
#include "mcc_generated_files/uart/uart1.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/pwm_hs/pwm.h"

/**********************ADC interface start**************/

#include "mcc_generated_files/adc/adc1.h"
const struct ADC_INTERFACE *adc = &ADC1;
const struct UART_INTERFACE *UartSerial = &UART1_Drv;
#define ADC_RESOLUTION 4096
uint16_t volatile adcResult;
//uint16_t ac_input_voltage; // contain data of AN2  - RB7
//uint16_t ac_output_voltage; // contain data of AN10 - RB8
uint16_t ac_input_current; // contain data of AN9  - RA2
uint16_t ac_output_current; // contain data of AN3  - RA3
//uint8_t  dc_battery_volt; // contain data of AN7  - RB2
uint16_t acvolt_in;
/**********************ADC interface end**************/

/***********************relay pins declararion Start****************************/

#define relay1            RB11         // here by this pin battery charging relay on
#define relay2            RA0        // here by this pin ac bypass in ouput
#define relay3            RB10        // here by this pin ac out using inverter circuit



/***********************relay pins declararion Start****************************/


#define buzzer            RB1 // here by this we can control buzzer
#define green_led         RB9         // Here D2 led control
#define red_led           RB3         // Here D3 led control



///*********************************PWM START*************************************/

static uint8_t sineIndex = 0; // initialization for look up table value PWM_1
static uint8_t sineIndex2 = 0; // initialization for look up table value PWM_2
volatile uint8_t gen1 = 0;
volatile uint8_t gen2 = 0;
#define SINE_TABLE_SIZE 200

const uint16_t sineTable[SINE_TABLE_SIZE] = {
    0, 0, 0, 1, 1, 1, 2, 2, 3, 4,
    5, 6, 7, 8, 10, 11, 12, 14,
    //    0, 0, 1, 1, 2, 2, 3, 4,
    //    5, 6, 7, 8, 10, 11, 12, 14,
    16, 17, 19, 21, 23, 25, 27, 29,
    32, 34, 36, 39, 41, 44, 46, 49,
    52, 55, 57, 60, 63, 66, 69, 72,
    75, 78, 81, 84, 87, 91, 94, 97,
    100, 103, 106, 109, 113, 116, 119, 122,
    125, 128, 131, 134, 137, 140, 143, 145,
    148, 151, 154, 156, 159, 161, 164, 166,
    168, 171, 173, 175, 177, 179, 181, 183,
    184, 186, 188, 189, 190, 192, 193, 194,
    195, 196, 197, 198, 198, 199, 199, 200,
    200, 200, 200, 200, 200, 200, 199, 199,
    198, 198, 197, 196, 195, 194, 193, 192,
    190, 189, 188, 186, 184, 183, 181, 179,
    177, 175, 173, 171, 168, 166, 164, 161,
    159, 156, 154, 151, 148, 145, 143, 140,
    137, 134, 131, 128, 125, 122, 119, 116,
    113, 109, 106, 103, 100, 97, 94, 91,
    87, 84, 81, 78, 75, 72, 69, 66,
    63, 60, 57, 55, 52, 49, 46, 44,
    41, 39, 36, 34, 32, 29, 27, 25,
    23, 21, 19, 17, 16, 14, 12, 11,
    10, 8, 7, 6, 5, 4, 3, 2,
    2, 1, 1, 0, 0, 0,

};
const uint16_t sineTable1[200] = {
    0, 0, 0, 1, 1, 2, 3, 4, 4, 5,
    5, 6, 7, 8, 10, 11, 12, 14,
    16, 17, 19, 21, 23, 25, 27, 29,
    32, 34, 36, 39, 41, 44, 46, 49,
    52, 55, 57, 60, 63, 66, 69, 72,
    75, 78, 81, 84, 87, 91, 94, 97,
    100, 103, 106, 109, 113, 116, 119, 122,
    125, 128, 131, 134, 137, 140, 143, 145,
    148, 151, 154, 156, 159, 161, 164, 166,
    168, 171, 173, 175, 177, 179, 181, 183,
    184, 186, 188, 189, 190, 192, 193, 194,
    195, 196, 197, 198, 198, 199, 199, 200,
    200, 200, 200, 200, 200, 200, 199, 199,
    198, 198, 197, 196, 195, 194, 193, 192,
    190, 189, 188, 186, 184, 183, 181, 179,
    177, 175, 173, 171, 168, 166, 164, 161,
    159, 156, 154, 151, 148, 145, 143, 140,
    137, 134, 131, 128, 125, 122, 119, 116,
    113, 109, 106, 103, 100, 97, 94, 91,
    87, 84, 81, 78, 75, 72, 69, 66,
    63, 60, 57, 55, 52, 49, 46, 44,
    41, 39, 36, 34, 32, 29, 27, 25,
    23, 21, 19, 17, 16, 14, 12, 11,
    10, 8, 7, 6, 5, 5, 4, 4,
    //    3, 3, 2, 2, 1, 1, 0, 0,
    2, 1, 1, 0, 0, 0,
};

void MyTimeoutHandler(void) {
    if (gen1) {
        sineIndex++;
        if (sineIndex > 200) {
            sineIndex = 0;
            gen2 = 1;
            gen1 = 0;
            PWM_DutyCycleSet(PWM_GENERATOR_1, 0);
        } else PWM_DutyCycleSet(PWM_GENERATOR_1, sineTable[sineIndex]);

    }

    if (gen2) {
        sineIndex2++;
        if (sineIndex2 > 200) {
            sineIndex2 = 0;
            gen2 = 0;
            gen1 = 1;
            PWM_DutyCycleSet(PWM_GENERATOR_2, 0);
        } else PWM_DutyCycleSet(PWM_GENERATOR_2, sineTable[sineIndex2]);

    }
    //    longpress_switch();
    __delay_us(20);
}
/*********************************PWM STOP*************************************/

/********************************PINS setup *****************************/
void gpio_pin_setup() {
    TRISBbits.TRISB4 = 1; // main mainswitch set as a input RB4
    TRISBbits.TRISB1 = 0; // here by this we can control buzzer RB1
    TRISAbits.TRISA0 = 0; // ac input power bypass relay2
    TRISBbits.TRISB10 = 0; // dc to ac out  by  relay3 
    TRISBbits.TRISB11 = 0; // charging on by  relay1 
    //    PORTBbits.buzzer = 0; // 
    //    PORTBbits.red_led = 0;
    //    PORTBbits.green_led = 0;
}

/********************************PINS setup *****************************/

/****************************stand by mode *************************************/
void stdby_mode() {
    PORTBbits.buzzer = 0;
}
/****************************stand by mode *************************************/




/*****************************Switch long press ****************************************/
#define mainswitch  RB4 // main switch  on off
unsigned int press_count = 0; // for switch condition
unsigned int long_press_threshold = 0; // Threshold for long press (~2 seconds at 1ms intervals) for switch condition
uint16_t volatile ups_switch;

uint8_t flag = 0;

void longpress_switch() {
    /**************************************  UPS switching start ************************************************/

    if (PORTBbits.mainswitch == 0) { // Double-check if the switch is still pressed


        press_count++;

        PORTBbits.buzzer = 0; // beep buzzer off
        __delay_ms(50);
        PORTBbits.buzzer = 1; // beep buzzer on
        __delay_ms(100);

        if (press_count >= long_press_threshold) {
            flag = 1;
            ups_switch = !ups_switch; // Toggle ups_switch_on state
            press_count = 0; // Reset press count after toggling
            if (flag == 1) {
                TMR1_Stop();
                flag = 0;
                TMR1_Start();
            }
        }

    } else {

        press_count = 0; // Reset press count 
        PORTBbits.buzzer = 0;
    }

    //    printf("ups_switch: %d\r\n", ups_switch); // Input voltage contain in veff
    /**************************************  UPS switching END************************************************/

}
/*****************************Switch long press ****************************************/

/*********************************switch case**************************************/
enum ups_switch {
    ups_on,
    ups_off
};

/*********************************switch case**************************************/



/***********************************AC input voltage mapping declaration***********************************/
uint16_t volatile ac_input_voltage;
int crosscount = 0;
int climb_flag = 0;
int val[100]; // Array to store sensor values
int max_v = 0;
int VmaxD = 0; // Max voltage
int VeffD = 0; // Effective voltage
float ac_inputvolt = 0; // Resulting voltage

void ac_input_volt_sense() {
    /******************** Ac volt input START ***********************/
    ac_input_voltage = adc->ConversionResultGet(Channel_AN2); // RB2 DC 12 volt sense
    for (int i = 0; i < 100; i++) {

        if (adc->ConversionResultGet(Channel_AN2) > 2040) {
            val[i] = ac_input_voltage; // Store sensor value in the array if it's greater than 511
        } else {
            val[i] = 0; // Otherwise, set the value to 0
        }
        //        __delay_ms(1); // Short delay for stability
    }

    // Find the maximum sensor value in the array
    max_v = 0;
    for (int i = 0; i < 100; i++) {
        if (val[i] > max_v) {
            max_v = val[i]; // Update max_v if a higher value is found
        }
        val[i] = 0; // Reset the array element to 0
    }

    // Calculate effective voltage based on the maximum sensor value
    if (max_v != 0) {
        VmaxD = max_v; // Set VmaxD to the maximum sensor value
        VeffD = VmaxD / sqrt(2); // Calculate effective voltage (RMS) from VmaxD
        //        Veff = (((VeffD - 2200.27) / -90.24) * -210.2) + 10 ;  // Apply calibration and scaling to Veff//42.76
        //        Veff = ((VeffD - 2210)/3); // here accurate mapping
        ac_inputvolt = ((VeffD - 2587) / 2) + 225; // here accurate mapping
        //Veff = ((VeffD - 600) / 2) + 230; // here accurate mapping
        if (ac_inputvolt <= 100) {
            ac_inputvolt = 0; // If no maximum value, set Veff to 0
        }
    } else {
        ac_inputvolt = 0; // If no maximum value, set Veff to 0

    }
    //    printf("\n VeffD: %d\r\n", VeffD); // Input voltage contain in veff
    printf("\n ac_inputvolt: %0.2f V\r\n", ac_inputvolt); // Input voltage contain in veff

    //    __delay_ms(100);
    VmaxD = 0; // Reset VmaxD for the next iteration


}

/***********************************AC voltage INPUT END mapping declaration***********************************/




/***********************************AC output voltage mapping declaration***********************************/
uint16_t ac_output_voltage; // contain data of AN10 - RB8
//int ac_out_crosscount = 0;
//int climb_flag = 0;
int ac_out_val[100]; // Array to store sensor values
int ac_out_max_v = 0;
int ac_out_VmaxD = 0; // Max voltage
int ac_out_VeffD = 0; // Effective voltage
float ac_outputvolt = 0; // Resulting voltage

void ac_output_volt_sense() {
    /******************** Ac volt input START ***********************/
    ac_output_voltage = adc->ConversionResultGet(Channel_AN10); // RB8 DC 12 volt sense
    for (int i = 0; i < 100; i++) {

        if (adc->ConversionResultGet(Channel_AN10) > 2040) {
            ac_out_val[i] = ac_output_voltage; // Store sensor value in the array if it's greater than 511
        } else {
            ac_out_val[i] = 0; // Otherwise, set the value to 0
        }
        //        __delay_ms(1); // Short delay for stability
    }

    // Find the maximum sensor value in the array
    ac_out_max_v = 0;
    for (int i = 0; i < 100; i++) {
        if (ac_out_val[i] > ac_out_max_v) {
            ac_out_max_v = ac_out_val[i]; // Update max_v if a higher value is found
        }
        ac_out_val[i] = 0; // Reset the array element to 0
    }

    // Calculate effective voltage based on the maximum sensor value
    if (ac_out_max_v != 0) {
        ac_out_VmaxD = ac_out_max_v; // Set VmaxD to the maximum sensor value
        ac_out_VeffD = ac_out_VmaxD / sqrt(2); // Calculate effective voltage (RMS) from VmaxD
        //        Veff = (((VeffD - 2200.27) / -90.24) * -210.2) + 10 ;  // Apply calibration and scaling to Veff//42.76
        //        Veff = ((VeffD - 2210)/3); // here accurate mapping
        ac_outputvolt = ((ac_out_VeffD - 2587) / 2) + 225; //here accurate mapping
        //Veff = ((VeffD - 600) / 2) + 230; // here accurate mapping
        if (ac_outputvolt <= 100) {
            ac_outputvolt = 0; // If no maximum value, set Veff to 0
        }
    } else {
        ac_outputvolt = 0; // If no maximum value, set Veff to 0

    }
    //    printf("\n VeffD: %d\r\n", VeffD); // Input voltage contain in veff
    printf("\n ac_outputvolt: %0.2f V\r\n", ac_outputvolt); // Input voltage contain in veff

    //    __delay_ms(100);
    ac_out_VmaxD = 0; // Reset VmaxD for the next iteration


}


/**********************************AC OUTPUT current sense start******************/

#define ac_out_current_VREF 3.3               // ADC reference voltage
#define ac_out_current_ADC_MAX 4095           // 12-bit ADC maximum value
#define ac_out_current_OFFSET_VOLTAGE 2.5     // Midpoint voltage of the current sensor (e.g., ACS712)
#define ac_out_current_SENSITIVITY 0.185      // Sensor sensitivity in V/A (e.g., ACS712-5A)
uint16_t ac_out_cuurnt;
float current;

float Get_Current(uint16_t ac_out_current) {
    float voltage = (ac_out_current * ac_out_current_VREF) / ac_out_current_ADC_MAX; // Convert ADC value to voltage
    return (voltage - ac_out_current_OFFSET_VOLTAGE) / ac_out_current_SENSITIVITY; // Calculate current in Amperes
}

void acouput_current() {
    uint16_t ac_out_current = adc->ConversionResultGet(Channel_AN3); // RA3 DC 12 volt sense
    float current = Get_Current(ac_out_current); // Convert ADC value to current
    //    printf("\n current: %0.2f A\r\n", ac_out_current); // Input voltage contain in veff
    printf("\n current: %d \r\n", ac_out_current); // Input voltage contain in veff
}

/**********************************AC OUTPUT current sense END***************/

/***********************************AC voltage output END mapping declaration***********************************/




/************************************DC 12V sense*************************************************/
uint16_t dc_battery_volt; // battery DC 12 volt sense  RB2-AN7
#define VREF 3.3 // Reference voltage (adjust if needed)
#define ADC_MAX_VALUE 1023.0 // Maximum value for 10-bit ADC
float dc12v;

void dc_12v_sense() {
    dc_battery_volt = adc->ConversionResultGet(Channel_AN9); // RA2 DC 12 current sense
    //        adcResult = ADC->GetConversion(Channel_AN0);
    //       printf("dcvol: %f\r\n",vo);

    dc12v = (dc_battery_volt * VREF) / ADC_MAX_VALUE;
    dc12v = dc12v + 3.5;

    /*****************************charging section******************************************/

    /*****************************charging section******************************************/
    // Print voltage using printf (ensure UART is configured for printf)
    printf("DC Voltage: %.2f V\r\n", dc12v);

    //    __delay_ms(500); // Delay to avoid spamming output
    //        ac_volt_in();

}

/************************************DC 12V sense*************************************************/

/********************************************DC 12V Current sense start*************************************************/
double dc12v__current_acs712_sensitivity = 0.18;
double dc12v_Cout = 0;
double dc12v_Current = 0;
uint16_t dc12v_current_sense = 0;

void dc_current_sense() {
    dc12v_current_sense = adc->ConversionResultGet(Channel_AN7); // RB2 DC 12 volt sense
    dc12v_Cout = ((3.3 / 4095) * dc12v_current_sense);
    dc12v_Current = ((dc12v_Cout - 2.58) / dc12v__current_acs712_sensitivity);

    printf("\n dc12v_Current: %0.2f V\r\n", dc12v_Current);
}

/********************************************DC 12V Current sense start*************************************************/

/*****************************************sine wave generate ******************************************************/

void sinewave_generate() {
    SCCP1_Timer_TimeoutCallbackRegister(MyTimeoutHandler);
    // Set interrupt priority

    SCCP1_Timer_InterruptPrioritySet(1);
    // Start the timer
    SCCP1_Timer_Start();
    gen2 = 1;
    //    __delay_us(20);
}

void MYTIMER_10MS(void) {
    longpress_switch();
    //PORTBbits.RB9 = !PORTBbits.RB9;
    //    gen1 = !gen1;
    //    sineIndex = 0;
    //    sineIndex2 = 0;
    //    if (gen1) {
    //        gen2 = 0;
    //        //     sineIndex = (sineIndex + 1) % SINE_TABLE_SIZE;
    //        //     __delay_us(10);
    //    } else {
    //        gen2 = 1;
    //        //    sineIndex2 = (sineIndex2 + 1) % SINE_TABLE_SIZE;
    //        //    __delay_us(10);
    //
    //    }

}

int main(void) {
    SYSTEM_Initialize();


    TMR1_TimeoutCallbackRegister(MYTIMER_10MS);
    //    TMR1_Start();
    //    printf("\n 1202: %0.2f V\r\n");
    gpio_pin_setup();
    //    sinewave_generate();
    //    sinewave_generate();
    /*********************************PWM START*************************************/
    //        SCCP1_Timer_TimeoutCallbackRegister(MyTimeoutHandler);
    //        // Set interrupt priority
    //        SCCP1_Timer_InterruptPrioritySet(1);
    //        // Start the timer
    //            SCCP1_Timer_Start();
    //            gen2 = 1;
    /*********************************PWM STOP*************************************/
    ups_switch = PORTBbits.mainswitch; // GPIO RB4 read


    TMR1_Start();
    // float voltage; // Variable to store calculated voltage
    //    uint16_t adcResult; // Variable to store raw ADC result
    while (1) {
        adc->SoftwareTriggerEnable();

        //        longpress_switch();
        ac_input_volt_sense();
        ac_output_volt_sense();
        acouput_current();
        dc_12v_sense();
        stdby_mode();



        switch (ups_switch) {
            case ups_on:

                //                PORTBbits.buzzer = 0;
                //                longpress_switch();
                if (ac_inputvolt > 0) {
                    SCCP1_Timer_Stop();
                    PORTBbits.relay3 = 0; // Relay3 off RB10 pin control and by this pin dc to ac pass 
                    PORTBbits.buzzer = 0;
                    PORTBbits.green_led = 0; // green led on
                    PORTBbits.red_led = 0; // red led on
                    PORTAbits.relay2 = 1; // AC bypass by this relay2
                    if (dc12v < 10) {
                        PORTBbits.relay1 = 1; // RB11 charging relay on
                    } else if (dc12v > 14) {
                        PORTBbits.relay1 = 0; // RB11 charging relay off
                    }

                } else {

                   
                    PORTBbits.relay3 = 1; // Relay3 on RB10 pin control and by this pin dc to ac pass 
                     sinewave_generate();
                    //                    SCCP1_Timer_Start();
                    //                    gen2 = 1;

                    PORTBbits.green_led = 1; // green led off
                    PORTBbits.red_led = 0; // red led off
                    PORTAbits.relay2 = 0; // AC bypass by this relay2
                    PORTBbits.buzzer = 0;
                }
                //                printf("dc12v: %0.2f\r\n",dc12v);

                break;

            case ups_off:
                SCCP1_Timer_Stop();
                PORTBbits.relay3 = 0; // Relay3 off RB10 pin control and by this pin dc to ac pass 
                PORTAbits.relay2 = 0; // AC bypass by this relay2
                SCCP1_Timer_Stop();
                PORTBbits.red_led = 1;
                PORTBbits.green_led = 1;
                PORTBbits.buzzer = 0;
                break;

            default:

                break;
        }
    }
}