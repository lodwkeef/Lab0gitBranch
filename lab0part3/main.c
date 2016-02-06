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

typedef enum stateChangeTypeEnum{
    yes, no
} stateChangeType;

    volatile stateType state;
    volatile ledDirectionType nextState = ledDown;
    volatile stateChangeType changeState = no;
    volatile stateChangeType delayState = no;
    volatile ledDirectionType ledDirection = ledDown;

//TODO: Use volatile variables that change within interrupts

int main() {
    

    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.
    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
    initTimer1();
    initTimer2();
    
    state = led1;
    T2CONbits.ON = 1;   //turn the timer on
    
    while(1){
        TMR2 = 0; //this resets the counter to 0
        
        while(delayState == no){}
        delayState = no;
       
        //TODO: Implement a state machine to create the desired functionality
            switch (state){
                case led1 :
                    if(changeState==yes){//if interrupt has flagged a button release
                        if(nextState==ledDown)state=led2;
                        else state=led3;
                        changeState=no;
                    }
                    turnOnLED(1);
                    break;
                case led2 :
                    if(changeState==yes){//if interrupt has flagged a button release
                        if(nextState==ledDown)state=led3;
                        else state=led1;
                        changeState=no;
                    }
                    turnOnLED(2);
                    break;
                case led3 :
                    if(changeState==yes){//if interrupt has flagged a button release
                        if(nextState==ledDown)state=led1;
                        else state=led2;
                        changeState=no;
                    }
                    turnOnLED(3);
                    break;
                default :
                    break;
        }
    }
    
    return 0;
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _CNInterrupt() {
    IFS1bits.CNDIF = 0;  //set the flag back down 
    PORTD; //must  read port before using
    if((PORTDbits.RD6 == NOTPRESSED)&&(changeState!=yes)){ //if the button is released
        T1CONbits.ON = 0;   //turn the timer off
        changeState = yes;
        if(ledDirection == ledUp) nextState = ledUp;
        else nextState = ledDown;
        ledDirection = ledDown;
        TMR1 = 0; //this is the counter, setting it back to 0
    }
    else if((PORTDbits.RD6 == PRESSED)&&(changeState!=yes)){   //button is pressed
        T1CONbits.ON = 1;   //start counting for swapping
    }
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interupt() {
    IFS0bits.T1IF = 0;  //sets flag back down
    T1CONbits.ON = 0;   //turn the timer off
    ledDirection = ledUp;
    TMR1 = 0; //this resets the counter to 0
    
    //LATDbits.LATD0 = ACIVE; really just send flag to main file
}

void __ISR(_TIMER_2_VECTOR, IPL7SRS) _T2Interupt() {
    IFS0bits.T2IF = 0;  //sets flag back down
    TMR2 = 0; //this resets the counter to 0
    delayState = yes;
    
    //LATDbits.LATD0 = ACIVE; really just send flag to main file
}