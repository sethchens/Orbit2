/***********************************************************************
 * Header File:
 *    TEST ACCELERATION
 * Author:
 *    <your name here>
 * Summary:
 *    Unit tests for the Acceleration class.
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "acceleration.h"
#include "angle.h"
#define _USE_MATH_DEFINES
#include <math.h>

/*********************************************
 * TEST ACCELERATION
 * Unit tests for Acceleration
 *********************************************/
class TestAcceleration : public UnitTest
{
public:
   void run()
   {
      // Ticket 3: Without Add
      constructor_default();
      constructor_nonDefault();
      getDDX();
      getDDY();
      setDDX();
      setDDY();
      set_up();
      set_down();
      set_left();
      set_right();
      set_diagonal();

      // Ticket 4: Add
      addDDX_zero();
      addDDX_value();
      addDDY_zero();
      addDDY_value();
      add_zeroZero();
      add_valueZero();
      add_zeroValue();
      add_valueValue();

      report("Acceleration");
   }

private:
   
   // constructor
   void constructor_default();
   void constructor_nonDefault();
   
   // getters
   void getDDX();
   void getDDY();
   
   // setters
   void setDDX();
   void setDDY();
   void set_up();
   void set_down();
   void set_right();
   void set_left();
   void set_diagonal();
   
   // add
   void addDDX_zero();
   void addDDX_value();
   void addDDY_zero();
   void addDDY_value();
   void add_zeroZero();
   void add_valueZero();
   void add_zeroValue();
   void add_valueValue();
};
