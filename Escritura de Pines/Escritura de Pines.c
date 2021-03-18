#include <16F876.h>
#USE DELAY(CLOCK = 4000000)
#FUSES XT,NOWDT,NOPROTECT,NOPUT
#USE fast_IO (B)
#byte portb=0x06
byte const display[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

main(){
byte ud=0,dec=0;
set_tris_b(0x00);
set_tris_a(0x00);

//output_b(0X99);
portb=0x00;
//bit_set(portb,0);
//output_high(pin_b0);


for(;;){
   bit_set(portb,1);
   bit_set(portb,3);
   bit_set(portb,5);
   bit_set(portb,7);
   delay_ms(500);
   portb=0x00;
   bit_set(portb,0);
   bit_set(portb,2);
   bit_set(portb,4);
   bit_set(portb,6);
   delay_ms(500);
   portb=0x00;
   }
}
