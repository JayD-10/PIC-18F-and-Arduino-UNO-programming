/*Baud Rate GENERATION
 * n    => required baudrate
 * BRGH     =   0
 * SPBRG    =   (Fosc / (64 * n)) -1
 * For 9600 baudrate, SPBRG ~=77
 */

#include<PIC18F4550.h>
#include<stdio.h>
#define Fosc 48000000UL

void InitUART(unsigned int baudrate)
{
  TRISCbits.RC6 = 0;                        //TX pin set as output
  TRISCbits.RC7 = 1;                        //RX pin set as input

  SPBRG = (unsigned char)(((Fosc /64)/baudrate)-1);
  BAUDCON = 0b00000000;                     //Non-inverted data; 8-bit baudrate generator

  TXSTA = 0b00100000;                       //Asynchronous 8-bit; Transmit enabled; Low speed baudrate select
  RCSTA = 0b10010000;                       //Serial port enabled; 8-bit data; single receive enabled
}

void SendChar(unsigned char data)
{
    while(TXSTAbits.TRMT == 0);             //Wait while transmit register is empty

    TXREG = data;                           //Transmit data
}

void putch(unsigned char data)
{
    SendChar(data);
}

unsigned char GetChar(void)
{
    while(!PIR1bits.RCIF);                  //Wait till receive buffer becomes full
    return RCREG;                           //Returned received data
}


void main(void)
{
    InitUART(9600);

    printf("\r\nHello MicroPIC-18F: Enter any Key from Keyboard\r\n");

    while(1)
    {
        printf("%c! ",GetChar());             //Receive character from PC and echo back
    }

 while(1);
}

