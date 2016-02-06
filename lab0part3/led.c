/* 
 * File:   led.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"

#define OUTPUT 0
#define INPUT 1
#define ACTIVE 1
#define OFF 0

void initLEDs(){
    TRISDbits.TRISD0 = OUTPUT; //Change LED Pins to be outputs
    TRISDbits.TRISD1 = OUTPUT;
    TRISDbits.TRISD2 = OUTPUT;
    LATDbits.LATD0 = OFF; //Set the LED pins to a certain state(initially off, 0)
    LATDbits.LATD1 = OFF;
    LATDbits.LATD2 = OFF;
    //TODO: Initialize LEDs
}

void turnOnLED(int led){
    
    if(led==1){
        LATDbits.LATD0 = ACTIVE;
        LATDbits.LATD1 = OFF;
        LATDbits.LATD2 = OFF;
    }
    else if (led==2){
        LATDbits.LATD0 = OFF;
        LATDbits.LATD1 = ACTIVE;
        LATDbits.LATD2 = OFF;
    }
    else if (led==3){
        LATDbits.LATD0 = OFF;
        LATDbits.LATD1 = OFF;
        LATDbits.LATD2 = ACTIVE;
    }
    else {}
    //TODO: You may choose to write this function
    // as a matter of convenience
    
}