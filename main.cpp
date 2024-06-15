#include "mbed.h"
InterruptIn button(BUTTON1);

void button_interrupt(){
    printf("button is pressed");
}

// main() runs in its own thread in the OS

int main()
{
    //this is just a comment
    while (true) {
        button.fall(&button_interrupt);

    }
}

