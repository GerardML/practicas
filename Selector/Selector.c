#include <16f877a.h>
#use delay(clock=4000000)
#fuses xt,nowdt,noprotect,noput
#use fast_io (a)
#use fast_io (b)
#byte entrada=0x05     //Porta=llantas
#byte salida=0x06       //ultrb=
////////////////////////////////////ENTRADAS////////////////////////////////////
//////1 BOTON COMIENZO//////////
//////4 SENSORES INFRAROJOS/////
//////5 SENSORES ULTRASONICOS///
////////////////////////////////////SALIDAS/////////////////////////////////////
//////4 CONTROLADORES PARA 2 MOTORES///////
////////////////////////////////////////////////////////////////////////////////
//ASIGNACIÓN DE PINES DE ENTRADA: RB0 -> RB7 + D7, D6, D5, D4
//ASIGNACIÓN DE PINES  DE SALIDA: RA0 -> RA3

///////////Asignación de etiquetas/nombres a los comandos Hexa//////////////////   
int calibrar=6,iniciar=1,medir=2;
int c=3,i=4,m=5;
int menus=0,seleccion=0;

#INT_EXT  //Interrupción por B0

ext_isr(){
   salida=0xFF;
   //output_toggle(pin_b1);
}


void menu(){
   switch(menus){
         case 1:{
            //salida=calibrar;
            bit_set(salida,calibrar);
            bit_clear(salida,iniciar);
            bit_clear(salida,medir);
         break;
         }
         case 2:{
            //salida=iniciar;
            bit_set(salida,iniciar);
            bit_clear(salida,calibrar);
            bit_clear(salida,medir);
         break;
         }
         case 3:{
            //salida=medir;
            bit_set(salida,medir);
            bit_clear(salida,calibrar);
            bit_clear(salida,iniciar);
         break;
         }
      }
}

void seleccion(){
      switch(menus){
         case 1:{
            bit_set(salida,c);
            bit_clear(salida,i);
            bit_clear(salida,m);
         break;
         }
         case 2:{
            bit_set(salida,i);
            bit_clear(salida,c);
            bit_clear(salida,m);
         break;
         }
         case 3:{
            bit_set(salida,m);
            bit_clear(salida,i);
            bit_clear(salida,c);
         break;
         }
      }
}

void main(){
   enable_interrupts(int_ext);
   ext_int_edge(L_TO_H);
   enable_interrupts(GLOBAL);
   set_tris_a(0x03);
   set_tris_b(0x81);
   salida=0x00;
   
   for(;;){
      if(input(pin_a0)==1){
         while(input(pin_a0)==1)
         {}
         menus++;
         if(menus>3){
            menus=1;
         }
         menu();
      }
      if(input(pin_a1)==1){
         while(input(pin_a1)==1)
         {}
         seleccion();
      }
      
   }
}


