//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
// FILE: libshift595arduino.h
// VERSION: 0.1.00
// PURPOSE: Package for 595 shift register
// CREATED BY: Arnaud D. LINA
// DATE: June 2014
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

#ifndef libcomarduino_h
#define libcomarduino_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define LIBCOMARDUINO_LIB_VERSION "0.1.00"


class Shift595Arduino
{
public:
   Shift595Arduino(int datapin, int clockpin, int latchpin, int nbregisters=1);
   ~Shift595Arduino() {delete[] registerData;};
   
   boolean OffRegister(int reg_index);
   boolean OffAllRegisters();
   boolean OnRegister(int reg_index);
   boolean OnAllRegisters();
   
   boolean OnSingleRegister(int position, int reg_index);
   boolean OnSingleAllRegisters(int position);
   boolean OnSingleEachRegisters(int position);
   boolean OffSingleRegister(int position, int reg_index);
   boolean OffSingleAllRegisters(int position);
   boolean OffSingleEachRegisters(int position);

   boolean OnSingleOnlyRegister(int position, int reg_index);
   boolean OnSingleOnlyAllRegisters(int position);
   boolean OnSingleOnlyEachRegisters(int position);
   boolean OffSingleOnlyRegister(int position, int reg_index);
   boolean OffSingleOnlyAllRegisters(int position);
   boolean OffSingleOnlyEachRegisters(int position);
   
   boolean ShiftLeftRegister(boolean circular, int reg_index);
   boolean ShiftLeftAllRegisters(boolean circular);
   boolean ShiftLeftEachRegisters(boolean circular);
   
   boolean ShiftRightRegister(boolean circular, int reg_index);
   boolean ShiftRightAllRegisters(boolean circular);
   boolean ShiftRightEachRegisters(boolean circular);
   
   boolean Update();
   boolean Blink(int iter, int delay_val);
   
   boolean verbose;
   int     nb_registers;
   int     data_pin;
   int     clock_pin;
   int     latch_pin;
   
private:
   
   boolean funcOffRegister(int reg_index);
   boolean funcOffAllRegisters();
   boolean funcOnRegister(int reg_index);
   boolean funcOnAllRegisters();
   
   boolean funcOnSingleRegister(int position, int reg_index);
   boolean funcOnSingleAllRegisters(int position);
   boolean funcOnSingleEachRegisters(int position);
   boolean funcOffSingleRegister(int position, int reg_index);
   boolean funcOffSingleAllRegisters(int position);
   boolean funcOffSingleEachRegisters(int position);
   
   boolean funcOnSingleOnlyRegister(int position, int reg_index);
   boolean funcOnSingleOnlyAllRegisters(int position);
   boolean funcOnSingleOnlyEachRegisters(int position);
   boolean funcOffSingleOnlyRegister(int position, int reg_index);
   boolean funcOffSingleOnlyAllRegisters(int position);
   boolean funcOffSingleOnlyEachRegisters(int position);
   
   boolean funcShiftLeftRegister(boolean circular, int reg_index);
   boolean funcShiftLeftAllRegisters(boolean circular);
   boolean funcShiftLeftEachRegisters(boolean circular);
   boolean funcShiftLeftAcross(boolean circular);
   
   boolean funcShiftRightRegister(boolean circular, int reg_index);
   boolean funcShiftRightAllRegisters(boolean circular);
   boolean funcShiftRightEachRegisters(boolean circular);
   boolean funcShiftRightAcross(boolean circular);
   
   boolean funcUpdate();
   boolean funcBlink(int iter, int delay_val);

private:
   void    Dump(char* text);
   void    ShiftOut(byte DataOut);
   boolean ValidRegister(int index);
   boolean ValidRegisterPosition(int index);
   boolean ValidAllRegistersPosition(int index);
   
private:
   int   funclevel;
   byte* registerData;
};



class FuncObj
{
public:
   FuncObj(int* levelptr, boolean* verboseptr)
   {
   funcverboseptr = verboseptr;
   funclevelptr   = levelptr;
   
   (*funclevelptr)+=1;
   
   if(*funcverboseptr)
      {
      if((*funclevelptr)==1)
         Serial.print("[[START:");
      else
         Serial.print("[");
      }
   }
   
   ~FuncObj()
   {
   (*funclevelptr)-=1;
   
   if(*funcverboseptr)
      {
      if((*funclevelptr)==0)
         Serial.println(":END]]");
      else
         Serial.print("]");
      }
   }
   
   int*     funclevelptr;
   boolean* funcverboseptr;
};
#endif

//
// END OF FILE
//
