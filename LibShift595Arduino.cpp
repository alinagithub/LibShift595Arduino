//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
// FILE: libshift595arduino.cpp
// VERSION: 0.1.00
// PURPOSE: Package for 595 shift register
// CREATED BY: Arnaud D. LINA
// DATE: June 2014
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

#include "libshift595arduino.h"

/////////////////////////////////////////////////////
//
// PUBLIC
//

#define DEFAULT_VERBOSE       false

Shift595Arduino::Shift595Arduino(int datapin, int clockpin, int latchpin, int nbregisters)
   {
   verbose                    = DEFAULT_VERBOSE;
   nb_registers               = nbregisters;
   data_pin                   = datapin;
   clock_pin                  = clockpin;
   latch_pin                  = latchpin;
   funclevel                  = 0;
   
   registerData = new byte[nb_registers];
   }

boolean Shift595Arduino::OffRegister(int reg_index)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOffRegister(reg_index);
}

boolean Shift595Arduino::OffAllRegisters()
{
   FuncObj obj(&funclevel, &verbose);
   return funcOffAllRegisters();
}

boolean Shift595Arduino::OnRegister(int reg_index)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOnRegister(reg_index);
}

boolean Shift595Arduino::OnAllRegisters()
{
   FuncObj obj(&funclevel, &verbose);
   return funcOnAllRegisters();
}

boolean Shift595Arduino::OnSingleRegister(int position, int reg_index)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOnSingleRegister(position, reg_index);
}

boolean Shift595Arduino::OnSingleOnlyRegister(int position, int reg_index)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOnSingleOnlyRegister(position, reg_index);
}

boolean Shift595Arduino::OnSingleAllRegisters(int position)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOnSingleAllRegisters(position);
}

boolean Shift595Arduino::OnSingleOnlyAllRegisters(int position)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOnSingleOnlyAllRegisters(position);
}

boolean Shift595Arduino::OnSingleEachRegisters(int position)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOnSingleEachRegisters(position);
}

boolean Shift595Arduino::OnSingleOnlyEachRegisters(int position)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOnSingleOnlyEachRegisters(position);
}

boolean Shift595Arduino::OffSingleRegister(int position, int reg_index)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOffSingleRegister(position, reg_index);
}

boolean Shift595Arduino::OffSingleOnlyRegister(int position, int reg_index)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOffSingleOnlyRegister(position, reg_index);
}

boolean Shift595Arduino::OffSingleAllRegisters(int position)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOffSingleAllRegisters(position);
}

boolean Shift595Arduino::OffSingleOnlyAllRegisters(int position)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOffSingleOnlyAllRegisters(position);
}

boolean Shift595Arduino::OffSingleEachRegisters(int position)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOffSingleEachRegisters(position);
}

boolean Shift595Arduino::OffSingleOnlyEachRegisters(int position)
{
   FuncObj obj(&funclevel, &verbose);
   return funcOffSingleOnlyEachRegisters(position);
}

boolean Shift595Arduino::ShiftLeftRegister(boolean circular, int reg_index)
   {
   FuncObj obj(&funclevel, &verbose);
   return funcShiftLeftRegister(circular, reg_index);
   }

boolean Shift595Arduino::ShiftLeftAllRegisters(boolean circular)
{
   FuncObj obj(&funclevel, &verbose);
   return funcShiftLeftAllRegisters(circular);
}

boolean Shift595Arduino::ShiftLeftEachRegisters(boolean circular)
{
   FuncObj obj(&funclevel, &verbose);
   return funcShiftLeftEachRegisters(circular);
}

boolean Shift595Arduino::ShiftRightRegister(boolean circular, int reg_index)
{
   FuncObj obj(&funclevel, &verbose);
   return funcShiftRightRegister(circular, reg_index);
}

boolean Shift595Arduino::ShiftRightAllRegisters(boolean circular)
{
   FuncObj obj(&funclevel, &verbose);
   return funcShiftRightAllRegisters(circular);
}

boolean Shift595Arduino::ShiftRightEachRegisters(boolean circular)
{
   FuncObj obj(&funclevel, &verbose);
   return funcShiftRightEachRegisters(circular);
}

boolean Shift595Arduino::Update()
{
   FuncObj obj(&funclevel, &verbose);
   return funcUpdate();
}

boolean Shift595Arduino::Blink(int iter, int delay_val)
{
   FuncObj obj(&funclevel, &verbose);
   return funcBlink(iter, delay_val);
}

/////////////////////////////////////////////////////
//
// PRIVATE
//

boolean Shift595Arduino::funcOffRegister(int reg_index)
{
   Dump("OffRegister");
   if(!ValidRegister(reg_index)) {return false;};
   
   registerData[reg_index] = 0x0;
   
   return true;
}

boolean Shift595Arduino::funcOffAllRegisters()
{
   Dump("OffAllRegisters");
   
   for(int ii=0; ii<nb_registers; ii++)
      registerData[ii] = 0x0;
   
   return true;
}

