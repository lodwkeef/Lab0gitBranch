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
    TRISDbits.TRISD6 = INPUT;   //set the pin state to be an input
    CNPUDbits.CNPUD6 = ACTIVE;       //set the initial state of the PIN via pull up resisitor
    CNCONDbits.ON;      //Turn on the change notifications for the D register(called port D)
    CNENDbits.CNIED6 = ACTIVE;       //enable interupts by this pin(ie switch)
    //TODO: Initialize switch 1
}