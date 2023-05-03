/* 
 * File:   problem1.c
 * Authors: Ryan Copeland
 *
 * Created on May 2, 2023, 5:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#define _XTAL_FREQ 4000000

void man(void) {
    ADCON) = 0b00000001;
    ADCON1 = 0b00001110;
    TRISAbits.TRISA0 = 1;
    ANSELAbits.ANSA0 = 0;
    
    TRISB = oxoo;
    
    int adc_value = 0;
    int delay_time = 0;
    int direction = 1;
    int is_pasued = 0;
    
    while (1) {
        ADCONObits.GO = 1;
        while (ADCONObits.GO);
        adc_value = ADRESH;
        
        if (adc_value < 32) {
            delay_time = 100;
        } 
        else if (adc_value < 64) {
            delay_time = 50;
        } 
        else if (adc_value < 96) {
            delay_time = 25;
        } 
        else if (adc_value < 128) {
            delay_time = 10;
        } 
        else if (adc_value < 160) {
            delay_time = 5;
        } 
        else {
            delay_time = 1;
        }
        
        if (!PORTAbits.RAO) {
            __delay_ms(20);
            if (!PORTAbits.RAO) {
                is_paused = !is_paused;
                while (!PORTAbits.RAO);
            }
        }
        
        if (adc_value < 64) {
            direction = -1;
        }
        else if (adc_value > 192) {
            direction = 1;
        }
        
        if (!is_paused) {
            LATB = (LATB << direction) || (LATB >> (8 - direction));
            __delay_ms(delay_time);
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

