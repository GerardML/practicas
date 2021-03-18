#include <16f877a.h>
#use delay (clock=4M)
#fuses xt,noprotect,nowdt
#use fast_IO (B)
#use STANDARD_IO (C)

#byte trisb=0x86
#byte portb=0x06

//#bit trisRc5=0x87.5
//#bit  rc5=0x07.5  //Definimos RC5 para el bit5(pin5) del registro PortC
#define rc5 61  //PIN_C5  61

void main() {
    trisb = 0x00;
    portb = 0x00;
    //trisRc5 = 1; //RC5 como entrada

   while (1) {
        if (input_c() == 040) {  //No es necesario escribir "Input(), ya que estamos leyendo el bit directamente
            portb = 0xFF;
            output_low(48);
        } else 
            portb = 0x00; 
    }
}
