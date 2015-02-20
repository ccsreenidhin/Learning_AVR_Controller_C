#include<util/delay.h>

#define lcd_port PORTB
#define lcd_ddir DDRB

void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_str(unsigned char *);

void lcd_init()
{
   lcd_ddir=0xff;
   
   lcd_port=(0x30|0x04);   //Sending 3
   _delay_ms(2);           //Delay
   lcd_port=(0x30&0xF0);   //Clear Enable Pin
   _delay_ms(2);

   lcd_port=(0x30|0x04);   //Sending 3
   _delay_ms(2);           //Delay
   lcd_port=(0x30&0xF0);   //Clear Enable Pin
   _delay_ms(2);

   lcd_port=(0x30|0x04);   //Sending 3
   _delay_ms(2);           //Delay
   lcd_port=(0x30&0xF0);   //Clear Enable Pin
   _delay_ms(2);
   
   lcd_port=(0x20|0x04);   //Sending 2 to initialise LCD 4-bit mode
   _delay_ms(2);           //Delay
   lcd_port=(0x20&0xF0);   //Clear Enable Pin
   _delay_ms(2);
   
   lcd_cmd(0x28);
   lcd_cmd(0x01);
   lcd_cmd(0x06);
   lcd_cmd(0x0C);
   lcd_cmd(0x80);
}

void lcd_cmd(unsigned char x)
{
   unsigned char t;
   t=x;
   
   t=((t&0xf0)|(0x04));
   lcd_port=t;
   _delay_ms(2);
   t=(t&0xf0);
   lcd_port=t;
   _delay_ms(2);
   
   x=(((x&0x0f)<<4)|0x04);
   lcd_port=x;
   _delay_ms(2);
   x=(x&0xf0);
   lcd_port=x;
   _delay_ms(2);
}

void lcd_data(unsigned char x)
{
   unsigned char t;
   t=x;
   
   t=((t&0xf0)|(0x05));
   lcd_port=t;
   _delay_ms(2);
   t=(t&0xf1);
   lcd_port=t;
   _delay_ms(2);
   
   x=(((x&0x0f)<<4)|0x05);
   lcd_port=x;
   _delay_ms(2);
   x=(x&0xf1);
   lcd_port=x;
   _delay_ms(2);
}

void lcd_str(unsigned char *s)
{
   while(*s)
      lcd_data(*s++);
}
