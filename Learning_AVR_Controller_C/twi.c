#include<avr/io.h>
#include<util/delay.h>
void twi_init();
void twi_start();
void twi_stop();
void twi_write(unsigned char);
unsigned int twi_read(int);


void main()
{
twi_init();
twi_start();
twi_write(0xd0);
twi_write(0x00);
twi_write(0x12);
twi_write(0x10);
twi_write(0x03);
twi_write(0x01);
twi_write(0x01);
twi_write(0x02);
twi_write(0x15);
twi_stop();
while(1);
}




void twi_init()
{
TWBR=0X48;
//TWCR=(1<<TWEN);
}

void twi_start()
{
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
while(!TWCR&(1<<TWINT));
}


void twi_stop()
{
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void twi_write(unsigned char v)
{
TWDR=v;
TWCR=(1<<TWEN)|(1<<TWINT);
while(!TWCR&(1<<TWINT));
}

unsigned int twi_read(int p)
{
TWCR=(1<<TWEN)|(1<<TWINT);
return(TWDR);
}

