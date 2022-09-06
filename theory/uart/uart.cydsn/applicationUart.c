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
#include "project.h"
#include <stdio.h>    
#include "applicationUart.h"

void printNumber(int number)
{
    char strings[30];
    
    sprintf(strings, "%d\n", number);
    uart_UartPutString(strings);    
} 

void printNumberIncrement()
{
    char strings[30];
    static int number = 10;
    
    number++;
    if(number > 15)
        number = 5;   
    
    sprintf(strings, "%d\n", number);
    uart_UartPutString(strings); 
}

void receive_After_Transmit_Char_Type()
{   
    static int i=0;
    char txData[] = "\nPlear enter a character: ";
    
    if( i==0 ) 
        uart_UartPutString( txData );
    
    uint32 rxData;     
       
    rxData = uart_UartGetChar();    // store received characters in temporary variable     
   
   if( rxData )  // make sure data is non-zero
    {        
        uart_UartPutString("\nResult: ");
        uart_UartPutChar( rxData ); // echo characters in terminal window 
        i=0;
        return;
    }
    
    i=1;    
        
    // Handle received characters
}

/*
//error receive
void receive_After_Transmit_String()
{
    static int i=0; 
    int j;    
    char txData[] = "\nPlear enter a string: ";
    char txDataString[20];
    uint32 txDataReceive;
    
    if(i==0)
        uart_UartPutString( txData );
        
    txDataReceive = uart_UartGetChar();  
    
    if(txDataReceive)
    {
        sprintf(txDataString, "%lu", txDataReceive);        
        uart_UartPutString( uart_UartGetChar()  );   
    }
    
}
*/

/* [] END OF FILE */
