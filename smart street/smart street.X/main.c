/*
 * File:   main.c
 * Author: Mohamed_Arafa
 *
 * Created on October 8, 2021, 9:28 PM
 */
#define _XTAL_FREQ  8000000UL
#include <xc.h>
#include <pic16f877a.h>

//macro

#include "config.h"

#define led_port PORTA
#define led_tris TRISA

#define sensor_port PORTB
#define sensor_tris TRISB
#define u8 unsigned char
///*******sensors*********/

#define s_right_1 RB0
u8 s_right_1_f = 0;
#define s_right_2 RB1
u8 s_right_2_f = 0;
#define s_left_1  RB2
u8 s_left_1_f = 0;
#define s_left_2  RB3
u8 s_left_2_f = 0;
#define s_top_1   RB4
u8 s_top_1_f = 0;
#define s_top_2   RB5
u8 s_top_2_f = 0;
#define s_bottom_1 RB6
u8 s_bottom_1_f = 0;
#define s_bottom_2 RB7
u8 s_bottom_2_f = 0;

u8 s_square_1_f = 0;
u8 s_square_2_f = 0;
/**********leds**********/
#define l_right_1 RA0
#define l_right_2 RA1

#define l_left_1  RA2
#define l_left_2  RA3

#define l_top   RE1
#define l_bottom RA5

#define l_square RE0

void main(void) {
    ADCON1=0x07;
    led_tris = 0x00;
    sensor_tris = 0xff;
    TRISE = 0;
    
    PORTE = 0;
    //led_port = 0;
    int count_r = 0;
    int count_l = 0;
    int count_t = 0;
    int count_b = 0;
    int count_s = 0;
    for (;;){
        if(s_right_1 == 0)
        {
            l_right_1=1;
            l_right_2=1;
        }
        else {
            l_right_1=0;
            l_right_2=0;
            
        }
    }
    
  
    while (1) {
        // main code

        //right streets
        if (s_right_1 == 0 && s_right_1_f == 0) {
            count_r++;
            s_right_1_f = 1;
        }
        if (s_right_1 == 1) {
            s_right_1_f = 0;
        }

        if (s_right_2 == 0 && s_right_2_f == 0) {
            count_r--;
            s_right_2_f = 1;
        }
        if (s_right_2 == 1) {
            s_right_2_f = 0;
        }

        /****left street*****/
        if (s_left_1 == 0 && s_left_1_f == 0) {
            count_l++;
            s_left_1_f = 1;
        }
        if (s_left_1 == 1) {
            s_left_1_f = 0;
        }

        if (s_left_2 == 0 && s_left_2_f == 0) {
            count_l--;
            s_left_2_f = 1;
        }
        if (s_left_2 == 1) {
            s_left_2_f = 0;
        }

        // top & bottom streets


        if (s_top_1 == 0 && s_top_1_f == 0) {
            count_t++;
            s_top_1_f = 1;
        }
        if (s_top_1 == 1) {
            s_top_1_f = 0;
        }
        if (s_top_2 == 0 && s_top_2_f == 0) {
            count_t--;
            s_top_2_f = 1;
        }
        if (s_top_2 == 1) {
            s_top_2_f = 0;
        }
        if (s_bottom_1 == 0 && s_bottom_1_f == 0) {
            count_b++;
            s_bottom_1_f = 1;
        }
        if (s_bottom_1 == 1) {
            s_bottom_1_f = 0;
        }

        if (s_bottom_2 == 0 && s_bottom_2_f == 0) {
            count_b--;
            s_bottom_2_f = 1;
        }
        if (s_bottom_2 == 1) {
            s_bottom_2_f = 0;
        }
        // square

        if ((s_top_2 == 0 || s_right_2 == 0) && s_square_1_f == 0) {
            count_s++;
            s_square_1_f = 1;
        }
        if ((s_top_2 == 1 && s_right_2 == 1)) {
            s_square_1_f = 0;
        }


        if ((s_bottom_1 == 0 || s_left_1 == 0) && s_square_2_f == 0) {
            count_s--;
            s_square_2_f = 1;
        }
        if ((s_bottom_1 == 1 && s_left_1 == 1)) {
            s_square_2_f = 0;
        }

        //bottom street LEDs
        if (count_b) {
            l_bottom = 1;
        } else {
            l_bottom = 0;
        }

        //top street LEDs
        if (count_t) {
            l_top = 1;
        } else {
            l_top = 0;
        }

        //left street LEDs
        if (count_l) {
            l_left_1 = 1;
            l_left_2 = 1;
        } else {
            l_left_1 = 0;
            l_left_2 = 0;
        }

        //right street LEDs
        if (count_r) {
            l_right_1 = 1;
            l_right_2 = 1;
        } else {
            l_right_1 = 0;
            l_right_2 = 0;
        }
        
        //square LEDs
        if (count_s) {
            l_square = 1;
        } else {
            l_square = 0;
        }
    }
    return;
}

