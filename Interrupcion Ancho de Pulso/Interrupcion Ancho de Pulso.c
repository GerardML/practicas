#include <16f877a.h>
//#include <lcd.c>
#use delay(clock=4M)
#fuses xt,nowdt,noprotect,noput
#define use_portb_lcd TRUE
#INT_EXT

int16 TFB;
float AP;
int1 nuevopulso=0;
int1 cambio=0;

void interrupt(){
   if (cambio==0){
      set_timer1(0);
      ext_int_edge(0,H_TO_L);
      cambio=1;
   } else {
      TFB=get_timer1();
      ext_int_edge(0,L_TO_H);
      cambio=0;
      if(nuevopulso==0){
        nuevopulso=1; 
      }
   }
}

void main(){
   //lcd_init(void);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
   ext_int_edge(0,L_TO_H);
   cambio=0;
   enable_interrupts(int_ext);
   enable_interrupts(global);
   
   while(1){
      if(nuevopulso==1){
        AP = TFB*1.0;
        //printf(lcd_putc,"\nPulso = %6.1fuS", AP);
      }
      nuevopulso=0;
   }

}
