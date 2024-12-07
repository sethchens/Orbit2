/***********************************************************************
 * Header File:
 *    TEST ANGLE
 * Author:
 *    <your name here>
 * Summary:
 *    All the unit tests for ANGLE
 ************************************************************************/

#pragma once


#include "angle.h"
#include "unitTest.h"

/*******************************
 * TEST ANGLE
 * A friend class for Angle which contains the Angle unit tests
 ********************************/
class TestAngle : public UnitTest
{
public:
   void run()
   {
      // Ticket 1: From before
      defaultConstructor();
      setUp();
      setDown();
      setRight();
      setLeft();
      reverse();
      setRadians_noNormalize();
      setDegrees_noNormalize();
      getDegrees_0();
      getDegrees_270();
      getRadians_0();
      getRadians_270();
      add_0();
      add_value();
      setRadians_negative();
      setRadians_oneLap();
      setRadians_sixLaps();
      setRadians_negativeThreeQuarters();
      setRadians_negativeOneLap();
      setRadians_negativeSixLaps();
      setDegrees_negative();
      setDegrees_oneLap();
      setDegrees_sixLaps();
      setDegrees_negativeThreeQuarters();
      setDegrees_negativeOneLap();
      setDegrees_negativeSixLaps();
      add_positiveLap();
      add_negativeLap();

      // Ticket 2: Components
      getDx_up();
      getDx_down();
      getDx_left();
      getDx_right();
      getDx_diagonal();
      getDy_up();
      getDy_down();
      getDy_left();
      getDy_right();
      getDy_diagonal();
      isRight_right();
      isRight_left();
      isLeft_right();
      isLeft_left();
      setDxDy_up();
      setDxDy_right();
      setDxDy_left();
      setDxDy_diagonal();

      report("Angle");
   }

private:
   
   // constructor
   void defaultConstructor();
   
   // setters
   void setUp();
   void setDown();
   void setRight();
   void setLeft();
   void reverse();
   void setRadians_noNormalize();
   void setRadians_negative();
   void setRadians_oneLap();
   void setRadians_sixLaps();
   void setRadians_negativeThreeQuarters();
   void setRadians_negativeOneLap();
   void setRadians_negativeSixLaps();
   void setDegrees_noNormalize();
   void setDegrees_negative();
   void setDegrees_oneLap();
   void setDegrees_sixLaps();
   void setDegrees_negativeThreeQuarters();
   void setDegrees_negativeOneLap();
   void setDegrees_negativeSixLaps();
   void setDxDy_up();
   void setDxDy_right();
   void setDxDy_left();
   void setDxDy_diagonal();
   
   // add
   void add_0();
   void add_value();
   void add_positiveLap();
   void add_negativeLap();

   // getters
   void getDegrees_0();
   void getDegrees_270();
   void getRadians_0();
   void getRadians_270();
   void getDx_up();
   void getDx_down();
   void getDx_left();
   void getDx_right();
   void getDx_diagonal();
   void getDy_up();
   void getDy_down();
   void getDy_left();
   void getDy_right();
   void getDy_diagonal();
   void isRight_right();
   void isRight_left();
   void isLeft_right();
   void isLeft_left();
};
