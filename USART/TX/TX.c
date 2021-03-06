#include <16f877a.h>
#fuses xt, noprotect, nowdt
#use delay (clock = 4M)
#use rs232(baud=9600, XMIT=PIN_C6, RCV=PIN_C7)

#byte SPBRG = 0x99    // Baud Rate Generator Register (0-255)
#byte RCREG = 0x18    // Read Data Register
#byte TXREG = 0x19    // Load Data Register

#bit  SYNC  = 0x98.4  // USART Mode
#bit  BRGH  = 0x98.2  // Baud Rate
#bit  SPEN  = 0x18.7  // Serial Port Enable
#bit  TXEN  = 0x98.5  // Transmit Enable
#bit  CREN  = 0x18.4  // Continuous Receive Enable
#bit  TX9   = 0x98.6  // 9-bit Transmit Enable bit
#bit  RX9   = 0x18.6  // 9-bit Recieve Enable bit
#bit  pullup = 0x81.7 //181.7
#bit  push1 = 0x06.0
#bit  push2 = 0x06.1


void main(){
   //BRGH  = 0; // Baud Rate LOW
   pullup = 0;
   while(1){
      if (!push1){
         puts("Hi");
      }
      
      if (!push2){
         puts("Low"); //Manda unicamente el array entre comillas " "
         //putc('c'); Manda indefinidamente el caracter
      }
   }
}
