#include <16f877a.h>
#use delay (clock=4M)
#fuses xt, nowdt, noprotect

#use fast_io(B)
#use fast_io(C)

#byte portb = 0x06
#byte trisb = 0x86

#bit pulse = 0x07.0
#bit tris0c = 0x87.0

void main (){
   set_tris_b(0x00);
   portb=0x00;
   tris0c=1;
   int inc[8]= {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
   int inicial=0,a,b=0;
   
      while(1){
         //Izq a Der
         while((input(pulse)==1)&&(inicial==0)){
            a=0;
            inicial=1;
            while(input(pulse)==1){}
         }
         //Der a Izq
         while((input(pulse)==1)&&(inicial==1)){
            a=1;
            inicial=0;
            while(input(pulse)==1){}
         }
        
        if(a==0){
         portb=inc[b];
         b++;
         if(b==8) b=0;
        }
        
        if(a==1){
         portb=inc[b];
         b--;
         if(b==-1) b=7;
        }
      }
}
