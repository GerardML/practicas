#include <16f877a.h>
#fuses xt, noprotect, nowdt
#use delay (clock = 4M)
#use rs232(baud=9600, XMIT=PIN_C6, RCV=PIN_C7)


#byte Trisb = 0x86
#byte Portb = 0x06

#bit  BRGH  = 0x98.2  // Baud Rate
#byte RCREG = 0x18    // Read Data Register
#byte TXREG = 0x19    // Load Data Register

void main(){
   Trisb = 0x00;
   Portb = 0x00;
   
   char c[5];
   int1 abe[2][2];
   int8 ebe;
   int words[2][5] = {
      
      {'H', 'i'},
      {'L', 'o', 'w'}
      
      };
   
   do{
      //gets(c);
         
         int r;
         int b;
         
         if (sizeof(abe) == sizeof(ebe)){
            portb=0xff;
            delay_ms(1000);
         }
         
         for(r=0; r<2; r++){
            
            int f;
            for(f=1; f<6; f++){
               
               if (words[r][f] == c[f]){
                  b=255;
                  Portb = b;
                  //delay_ms(500);
               }
               else{
                  b=0;
                  Portb = b;
                  //delay_ms(500);
                  
               }
            }
         
         }
         
   }
   while(1);
}
