#include <16f877a.h>
#use delay(clock=4M)
#fuses noprotect, nowdt, xt, nobrownout

#use standard_io(b)
#byte portb=0x06
#define trig pin_b1
#define echo pin_b0
#define led pin_b7
#define high output_high
#define low output_low

float T,D;

void main(){
   set_tris_b(0x01);
   portb=0x00;
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
   
   while(1){
      high(trig);
      delay_us(10);
      low(trig);
      while(!input(echo))
      {}
      set_timer1(0);
      while(input(echo))
      {}
      T=get_timer1();
      D=(T/2)/(29.15);
      if (D<10){
      high(led);
      }
      else{
      low(led);
      }
   }

}
