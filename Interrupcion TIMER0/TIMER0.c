#include <16f877a.h>
#use delay(clock=4000000)
#fuses xt,nowdt,noprotect,noput
#use standard_io (b)
#byte salida=0x06       //ultrb=

#INT_TIMER0  //Interrupción por B0

void interrupcion(){
   output_toggle(pin_b1);
   set_timer0(6);
}


void main(){
   setup_timer_0 (rtcc_div_2 | rtcc_internal);
   enable_interrupts(int_timer0);
   enable_interrupts(GLOBAL);
   set_timer0(6);
   set_tris_b(0x81);
   salida=0x00;
   
   for(;;){
      salida=(0xFF);
      delay_ms(730);
      salida=(0x00);
      delay_ms(730);
   }
}


