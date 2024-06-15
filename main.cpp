#include "mbed.h"
InterruptIn button(BUTTON1);
volatile int int_trig = 0;

void button_fall(){
   int trig = 1;
}

// main() runs in its own thread in the OS

int main()
{
    //this is just a comment
    button.fall(&button_fall);
    while (true) {
        if (int_trig ==1){
            int_trig = 0;
            printf("buttonfall \r\n");
        }

        //button.fall(&button_interrupt);

    }
}

