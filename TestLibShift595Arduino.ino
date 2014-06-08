#include <LibShift595Arduino.h>

Shift595Arduino ShiftReg(2, 3, 4, 2);

void setup() 
  {
  //set pins to output because they are addressed in the main loop
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  }
  
void loop()
 { 
   // Set all Leds on
   ShiftReg.OnAllRegisters();
   ShiftReg.Update();
   delay(1000);
   
   // Set all Leds off
   ShiftReg.OffAllRegisters();
   ShiftReg.Update();
   delay(1000);
   
   // Scan all Leds
   for(int ii=0; ii<16; ii++)
     {
     ShiftReg.OnSingleOnlyAllRegisters(ii);
     ShiftReg.Update();
     delay(200);
     }
     
   // Set all Leds off
   ShiftReg.OffAllRegisters();
   ShiftReg.Update();
   delay(1000);
   
   // Set led 1 and 2 on
   ShiftReg.OnSingleEachRegisters(1);
   ShiftReg.OnSingleEachRegisters(2);
   ShiftReg.Update();
   delay(1000);
   
   // Translate the pattern on the left
   for(int ii=0; ii<33; ii++)
   {
     ShiftReg.ShiftLeftRegister(true, 0);
     ShiftReg.ShiftLeftRegister(true, 1);
     ShiftReg.Update();
     delay(100);
   }
   delay(100);
   
   // Translate the pattern on the right
   for(int ii=0; ii<33; ii++)
   {
     ShiftReg.ShiftRightRegister(true, 0);
     ShiftReg.ShiftRightRegister(true, 1);
     ShiftReg.Update();
     delay(100);
   }
 }
