#include <16f877a.h>
#use delay(clock=4M)
#fuses noprotect, nowdt, xt, nobrownout

#use standard_io(b)
#byte salida=0x06
#define led pin_b0


void on(){
   int T=0;
   output_toggle(led);
   bit_clear(salida,1);
   bit_clear(salida,2);
   
      while(T<2){
         set_timer1(53035);
         while(get_timer1()>=53035)
         {
            bit_set(salida,1);
         }
         bit_set(salida,2);
         T++;
      }
}

void main(){
   setup_timer_1 (T1_INTERNAL|T1_DIV_BY_8);
   set_tris_b(0xF8);
      
   while(1){
      on();
   }

}