boolean Shift595Arduino::funcOnRegister(int reg_index)
{
   Dump("OnRegister");
   if(!ValidRegister(reg_index)) {return false;};
   
   registerData[reg_index] = 0xFF;
   
   return true;
}

boolean Shift595Arduino::funcOnAllRegisters()
{
   Dump("OnAllRegisters");
   
   for(int ii=0; ii<nb_registers; ii++)
      registerData[ii] = 0xFF;
   
   return true;
}

boolean Shift595Arduino::funcOnSingleRegister(int position, int reg_index)
{
   Dump("OnSingleRegister");
   if(!ValidRegister(reg_index)) {return false;};
   if(!ValidRegisterPosition(position)) {return false;};
   
   registerData[reg_index] |= 1<<position;
   return true;
}

boolean Shift595Arduino::funcOnSingleOnlyRegister(int position, int reg_index)
{
   Dump("OnSingleRegister");
   if(!ValidRegister(reg_index)) {return false;};
   if(!ValidRegisterPosition(position)) {return false;};
   
   registerData[reg_index] = 0x0;
   registerData[reg_index] |= 1<<position;
   return true;
}

boolean Shift595Arduino::funcOnSingleAllRegisters(int position)
{
   Dump("OnSingleRegister");
   
   if(!ValidAllRegistersPosition(position)) {return false;};
   
   int reg_index = position/8;
   registerData[reg_index] |= 1<<(position%8);
   
   return true;
}

boolean Shift595Arduino::funcOnSingleOnlyAllRegisters(int position)
{
   Dump("OnSingleRegister");
   
   if(!ValidAllRegistersPosition(position)) {return false;};
   
   funcOffAllRegisters();
   int reg_index = position/8;
   registerData[reg_index] |= 1<<(position%8);
   
   return true;
}

boolean Shift595Arduino::funcOnSingleEachRegisters(int position)
{
   Dump("OnSingleRegister");
   if(!ValidRegisterPosition(position)) {return false;};
   
   for(int ii=0; ii<nb_registers; ii++)
      registerData[ii] |= 1<<position;
   
   return true;
}

boolean Shift595Arduino::funcOnSingleOnlyEachRegisters(int position)
{
   Dump("OnSingleRegister");
   if(!ValidRegisterPosition(position)) {return false;};
   
   funcOffAllRegisters();
   
   for(int ii=0; ii<nb_registers; ii++)
      registerData[ii] |= 1<<position;
   
   return true;
}

boolean Shift595Arduino::funcOffSingleRegister(int position, int reg_index)
{
   Dump("OnSingleRegister");
   if(!ValidRegister(reg_index)) {return false;};
   if(!ValidRegisterPosition(position)) {return false;};
   
   registerData[reg_index] &= ~(1<<position);
   return true;
}

boolean Shift595Arduino::funcOffSingleOnlyRegister(int position, int reg_index)
{
   Dump("OnSingleRegister");
   if(!ValidRegister(reg_index)) {return false;};
   if(!ValidRegisterPosition(position)) {return false;};
   
   registerData[reg_index] = 0xFF;
   registerData[reg_index] &= ~(1<<position);
   return true;
}

boolean Shift595Arduino::funcOffSingleAllRegisters(int position)
{
   Dump("OnSingleRegister");
   
   if(!ValidAllRegistersPosition(position)) {return false;};
   
   int reg_index = position/8;
   registerData[reg_index] &= ~(1<<(position%8));
   
   return true;
}

boolean Shift595Arduino::funcOffSingleOnlyAllRegisters(int position)
{
   Dump("OnSingleRegister");
   
   if(!ValidAllRegistersPosition(position)) {return false;};
   
   funcOnAllRegisters();
   int reg_index = position/8;
   registerData[reg_index] &= ~(1<<(position%8));
   
   return true;
}

boolean Shift595Arduino::funcOffSingleEachRegisters(int position)
{
   Dump("OnSingleRegister");
   if(!ValidRegisterPosition(position)) {return false;};
   
   for(int ii=0; ii<nb_registers; ii++)
      registerData[ii] &= ~(1<<position);
   
   return true;
}

boolean Shift595Arduino::funcOffSingleOnlyEachRegisters(int position)
{
   Dump("OnSingleRegister");
   if(!ValidRegisterPosition(position)) {return false;};
   
   funcOnAllRegisters();
   
   for(int ii=0; ii<nb_registers; ii++)
      registerData[ii] &= ~(1<<position);
   
   return true;
}

boolean Shift595Arduino::funcShiftLeftRegister(boolean circular, int reg_index)
{
   Dump("ShiftLeftRegister");
   
   bool bitzero_on = registerData[reg_index] & 0x80;
   Serial.print(bitzero_on);
   
   registerData[reg_index]=registerData[reg_index]<<1;
   
   if(circular)
      if(bitzero_on)
         registerData[reg_index] |=0x1;
      else
         registerData[reg_index] &=0xFE;
   
   return true;
}

