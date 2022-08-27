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
#include "ledMatrix.h"

uint8 control[] = { 0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80 };

uint8 data[] = {
                0xff,0x81,0x7e,0x7e,0x7e,0x7e,0x81,0xff,//0
                0xff,0x7b,0x7d,0x00,0x00,0x7f,0x7f,0xff,//1
                0xff,0x86,0xb6,0xb6,0xb6,0xb6,0xb0,0xff,//2
                0xff,0x66,0x66,0x66,0x66,0x98,0xff,0xff,//3
                0xef,0xe7,0xeb,0x6d,0x00,0x6f,0xef,0xff,//4
                0xff,0x78,0x7a,0x7a,0xba,0xc6,0xff,0xff,//5
                0xff,0x81,0x76,0x76,0x76,0x8d,0xff,0xff,//6
                0xff,0xff,0xfc,0xfe,0xfe,0xfe,0x00,0xff,//7
                0xff,0x89,0x76,0x76,0x76,0x89,0xff,0xff,//8
                0xff,0xb9,0x76,0x76,0x76,0x81,0xff,0xff,//9
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // turn on full
                0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF  // turn off full
                
                
};
uint8 data1[] = {0xE7,0xE7,0xE7,0xE7,0x00,0x00,0xE7,0xE7 //+
                };

/*
    Curent location --> will return hight logic, contra return low logic
*/
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

void write_data(uint8 dataNeedWrite, uint8 rowOrCloumn)
{
    switch(rowOrCloumn)
    {
        case row:
            row_matrix_0_Write( writeHightOrLow(dataNeedWrite, 0) );
            row_matrix_1_Write( writeHightOrLow(dataNeedWrite, 1) );
            row_matrix_2_Write( writeHightOrLow(dataNeedWrite, 2) );
            row_matrix_3_Write( writeHightOrLow(dataNeedWrite, 3) );
            row_matrix_4_Write( writeHightOrLow(dataNeedWrite, 4) );
            row_matrix_5_Write( writeHightOrLow(dataNeedWrite, 5) );
            row_matrix_6_Write( writeHightOrLow(dataNeedWrite, 6) );
            row_matrix_7_Write( writeHightOrLow(dataNeedWrite, 7) );
            break; 
        case column:
            col_matrix_0_Write( writeHightOrLow(dataNeedWrite, 0) );
            col_matrix_1_Write( writeHightOrLow(dataNeedWrite, 1) );
            col_matrix_2_Write( writeHightOrLow(dataNeedWrite, 2) );
            col_matrix_3_Write( writeHightOrLow(dataNeedWrite, 3) );
            col_matrix_4_Write( writeHightOrLow(dataNeedWrite, 4) );
            col_matrix_5_Write( writeHightOrLow(dataNeedWrite, 5) );
            col_matrix_6_Write( writeHightOrLow(dataNeedWrite, 6) );
            col_matrix_7_Write( writeHightOrLow(dataNeedWrite, 7) );      
    }
}


void light_character_k(int k)
{
    int n;
    
    write_data(0xFF, column);
    write_data(0x00, row);
    
    for(n=0;n<8;n++)
    {
        write_data( data1[k*8 + n], column );
        write_data( control[n], row );
        CyDelay(1);
    }
}

void light_from_0_to_9()
{
    int run , loops;
    
    write_data(0xFF, column);
    write_data(0x00, row);
    
    while(1)
    {
        for(run=0; run<10; run++)
        {
            for(loops=0; loops<500; loops++)            
                light_character_k(run);
            
            write_data(0xFF, column);
            write_data(0x00, row);
        }
    }
}


/* [] END OF FILE */
