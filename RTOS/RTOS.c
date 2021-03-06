#include <16f877.h>
#use delay(clock=4M)
#fuses xt, noprotect, nowdt
#use RTOS(timer=0, minor_cycle=10ms)

#use standard_io(b)

#byte portb = 0x06

#task(rate=500ms, max=10ms)
void task1(){
   output_toggle(pin_b0);
}

#task(rate=30ms, max=10ms)
void task2(){
   output_toggle(pin_b1);
}

#task(rate=1500ms, max=10ms)
void task3(){
   output_toggle(pin_b2);
   //rtos_terminate( );
}

void main(){
   set_tris_b(0x00);
   portb=0xFF;
   RTOS_run();
}
