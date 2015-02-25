#include<avr/io.h>
#include<util/delay.h>
#include"avr_lcdz.c"

void main()
{
int i,a=0x00;
char b[10]="welcome",c[10];
lcd_init();

for(i=0;i<7;i++)
{
EEAR=a;
while(EECR&0x02!=0X02);
EEDR=b[i];
EECR|=0X04;
EECR|=0X02;
a=a++;
_delay_ms(30);
}
a=0x00;
for(i=0;i<7;i++)
{
EEAR=a;
while(EECR&0x02!=0X02);
EECR|=0X01;
c[i]=EEDR;
a=a++;
}
lcd_str(c);

while(1);
}
