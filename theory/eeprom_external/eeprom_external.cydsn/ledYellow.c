/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
 #include <stdio.h>
 #include "project.h"

extern volatile unsigned long counter1_s;
volatile unsigned long time_current = 0;

enum Status_Led
{
    turn_on = 0,
    turn_off
};

void four_led_short_off() //0000 L3 L2 L1 L0 
{
    LedYellow_0_Write(turn_off);
    LedYellow_1_Write(turn_off);
    LedYellow_2_Write(turn_off);
    LedYellow_3_Write(turn_off);
}

void four_led_tall_off() // L7 L6 L5 L4 0000
{
    LedYellow_4_Write(turn_off);
    LedYellow_5_Write(turn_off);
    LedYellow_6_Write(turn_off);
    LedYellow_7_Write(turn_off);
}

void turn_off_all_led()
{
    LedYellow_0_Write(turn_off);
    LedYellow_1_Write(turn_off);
    LedYellow_2_Write(turn_off);
    LedYellow_3_Write(turn_off);
    
    LedYellow_4_Write(turn_off);
    LedYellow_5_Write(turn_off);
    LedYellow_6_Write(turn_off);
    LedYellow_7_Write(turn_off);
}

void turn_on_all_led()
{
    LedYellow_0_Write(turn_on);
    LedYellow_1_Write(turn_on);
    LedYellow_2_Write(turn_on);
    LedYellow_3_Write(turn_on);
    LedYellow_4_Write(turn_on);
    LedYellow_5_Write(turn_on);
    LedYellow_6_Write(turn_on);
    LedYellow_7_Write(turn_on);    
}

void location_led_light(int location)
{
    switch(location)
    {
        case 0:
            LedYellow_0_Write(turn_on);
            LedYellow_1_Write(turn_off);
            LedYellow_2_Write(turn_off);
            LedYellow_3_Write(turn_off);
            four_led_tall_off();
            break;
        case 1:
            LedYellow_0_Write(turn_off);
            LedYellow_1_Write(turn_on);
            LedYellow_2_Write(turn_off);
            LedYellow_3_Write(turn_off);
            four_led_tall_off();
            break;
        case 2:
            LedYellow_0_Write(turn_off);
            LedYellow_1_Write(turn_off);
            LedYellow_2_Write(turn_on);
            LedYellow_3_Write(turn_off);
            four_led_tall_off();
            break;
        case 3:
            LedYellow_0_Write(turn_off);
            LedYellow_1_Write(turn_off);
            LedYellow_2_Write(turn_off);
            LedYellow_3_Write(turn_on);
            four_led_tall_off();
            break;
        case 4:
            four_led_short_off();
            LedYellow_4_Write(turn_on);
            LedYellow_5_Write(turn_off);
            LedYellow_6_Write(turn_off);
            LedYellow_7_Write(turn_off);
            break;
        case 5:
            four_led_short_off();
            LedYellow_4_Write(turn_off);
            LedYellow_5_Write(turn_on);
            LedYellow_6_Write(turn_off);
            LedYellow_7_Write(turn_off);
            break;
        case 6:
            four_led_short_off();
            LedYellow_4_Write(turn_off);
            LedYellow_5_Write(turn_off);
            LedYellow_6_Write(turn_on);
            LedYellow_7_Write(turn_off);
            break;
        case 7:
            four_led_short_off();
            LedYellow_4_Write(turn_off);
            LedYellow_5_Write(turn_off);
            LedYellow_6_Write(turn_off);
            LedYellow_7_Write(turn_on);
    }
}

void shift_left(int location_light)
{
    switch(location_light)
    {
        case 0:
            location_led_light(0);
            break;
        case 1:
            location_led_light(1);
            break;
        case 2:
            location_led_light(2);
            break;
        case 3:
            location_led_light(3);
            break;
        case 4:
            location_led_light(4);
            break;
        case 5:
            location_led_light(5);
            break;
        case 6:
            location_led_light(6);
            break;
        case 7:
            location_led_light(7);
    }
}

void shift_right(int location_light)
{
    switch( 7 - location_light )
    {
        case 0:
            location_led_light(0);
            break;
        case 1:
            location_led_light(1);
            break;
        case 2:
            location_led_light(2);
            break;
        case 3:
            location_led_light(3);
            break;
        case 4:
            location_led_light(4);
            break;
        case 5:
            location_led_light(5);
            break;
        case 6:
            location_led_light(6);
            break;
        case 7:
            location_led_light(7);
    }
}

void flicker_8_led(unsigned long delay_s)
{
    static int flag_led = 0;
    
    if(counter1_s - time_current >= delay_s)
    {
        flag_led = ~flag_led;
        time_current = counter1_s;
    }
    
    if(flag_led == 0)    
        turn_off_all_led();
    else
        turn_on_all_led();    
}


/* [] END OF FILE */


