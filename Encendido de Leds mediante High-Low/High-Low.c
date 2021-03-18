#include <16f876.h>
#fuses xt, nowdt
#use delay(clock = 4000000)
#use fast_io(B)
 
void main(){
   port_b_pullups(TRUE);
   set_tris_B(0b011);             //configura b0 y b1 como entrada, el resto son salidas
   output_low(pin_b2);           //se limpian las salidas y se mandan a 0
   output_low(pin_b3);
   output_low(pin_b4);
   output_low(pin_b5);
   output_low(pin_b6);
   output_low(pin_b7);
   
   while(1){
      if(input(pin_b0)==1){
         output_low(pin_b2);
      }
      else
         output_high(pin_b2);
   }
}
