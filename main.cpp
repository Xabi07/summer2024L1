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
void button_fall(){     //button_fall function call
   int_trig = 1;        //sets trig = 1
}

void button_rise(){     //button_rise function call
    int_trig = 2;       //sets trig = 2
}
// main() runs in its own thread in the OS

int main()
{
    //this is just a comment
    button.fall(&button_fall);  //when button is pressed goes from high to low state makes call to the button_fall function
    button.rise(&button_rise);  //when button is depressed goes from high to low state makes call to the button_rise function
    while (true) {
        if (int_trig == 1){     //if trig = 1, set trig = 0 and print buttonfall
            int_trig = 0;
            printf("buttonfall \r\n");
        }
        if (int_trig == 2){     //if trig = 2, print buttonrise and set trig = 0
            printf("buttonrise \r\n");
            int_trig = 0;

        }
        //int_trig = 0;

        //button.fall(&button_interrupt);

    }
}

