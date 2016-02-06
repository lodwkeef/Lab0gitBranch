/* 
 * File:   switch.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */

#include <xc.h>

#define OUTPUT 0
#define INPUT 1
#define ACTIVE 1
#define OFF 0


void initSwitch1(){
    TRISDbits.TRISD6 = INPUT;           //set the pin state to be an input
    CNPUDbits.CNPUD6 = ACTIVE;          //set the initial state of the PIN via pull up resisitor
    CNCONDbits.ON = 1;                  //Turn on the change notifications for the D register(called port D)
    CNENDbits.CNIED6 = ACTIVE;          //enable interupts by this pin(ie switch)
    IPC8bits.CNIP = 7;                  // Configure interrupt priority
    IFS1bits.CNDIF = 0;                 // Put down the flag
    IEC1bits.CNDIE = ACTIVE;           // Enable interrupt for D pins
            
            
    //TODO: Initialize switch 1
}