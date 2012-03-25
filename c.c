//same led, both as light sensor and light emiter //
 #include<msp430.h>
void init();
void start_conversion();
unsigned int check_conversion();
void main()
{
unsigned int a=0,i;
while(1)
{
for(i=0;i<1000;i++);
init();
start_conversion();
while(check_conversion());
a=ADC10MEM;
if(a>407)
{
ADC10CTL0&=~(1<<1);
ADC10AE0=0;
P1DIR=1;
P1OUT=1;}
else 
P1OUT=0;
}
}

void init()
{
ADC10CTL0=ADC10ON|SREF_0|ADC10SHT_2;
ADC10CTL1=INCH_0|SHS_0|ADC10DIV_0|ADC10SSEL_0|CONSEQ_0;
ADC10AE0=BIT0;
ADC10CTL0|=ENC;
}

void start_conversion()
{ADC10CTL0 |= ADC10SC;}

unsigned int check_conversion()
{
return(ADC10CTL1 & ADC10BUSY);
}	
