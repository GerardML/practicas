#include <16F876.h>
#use delay(clock = 4000000)
//#fuses xt,nowdt,noprotect,noput

#use fast_io (a)
#use fast_io (b)
byte const display[10] = {0x40,0x79,0x24,0x30,0x99,0x12,0x02,0x38,0x00,0x18};

void main(){
   byte uni=0, dec=0, inc=0;
   set_tris_a(0x00);
   set_tris_b(0x00);
   output_b(0);
   
   while(1){
      for(dec=0; dec<10; dec++){
         for(uni=0; uni<10; uni++){
         
               output_a(0x02);
               output_b(display[uni]);
            
            delay_ms(50);
            
            
               output_a(0x01);
               output_b(display[dec]);
            
            delay_ms(50);
         }
      }
   }
   //while(dec<10);
   //output_a(0x03);
}
