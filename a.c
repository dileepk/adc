#include<msp430.h>
void start_conversion()
{
ADC10CTL0|=ADC10SC;
}

unsigned int converting()
{
return(ADC10CTL1&ADC10BUSY);
}

void main()
{
int a=0,i;
ADC10CTL0=ADC10ON|SREF_0|ADC10SHT_2;
ADC10CTL1=INCH_0|SHS_0|ADC10DIV_0|ADC10SSEL_0|CONSEQ_0;
ADC10AE0=BIT0;
ADC10CTL0|=ENC;
while(1)
{
for(i=0;i<1000;i++);
start_conversion();
while(converting());
a=ADC10MEM;
if(a>407)
{
P1DIR=0X40;
P1OUT=0X40;
}
else
{
P1OUT=0;
}
}
}
