#include <io.h>
#include <mega32.h>
#include <delay.h>

flash char num [10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void main(void)
    { 
      int d=5,q=0,w=0,x=0,y=0,i=0,j=0,hour,min,sec,o;
      DDRA=0xFF;
      PORTA=0x00;
      DDRC=0xFF;
      PORTC=0xFF;
      DDRB=0x00;
      PORTB=0xFF;   
      while (1)
        {    
          for(hour=0;hour<24;hour++)
             {  
                w=hour%10;
                q=hour/10;
                for(min=0;min<60;min++)
                   { 
                       y=min%10;
                       x=min/10;
                       for(sec=0;sec<60;sec++)
                        {   
                           j=sec%10;
                           i=sec/10;
                           for(o=0;o<20;o++)
                            {
                             PORTC.7=0;
                             PORTA=num[j];
                             delay_ms(d);  
                             PORTC.7=1;

                             PORTC.6=0;
                             PORTA=num[i];
                             delay_ms(d);  
                             PORTC.6=1;

                             PORTC.5=0;
                             PORTA=0x80;
                             delay_ms(d);  
                             PORTC.5=1; 

                             PORTC.4=0;
                             PORTA=num[y];
                             delay_ms(d);  
                             PORTC.4=1;

                             PORTC.3=0;
                             PORTA=num[x];
                             delay_ms(d);  
                             PORTC.3=1;

                             PORTC.2=0;
                             PORTA=0x80;
                             delay_ms(d);  
                             PORTC.2=1;

                             PORTC.1=0;
                             PORTA=num[w];
                             delay_ms(d);  
                             PORTC.1=1;

                             PORTC.0=0;
                             PORTA=num[q];
                             delay_ms(d);  
                             PORTC.0=1; 

                                }
                             }
                         }    
                    }
              } 
         }
    