boolean Shift595Arduino::funcShiftLeftAllRegisters(boolean circular)
{
   Dump("ShiftLeftAllRegisters");
   
   // To implement...
   
   return true;
}

boolean Shift595Arduino::funcShiftLeftEachRegisters(boolean circular)
{
   Dump("ShiftLeftEachRegisters");
   
   for(int ii=0; ii<nb_registers; ii++)
      funcShiftLeftRegister(circular, ii);

   return true;
}

boolean Shift595Arduino::funcShiftRightRegister(boolean circular, int reg_index)
{
   Dump("ShiftRightRegister");
   
   bool bitzero_on = registerData[reg_index] & 0x01;
   Serial.print(bitzero_on);
   
   registerData[reg_index]=registerData[reg_index]>>1;
   
   if(circular)
      if(bitzero_on)
         registerData[reg_index] |=0x80;
      else
         registerData[reg_index] &=0x7F;
   
   return true;
}

boolean Shift595Arduino::funcShiftRightAllRegisters(boolean circular)
{
   Dump("ShiftRightAllRegisters");
   
   // To implement...
   
   return true;
}

boolean Shift595Arduino::funcShiftRightEachRegisters(boolean circular)
{
   Dump("ShiftRightEachRegisters");
   
   for(int ii=0; ii<nb_registers; ii++)
      funcShiftRightRegister(circular, ii);
      
      return true;
}

boolean Shift595Arduino::funcUpdate()
{
   Dump("Update");
   
   //ground latchPin and hold low for as long as you are transmitting
   digitalWrite(latch_pin, 0);
   //move 'em out
   for(int ii=0; ii<nb_registers; ii++)
      ShiftOut(registerData[nb_registers-ii-1]);
   //return the latch pin high to signal chip that it
   //no longer needs to listen for information
   digitalWrite(latch_pin, 1);
}

boolean Shift595Arduino::funcBlink(int iter, int delay_val)
{
   Dump("Blink");
   
   for(int jj=0; jj<iter; jj++)
      {
      //ground latchPin and hold low for as long as you are transmitting
      digitalWrite(latch_pin, 0);
      //move 'em out
      for(int ii=0; ii<nb_registers; ii++)
         ShiftOut(0x0);
      //return the latch pin high to signal chip that it
      //no longer needs to listen for information
      digitalWrite(latch_pin, 1);
      delay(delay_val);
      funcUpdate();
      delay(delay_val);
      }
   
   return true;
}

/////////////////////////////////////////////////////
//
// PRIVATE UTIL
//
void Shift595Arduino::Dump(char* text)
{
   if(verbose)
      {
      Serial.print(text);
      delay(20);
      }
}

boolean Shift595Arduino::ValidRegister(int index)
{
   return (index>=0) && (index<nb_registers);
}

boolean Shift595Arduino::ValidRegisterPosition(int index)
{
   return (index>=0) && (index<8);
}

boolean Shift595Arduino::ValidAllRegistersPosition(int index)
{
   return (index>=0) && (index<nb_registers*8);
}


//**************************************************************//
//  Name    : shiftOutCode, Predefined Dual Array Style         //
//  Author  : Thanks to Carlyn Maw, Tom Igoe                    //
//  Date    : 25 Oct, 2006                                      //
//  Version : 1.0                                               //
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                            //
//****************************************************************
void Shift595Arduino::ShiftOut(byte DataOut)
{
   // This shifts 8 bits out MSB first,
   //on the rising edge of the clock,
   //clock idles low
   
   //internal function setup
   int i=0;
   int pinState;
   pinMode(clock_pin, OUTPUT);
   pinMode(data_pin, OUTPUT);
   
   //clear everything out just in case to
   //prepare shift register for bit shifting
   digitalWrite(data_pin, 0);
   digitalWrite(clock_pin, 0);
   
   //for each bit in the byte DataOut�
   //NOTICE THAT WE ARE COUNTING DOWN in our for loop
   //This means that %00000001 or "1" will go through such
   //that it will be pin Q0 that lights.
   for (i=7; i>=0; i--)  {
      digitalWrite(clock_pin, 0);
      
      //if the value passed to DataOut and a bitmask result
      // true then... so if we are at i=6 and our value is
      // %11010100 it would the code compares it to %01000000
      // and proceeds to set pinState to 1.
      if ( DataOut & (1<<i) ) {
         pinState= 1;
      }
      else {
         pinState= 0;
      }
      
      //Sets the pin to HIGH or LOW depending on pinState
      digitalWrite(data_pin, pinState);
      //register shifts bits on upstroke of clock pin
      digitalWrite(clock_pin, 1);
      //zero the data pin after shift to prevent bleed through
      digitalWrite(data_pin, 0);
   }
   
   //stop shifting
   digitalWrite(clock_pin, 0);
}


//
// END OF FILE
//
