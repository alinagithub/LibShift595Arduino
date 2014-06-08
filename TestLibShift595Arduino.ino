#include <LibShift595Arduino.h>

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
// FILE: testlibshift595arduino.ino
// VERSION: 0.1.00
// PURPOSE: Test for the LibShift595Arduino
//          using 2x cascaded 595 shift registers.
// CREATED BY: Arnaud D. LINA
// DATE: June 2014
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

#define NumberOfRegisters 2
#define LatchPin          4
#define ClockPin          3
#define DataPin           2

/* Instantiate the shift register object */
Shift595Arduino MyShiftReg(DataPin, ClockPin, LatchPin, NumberOfRegisters);

void setup() 
  {
  MyShiftReg.Setup();                  /* Init the shift register object                              */
  MyShiftReg.verbose = true;           /* Optional: enable verbose output                             */
  Serial.begin(9600);                  /* Optional: start Serial to get the verbose output            */ 
  }
  
void loop()
 { 
   MyShiftReg.auto_update    =  true;  /* Enable auto update of the register state after each action  */ 
   MyShiftReg.update_delay   =  1000;  /* Set automatic update delay of 1 second for the auto update  */
   
   MyShiftReg.OnAllRegisters();        /* Turn ON all LEDs                                            */
   MyShiftReg.Blink(5, 100);           /* Blink LEDs 5 times with 100ms period                        */
   MyShiftReg.OffAllRegisters();       /* Turn OFF all LEDs                                           */
   
   MyShiftReg.auto_update    = false;  /* Disable auto update of the register state after each action */ 
   MyShiftReg.OnSingleAllRegisters(0); /* Set ON LED 0                                                */
   MyShiftReg.OnSingleAllRegisters(1); /* Set ON LED 1                                                */
   MyShiftReg.OnSingleAllRegisters(2); /* Set ON LED 2                                                */
   MyShiftReg.Update();                /* Force register state update to turn ON LEDs 0,1, and 2      */                                
   
   MyShiftReg.auto_update    = true;   /* Enable auto update of the register state after each action  */
   MyShiftReg.update_delay   =  100;   /* Set automatic update delay of 100 msec for the auto update  */
   
   for(int ii=0; ii<32; ii++)                  /* Circular shift the registers to the left.           */
      MyShiftReg.ShiftLeftAllRegisters(true);  /* Now LEDs 1,2,3 are on, then 2,3,4...                */
                                                 
   MyShiftReg.OffRegister(0);          /* Turn OFF the first 8 LEDs                                   */
   MyShiftReg.OnRegister(1);           /* Turn ON the second 8 LEDs                                   */
   
   MyShiftReg.update_delay  =  250;    /* Set automatic update delay of 250 msec for the auto update  */
   for(int ii=0; ii<10; ii++)          /* Negate the registers states.                                */
      MyShiftReg.NegateAllRegisters(); /* Now first 8 LEDs ON and second 8 LEDs OFF, then alternate...*/
 }
