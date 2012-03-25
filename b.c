//led as light sensor//
#include<msp430.h>
void init();
void start_conversion();
unsigned int check_conversion();
void main()
{
int a=0,b,i;
init();
while(1)
{
for(i=0;i<1000;i++);
start_conversion();
while(1)
{
b=check_conversion();
if(b==0)
break;
}
a=ADC10MEM;
if(a>409)
{P1DIR=0X40;
P1OUT=0X40;}
else
P1OUT=0;
}
}

void init()
{
ADC10CTL0=ADC10ON|SREF_0|ADC10SHT_0;
ADC10CTL1=INCH_0|SHS_0|ADC10DIV_0|ADC10SSEL_0|CONSEQ_0;
ADC10AE0=BIT0;
ADC10CTL0 |= ENC;
}

void start_conversion()
{ADC10CTL0 |= ADC10SC;}

unsigned int check_conversion()
{
return(ADC10CTL1 & ADC10BUSY);
}	
