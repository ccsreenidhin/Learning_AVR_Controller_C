#include<avr/io.h>
#include<util/delay.h>
#include"avr_lcdz.c"
void main()
{
int h=0,g=0,i,l=0;
char n[4],p[4];
lcd_init();
_delay_ms(10);
ADMUX=0X21;
ADCSRA=0X83;
while(1)
{
ADCSRA|=0X40;
while((ADCSRA&0X10)!=0x10);
ADCSRA|=0X10;
g=ADCL;
h=ADCH;
if(l!=h)
{
	l=h;
	sprintf(n,"%d",(h<<2)+(g>>6));
	lcd_cmd(0X01);
	for(i=0;n[i]!='\0';i++)
	{
	lcd_data(n[i]);
	}
}
}
}