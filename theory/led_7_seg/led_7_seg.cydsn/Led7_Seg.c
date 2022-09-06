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

/* [] END OF FILE */
#include "project.h"        
#include <stdio.h>

enum Status_pin
{
    low = 0,
    hight
};

#include "Led7_Seg.h"

unsigned char code_Led7_Seg[] = {0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};

uint8 writeHightOrLow(uint8 dataNeedWrite, uint8 locationWrite)
{
    uint8 result = 0;
    
    switch(locationWrite)
    {
        case 0:
            ((dataNeedWrite & (1<<0)) == (1<<0) ) ? (result = hight) : (result = low);
            break;
        case 1:
            ((dataNeedWrite & (1<<1)) == (1<<1)) ? (result = hight) : (result = low);
            break;
        case 2:
            ((dataNeedWrite & (1<<2)) == (1<<2)) ? (result = hight) : (result = low);
            break;
        case 3:
            ((dataNeedWrite & (1<<3)) == (1<<3) ) ? (result = hight) : (result = low);
            break;
        case 4:
            ((dataNeedWrite & (1<<4)) == (1<<4) ) ? (result = hight) : (result = low);
            break;
        case 5:
            ((dataNeedWrite & (1<<5)) == (1<<5) ) ? (result = hight) : (result = low);
            break;
        case 6:
            ((dataNeedWrite & (1<<6)) == (1<<6) ) ? (result = hight) : (result = low);
            break;
        case 7:
            ((dataNeedWrite & (1<<7)) == (1<<7) ) ? (result = hight) : (result = low);
    }
    
    return result;
}

void write_data(uint8 dataNeedWrite)
{
    Led_1_Write( writeHightOrLow(dataNeedWrite, 0) );
    Led_2_Write( writeHightOrLow(dataNeedWrite, 1) );
    Led_3_Write( writeHightOrLow(dataNeedWrite, 2) );
    Led_4_Write( writeHightOrLow(dataNeedWrite, 3) );
    Led_5_Write( writeHightOrLow(dataNeedWrite, 4) );
    Led_6_Write( writeHightOrLow(dataNeedWrite, 5) );
    Led_7_Write( writeHightOrLow(dataNeedWrite, 6) );
    Led_8_Write( writeHightOrLow(dataNeedWrite, 7) );
}

void control_Led_Light(int location)
{
    switch(location)
    {
        case 1:
            Control_Led7_1_Write(0);
            Control_Led7_2_Write(1);
            Control_Led7_3_Write(1);
            Control_Led7_4_Write(1);
            break;
        case 2:
            Control_Led7_1_Write(1);
            Control_Led7_2_Write(0);
            Control_Led7_3_Write(1);
            Control_Led7_4_Write(1);
            break;
        case 3:
            Control_Led7_1_Write(1);
            Control_Led7_2_Write(1);
            Control_Led7_3_Write(0);
            Control_Led7_4_Write(1);
            break;
        case 4:
            Control_Led7_1_Write(1);
            Control_Led7_2_Write(1);
            Control_Led7_3_Write(1);
            Control_Led7_4_Write(0);
            break;
    }
}

void turnOffAllLed()
{
    Control_Led7_1_Write(1);
    Control_Led7_2_Write(1);
    Control_Led7_3_Write(1);
    Control_Led7_4_Write(1);
}

void scanLed(unsigned int number)
{
    uint8 nghin = number/1000;
    uint8 tram = (number%1000)/100;
    uint8 chuc = (number%100)/10;
    uint8 donvi = (number%10);
    
    // Display led 1
    control_Led_Light(4);
    write_data(code_Led7_Seg[nghin]);
     CyDelay(5);
    turnOffAllLed();
    
    // Display led 2
    control_Led_Light(3);
    write_data(code_Led7_Seg[tram]);
    CyDelay(5);
    turnOffAllLed();
    
    // Display led 3
    control_Led_Light(2);
    write_data(code_Led7_Seg[chuc]);
    CyDelay(5);
    turnOffAllLed();
    
    // Display led 4
    control_Led_Light(1);
    write_data(code_Led7_Seg[donvi]);
    CyDelay(5);    
    turnOffAllLed();
}

void checkLedLiveOrDie(uint8 location, uint8 data)
{
    control_Led_Light(location); 
    
    write_data(data);
    
    CyDelay(5);
    turnOffAllLed();
}



