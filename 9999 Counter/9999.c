#include <16f877a.h>
#use delay(clock=4M)
#FUSES xt,noprotect,nowdt
#use fast_io(B)
#use fast_io(C)
#byte portb   = 0x06
#byte portc   = 0x07
#byte display = 0x08
#bit  pulse   = 0x07.0
#bit  uni     = 0x07.1
#bit  dec     = 0x07.2
#bit  cen     = 0x07.3
#bit  uMill   = 0x07.4

int8 numDisp[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0xfc,0x47,255,0x67};
int c=0,c2=0,c3=0,c4=0;

void conteo();

#int_ext

void ext(){
   while(!input(pin_b0)){
      conteo();
   }
   //portb=0x00;
}

void conteo(){

   uMill = 0;
   cen   = 1;
   dec   = 1;
   uni   = 1;
   display=numDisp[c4];
   delay_ms(1);
  
   uMill = 1;
   cen   = 0;
   dec   = 1;
   uni   = 1;
   display=numDisp[c3];
   delay_ms(1);
   
   uMill = 1;
   cen   = 1;
   dec   = 0;
   uni   = 1;
   display=numDisp[c];
   delay_ms(1);
   
   uMill = 1;
   cen   = 1;
   dec   = 1;
   uni   = 0;
   display=numDisp[c2];
   delay_ms(1);
   
   delay_ms(40);
}


void main(){
   enable_interrupts(int_ext);
   enable_interrupts(global);
   ext_int_edge(H_TO_L);
   int globa=0;
   int globa2=0;
   int globa3=0;
   int globa4=0;
   
   set_tris_b(0x01);
   set_tris_c(0xE1);
   set_tris_d(0x00);
   display=numDisp[c];
   portb=0x00;
   
   for(;;){
         for(globa4=0;globa4<=9;globa4++){
                  
                  c3=0;
                  
                  for(globa3=0;globa3<=9;globa3++){
                        
                        c=0;
                        
                        for(globa=0;globa<=9;globa++){
                           
                           c2=0;
                           
                           for(globa2=0;globa2<=9;globa2++){
                           
                              conteo();
                              c2++;
                           }
                           c++;
                        }
                        c3++;
                  }
                  c4++;
         }
         c4=0;
      }
}
