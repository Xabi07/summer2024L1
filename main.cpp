#include "mbed.h"
#include <cstdio>
InterruptIn button(BUTTON1);
volatile int int_trig = 0;

/*This program executes an interrupt, on Button press printf send "Buttonfall" to the screen. Previous versions 
of the code would not work with printf inside the ISR routine. By adding a volatile variable name to the int_trig variable we 
are able to execute the function "void button_fall" whenever the BUTTON1 is pressed. When BUTTON1 is pressed int_flag is then set to true or 1
the code inside the main function executes, before the code prints "buttonfall" the int_trig variable is cleared
waiting for another interrupt to occur and the programs loops over using the if statement.

*/
void button_fall(){
   int_trig = 1;
}

// main() runs in its own thread in the OS

int main()
{
    //this is just a comment
    button.fall(&button_fall);
    while (true) {
        if (int_trig == 1){
            int_trig = 0;
            printf("buttonfall \r\n");
        }

        //button.fall(&button_interrupt);

    }
}

