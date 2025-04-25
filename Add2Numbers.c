#include<xc.h>
#include<PIC18F4550.h>

void main(void)
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int i,sum=0;
    for(i=0;i<=9;i++)
    {
        sum=sum + arr[i];
    }
    TRISB = 0;
    PORTB = sum;
}