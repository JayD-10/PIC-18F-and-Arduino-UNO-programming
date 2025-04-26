#include <xc.h>
#include <PIC18F4550.h>


void delay(unsigned int time)
{
    unsigned int i,j;
    for(i=0;i<time;i++)
        for(j=0;j<5000;j++);
}

void main(void)
{
   TRISC = 0x00;
   LATC = 0xFF;

   while(1)                                //Loop forever;
   {
       LATC =  0x01;
       delay(10);
       LATC =  0x02;
       delay(10);
       LATC =  0x04;
       delay(10);
       LATC =  0x20;
       delay(10);
   }
}


