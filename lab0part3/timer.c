/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>

void initTimer1(){
    //Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    TMR1 = 0; //this is the counter
    T1CONbits.TCKPS = 3; //set the ticking rate, this is a prescaller value
    PR1 = 39062; //register to compare against, basically the new clock tick
    T1CONbits.ON = 1;   //turn the timer on
    IPC1bits.T1IP = 7;  //this is the priority, must match the ISR
    IFS0bits.T1IF = 0;  //
    IEC0bits.T1IE = 1;  //
    T1CONbits.ON = 0;   //turn the timer off
    
    
}

initTimer2(){
    TMR2 = 0; //this is the counter
    T2CONbits.TCKPS = 3; //set the ticking rate, this is a prescaller value
    PR2 = 2000; //register to compare against, basically the new clock tick~50nms
    T2CONbits.ON = 1;   //turn the timer on
    IPC2bits.T2IP = 7;  //this is the priority, must match the ISR
    IFS0bits.T2IF = 0;  //
    IEC0bits.T2IE = 1;  //
    T2CONbits.ON = 0;   //turn the timer off
    //Initialize Timer 2.
}

delayMs(int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
}