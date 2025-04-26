#include <pic18f4550.h>		/* Contains PIC18F4550 specifications */

#define Buzzer LATAbits.LATA5  		/* Define buzzer pin */
unsigned int count = 0;

void interrupt Timer1_ISR()
{
    if(TMR1IF==1)
    {
    //TMR1=0xCF2C;
    TMR1L = 0x20;
    TMR1H = 0xD1;
    count ++;

    if (count >= 1000) //measure upto 1000 ms i.e. 1 seconds
    {
        Buzzer = ~Buzzer;  	/* Toggle buzzer pin  */
        count = 0;  //reset count
    }
    TMR1IF = 0; //timer1 overflow flag to 0
    }
}


void main()
{
    TRISB=0;  			/* Set as output port */
    TRISAbits.TRISA5 = 0;       //set buzzer pin RA5 as output
    GIE=1;                      /* Enable Global Interrupt */
    PEIE=1;                     /* Enable Peripheral Interrupt */
    TMR1IE=1;                   /* Enable Timer1 Overflow Interrupt */
    TMR1IF=0;

    /* Enable 16-bit TMR1 register,no pre-scale,internal clock, timer OFF */
    T1CON=0x80;         /*1:8 prescale*/
    TMR1L = 0x20;
    TMR1H = 0xD1;
    TMR1ON=1;		/* Turn ON Timer1 */

    while(1);
}

