/* 
 * File:   main.c
 * Author: gvanhoy
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1
#define ACTIVE 1
#define OFF 0
#define PRESSED 0
#define NOTPRESSED 1

//TODO: Define states of the state machine 
typedef enum stateTypeEnum{
    led1, led2, led3, wait, wait2, debouncePress, debounceRelease, debounceRelease2
} stateType;

typedef enum ledDirectionTypeEnum{
    ledUp, ledDown
} ledDirectionType;

    volatile stateType state;
    volatile ledDirectionType ledDirection = ledUp;

//TODO: Use volatile variables that change within interrupts

int main() {
    

    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.
    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
    //initTimer2();
    initTimer1();
    
    state = led1;
    
    while(1){

       
        //TODO: Implement a state machine to create the desired functionality
        if(0){
            switch (state){
                case led1 :
                    //something
                    break;
                case led2 :
                    //something
                    break;
                case led3 :
                    //something
                    break;
                case wait :
                    //something
                    break;
                case wait2 :
                    //something
                    break;
                case debouncePress :
                    //something
                    break;
                case debounceRelease :
                    //something
                    break;
                case debounceRelease2 :
                    //something
                    break;
                default :
                    break;
            }
        }
        else{
            switch (state){
                case led1 :
                    turnOnLED(1);
                    break;
                case led2 :
                    turnOnLED(2);
                    break;
                case led3 :
                    turnOnLED(3);
                    break;
                default :
                    break;
            }
        }
        
    }
    
    return 0;
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _CNINterrupt() {
    IFS1bits.CNDIF = 0;  //set the flag back down
    //set the interrupt program
    PORTD;
    if(PORTDbits.RD6 == NOTPRESSED){
        if(ledDirection==ledUp)       {//if timer is less than 1 sec continue direction
            //add stuff
        }
    }
    else{
        //start counting for swapping
    }
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interupt() {
    IFS0bits.T1IF = 0;
    
    if(state==led1) state=led2;
    else if(state==led2) state=led3;
    else if (state==led3) state=led1;
    else state=led1;
    
    //LATDbits.LATD0 = ACIVE; really just send flag to main file
}