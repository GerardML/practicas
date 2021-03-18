#Include <16f876.h>
#fuses xt,nowdt
#use delay (clock = 4000000)
#byte TrisB = 0X86
#byte PortB = 0X06
#byte Option_reg = 0x81

void main() {
   bit_clear(Option_reg,7);
   bit_set(TrisB,0);               //"set" para habilitar como entrada el pin 0, el "tris," hace la funcion de indicar el pin
   bit_clear(TrisB,1);             //"clear" habilita el pin 1 como salida y limpia/manda 0 al pin 1
   bit_clear(PortB,1);
   bit_clear(TrisB,2);
   bit_clear(PortB,2);
   bit_clear(TrisB,3);
   bit_clear(PortB,3);
   bit_clear(TrisB,4);
   bit_clear(PortB,4);
   
   while(1){
      if (bit_test(PortB,0)==1){
         //bit_clear(PortB,1);
         //PortB = 0b00000;         //Sentencia Binaria
         //PortB = 0x00;            //Sentencia Hexa
         PortB = 000;             //Sentencia Octal
         //PortB = 0;          //Sentencia Decimal
      }
      else{
         //bit_set(PortB,1);
         //PortB = 0b11110;            //Sentencia Binaria
         //PortB = 0x1E;            //Sentencia Hexa
         //PortB = 036;             //Sentencia Octal
         PortB = 30;             //Sentencia Decimal
      }
   }
}
