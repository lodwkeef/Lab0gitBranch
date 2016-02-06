/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    TMR1 = 0; //this is the counter
    T1CONbits.TCKPS = 3; //set the ticking rate, this is a prescaller value
    PR1 = 39062; //register to compare against, basically the new clock tick
    T1CONbits.ON = 1;   //turn the timer on
    IPC1bits.T1IP = 7;  //this is the priority, must match the ISR
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    
    
}

initTimer2(){
    //TODO: Initialize Timer 2.
}

delayMs(int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
}