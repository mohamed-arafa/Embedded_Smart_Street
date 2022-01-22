/*
 * File:   main.c
 * Author: Mohamed_Arafa
 *
 * Created on October 8, 2021, 9:28 PM
 */
#define _XTAL_FREQ  8000000UL
#include <xc.h>
#include <pic16f877a.h>


#include "config.h"

unsigned short adc_read();
    
int main()
{
    ADCON0 = 0x41;
    ADCON1 = 0x8E;
    volatile unsigned short adc_result = 0;
    TRISD = 0x00;
    TRISC = 0;

    while (1) {
        adc_result=adc_read();
        if (adc_result < 100) {
            PORTD = 0XFF;
            PORTC = 0XFF;
        } else {
            PORTD = 0X00;
            PORTC = 0X00;

        }


    }
}

unsigned short adc_read() {
    ADCON0 = 0x41;
    ADCON1 = 0x8E;
    __delay_us(30);
    GO_DONE = 1;
    while (GO_DONE == 1);
    unsigned short adc_result = (ADRESH << 8) + ADRESL;
    return adc_result;

}