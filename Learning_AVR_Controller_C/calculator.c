#include<avr/io.h>
#include<util/delay.h>
#include"avr_lcdz.c"
char keypad();
void main()
{
char x,j[20];
char k,op,a[15],b[15],q[14],o[13];
  int i,n,m,p;
lcd_init();
 while(1)
   {
   lcd_cmd(0x01);
   i=0;
   a[0]='\0';
   b[0]='\0';
   while(1)
   {
      x=keypad();
      lcd_data(x);
      if(x=='+'||x=='-'||x=='*'||x=='/')
      break;
      a[i]=x;
      i++;
   }
   a[i]='\0';
   
   switch(x)
   {
      case '+':
	           n=atoi(a);
               i=0;
               while(1)
               {              
                  k=keypad();
                  lcd_data(k);
                  if(k=='=')
                  break;
                  b[i]=k;
                  i++;
               }
               b[i]='\0';
			   
               m=atoi(b);
               p=m+n;
               sprintf(j,"%d",p);
			   lcd_str(j);
               _delay_ms(30);
               break;
      case '-':
      
               n=atoi(a);
               i=0;
               while(1)
               {
               
                  x=keypad();
                  lcd_data(x);
                  if(x=='=')
                  break;
                  b[i]=x;
                  i++;
               }
               b[i]='\0';
               m=atoi(b);
               p=n-m;
               sprintf(j,"%d",p);
			   lcd_str(j);
               _delay_ms(30);
              break;
       case '*':
      
               n=atoi(a);
               i=0;
               while(1)
               {
               
                  x=keypad();
                  lcd_data(x);
                  if(x=='=')
                  break;
                  b[i]=x;
                  i++;
               }
               b[i]='\0';
               m=atoi(b);
               p=m*n;
               sprintf(j,"%d",p);
			   lcd_str(j);
               _delay_ms(30);
              break;
      case '/':
      
               n=atoi(a);
               i=0;
               while(1)
               {
               
                  x=keypad();
                  lcd_data(x);
                  if(x=='=')
                  break;
                  b[i]=x;
                  i++;
               }
               b[i]='\0';
               m=atoi(b);
               p=n/m;
               sprintf(j,"%d",p);
			   lcd_str(j);
               _delay_ms(30);
              break;
 }
 while(keypad()!='c');
   }
while(1);
}

char keypad()
{
char x;
DDRF=0X0F;
   
   while(1)
   {
   PORTF|=(1<<0);
   PORTF&=~(1<<1);
   PORTF&=~(1<<2);
   PORTF&=~(1<<3);
   if((PINF&0X10)==0X10)
   {
   while((PINF&0X10)==0x10);
   x='0';
   break;
   }
   else  if((PINF&0X20)==0X20)
   {
     while((PINF&0X20)==0x20);
   x='4';
   break;
   }
   else if((PINF&0X40)==0X40)
   {
    while((PINF&0X40)==0x40);
   x='8';
   break;
   }
   else  if((PINF&0X80)==0X80)
   {
     while((PINF&0X80)==0x80);
   x='*';
   break;
   
   }
 
   PORTF&=~(1<<0);
   PORTF|=(1<<1);
   PORTF&=~(1<<2);
   PORTF&=~(1<<3);
 
   if((PINF&0X10)==0X10)
   {
    while((PINF&0X10)==0x10);
   x='1';
   break;
   }
   else if((PINF&0X20)==0X20)
   {
       while((PINF&0X20)==0x20);
   x='5';
   break;
   }
   else  if((PINF&0X40)==0X40)
   {
       while((PINF&0X40)==0x40);
   x='9';
   break;
   }
   else if((PINF&0X80)==0X80)
   {
       while((PINF&0X80)==0x80);
   x='/';
   break;
   }
     PORTF&=~(1<<0);
     PORTF&=~(1<<1);
     PORTF|=(1<<2);
	 PORTF&=~(1<<3);
  if((PINF&0X10)==0X10)
   {
       while((PINF&0X10)==0x10);
   x='2';
   break;
   }
   else if((PINF&0X20)==0X20)
   {
       while((PINF&0X20)==0x20);
   x='6';
   break;
   }
   else if((PINF&0X40)==0X40)
   {
       while((PINF&0X40)==0x40);
   x='+';
   break;
   }
   else if((PINF&0X80)==0X80)
   {
       while((PINF&0X80)==0x80);
   x='c';
   break;
   }
  
     PORTF&=~(1<<0);
     PORTF&=~(1<<1);
     PORTF&=~(1<<2);
	 PORTF|=(1<<3);
    if((PINF&0X10)==0X10)
   {
       while((PINF&0X10)==0x10);
   x='3';
   break;
   }
   else if((PINF&0X20)==0X20)
   {
       while((PINF&0X20)==0x20);
   x='7';
   break;
   }
   else  if((PINF&0X40)==0X40)
   {
       while((PINF&0X40)==0x40);
   x='-';
   break;
   }
   else if((PINF&0X80)==0X80)
   {
       while((PINF&0X80)==0x80);
   x='=';
   break;
   }
   }
 return x;
 
 }
   
