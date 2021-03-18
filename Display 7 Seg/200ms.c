#include <16f877a.h>
#fuses xt, noprotect, nowdt
#use delay(clock=4M)
#byte display = 0x06  //PortB
#bit trisc0 = 0x87.0  //TrisC pin0
#bit portc0 = 0x07.0
#define button  pin_c0

#use fast_io(b)
#use fast_io(c)
int8 numDisp[9]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0xfc,0x47,255};

void main() {
    set_tris_b(0x00);
    display = 0x00;
    trisc0 = 1;
    
    int disp = 0x06;
    int a = 1;
    display=numDisp[0];
    while (1) {
        if (input(button)) {
         while(input(button)){}
            display=numDisp[a];
            a!=a++;
            //delay_ms(200);
            if (a>=9) a=0;
            } //else display=0x00;
    }
}
