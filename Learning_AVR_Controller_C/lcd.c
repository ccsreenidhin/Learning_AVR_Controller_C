#include<avr/io.h>
#include<util/delay.h>

void lcd_cmd(int a);
void lcd_data(char a);
void main()
{
int i;
char b[20]="WELCOME";
DDRB=0XFF;
DDRE=0XFF;
PORTB=0X00;
lcd_cmd(0X38);
lcd_cmd(0X0C);
lcd_cmd(0X06);
lcd_cmd(0X80);
for(i=0;i<7;i++)
{
lcd_data(b[i]);
}
while(1);
}


void lcd_cmd(int a)
{
PORTB&=~(1<<0);
PORTB&=~(1<<1);
PORTE=a;
PORTB|=(1<<2);
_delay_ms(2);
PORTB&=~(1<<2);
_delay_ms(2);
}

void lcd_data(char a)
{
PORTB|=(1<<0);
PORTB&=~(1<<1);
PORTE=a;
PORTB|=(1<<2);
_delay_ms(2);
PORTB&=~(1<<2);
_delay_ms(2);
}