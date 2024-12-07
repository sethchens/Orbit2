/***********************************************************************
 * Source File:
 *    TEST ACCELERATION
 * Author:
 *    <your name here>
 * Summary:
 *    Unit tests for the Acceleration class.
 ************************************************************************/


#include "testAcceleration.h"


/*********************************************
 * name:    DEFAULT CONSTRUCTOR
 * input:   nothing
 * output:  zeros
 *********************************************/
void TestAcceleration::constructor_default()
{  // setup
   // exercise
   Acceleration a;

   // verify
   assertEquals(a.ddx, 0.0);
   assertEquals(a.ddy, 0.0);
}  // teardown
   
/*********************************************
 * name:    NON-DEFAULT CONSTRUCTOR
 * input:   2.3, 4.5
 * output:  (2.3, 4.5)
 *********************************************/
void TestAcceleration::constructor_nonDefault()
{  // setup
   double ddx = 2.3;
   double ddy = 4.5;
   // exercise
   Acceleration a(ddx, ddy);

   // verify
   assertEquals(a.ddx, 2.3);
   assertEquals(a.ddy, 4.5);
   assertEquals(ddx, 2.3);
   assertEquals(ddy, 4.5);
}  // teardown

/*********************************************
 * name:    GET DDX
 * input:   (2.3, 4.5)
 * output:  2.3
 *********************************************/
void TestAcceleration::getDDX()
{  // setup
   Acceleration a;
   a.ddx = 2.3;
   a.ddy = 4.5;
   double ddx = 99.9;

   // exercise
   ddx = a.getDDX();

   // verify
   assertEquals(a.ddx, 2.3);
   assertEquals(a.ddy, 4.5);
   assertEquals(ddx,2.3);
}  // teardown

/*********************************************
 * name:    GET DDY
 * input:   (2.3, 4.5)
 * output:  4.5
 *********************************************/
void TestAcceleration::getDDY()
{  // setup
   Acceleration a;
   a.ddx = 2.3;
   a.ddy = 4.5;
   double ddy = 99.9;

   // exercise
   ddy = a.getDDY();

   // verify
   assertEquals(a.ddx, 2.3);
   assertEquals(a.ddy, 4.5);
   assertEquals(ddy, 4.5);
}  // teardown

/*********************************************
 * name:    SET DDX
 * input:   (-99.9, -88.8) 11.1
 * output:  (11.1, -88.8)
 *********************************************/
void TestAcceleration::setDDX()
{  // setup
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   
   // exercise
   a.setDDX(11.1);

   // verify
   assertEquals(a.ddx, 11.1);
   assertEquals(a.ddy, -88.8);
}

/*********************************************
 * name:    SET DDX
 * input:   (-99.9, -88.8) 11.1
 * output:  (-99.9, 11.1)
 *********************************************/
void TestAcceleration::setDDY()
{  // setup
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;

   // exercise
   a.setDDY(11.1);

   // verify
   assertEquals(a.ddx, -99.9);
   assertEquals(a.ddy, 11.1);
}

/*********************************************
 * name:    SET UP
 * input:   (-99.9, -88.8) 0 degrees, 3.3
 * output:  (0.0, 3.3)
 *********************************************/
void TestAcceleration::set_up()
{  // setup
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   Angle angle;
   angle.radians = 0.0; // up
   double magnitude = 3.3;

   // exercise
   a.set(angle, magnitude);

   // verify
   assertEquals(a.ddx, 0.0);
   assertEquals(a.ddy, 3.3);
   assertEquals(angle.radians, 0.0);
   assertEquals(magnitude, 3.3);
}

/*********************************************
 * name:    SET DOWN
 * input:   (-99.9, -88.8) 180 degrees, 3.3
 * output:  (0.0, -3.3)
 *********************************************/
void TestAcceleration::set_down()
{  // setup
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   Angle angle;
   angle.radians = M_PI; // DOWN
   double magnitude = 3.3;

   // exercise
   a.set(angle, magnitude);

   // verify
   assertEquals(a.ddx, 0.0);
   assertEquals(a.ddy,-3.3);
   assertEquals(angle.radians, M_PI);
   assertEquals(magnitude, 3.3);
}

/*********************************************
 * name:    SET RIGHT
 * input:   (-99.9, -88.8) 90 degrees, 3.3
 * output:  (3.3, 0.0)
 *********************************************/
void TestAcceleration::set_right()
{  // setup
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   Angle angle;
   angle.radians = M_PI_2; // RIGHT
   double magnitude = 3.3;

   // exercise
   a.set(angle, magnitude);

   // verify
   assertEquals(a.ddx, 3.3);
   assertEquals(a.ddy, 0.0);
   assertEquals(angle.radians, M_PI_2);
   assertEquals(magnitude, 3.3);
}

/*********************************************
 * name:    SET LEFT
 * input:   (-99.9, -88.8) 270 degrees, 3.3
 * output:  (3.3, 0.0)
 *********************************************/
void TestAcceleration::set_left()
{  // setup
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   Angle angle;
   angle.radians = M_PI_2 + M_PI; // RIGHT
   double magnitude = 3.3;

   // exercise
   a.set(angle, magnitude);

   // verify
   assertEquals(a.ddx, -3.3);
   assertEquals(a.ddy, 0.0);
   assertEquals(angle.radians, M_PI_2 + M_PI);
   assertEquals(magnitude, 3.3);
}

/*********************************************
 * name:    SET DIAGONAL
 * input:   (-99.9, -88.8) 57 degrees, 1.0
 * output:  (0.84, 0.54)
 *********************************************/
void TestAcceleration::set_diagonal()
{  // setup
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   Angle angle;
   angle.radians = 1.0; // up and right somewhat
   double magnitude = 1.0;

   // exercise
   a.set(angle, magnitude);

   // verify
   assertEquals(a.ddx, 0.8414);
   assertEquals(a.ddy, 0.5403);
   assertEquals(angle.radians, 1.0);
   assertEquals(magnitude,1.0);
}

/*********************************************
 * name:    ADD DDX ZERO
 * input:   a=(2.3, 4.5) ddx=0.0
 * output:  a=(2.3, 4.5)
 *********************************************/
void TestAcceleration::addDDX_zero()
{
    Acceleration a(2.3, 4.5);
    a.addDDX(0);
    assertEquals(a.getDDX(), 2.3);
    assertEquals(a.getDDY(), 4.5);
}

/*********************************************
 * name:    ADD DDX 4.1
 * input:   a=(2.3, 4.5) ddx=4.1
 * output:  a=(6.4, 4.5)
 *********************************************/
void TestAcceleration::addDDX_value()
{
    Acceleration a(2.3, 4.5);
    a.addDDX(4.1);
    assertEquals(a.getDDX(), 6.4);
    assertEquals(a.getDDY(), 4.5);
}

/*********************************************
 * name:    ADD DDY ZERO
 * input:   a=(2.3, 4.5) ddy=0.0
 * output:  a=(2.3, 4.5)
 *********************************************/
void TestAcceleration::addDDY_zero()
{
    Acceleration a(2.3, 4.5);
    a.addDDY(0);
    assertEquals(a.getDDX(), 2.3);
    assertEquals(a.getDDY(), 4.5);
}

/*********************************************
 * name:    ADD DDY 4.1
 * input:   a=(2.3, 4.5) ddy=4.1
 * output:  a=(2.3, 8.6)
 *********************************************/
void TestAcceleration::addDDY_value()
{
    Acceleration a(2.3, 4.5);
    a.addDDY(4.1);
    assertEquals(a.getDDX(), 2.3);
    assertEquals(a.getDDY(), 8.6);
}

/*********************************************
 * name:    ADD NOTHING TO NOTHING
 * input:   aLHS=(0.0, 0.0) aRHS=(0.0, 0.0)
 * output:  aLHS=(0.0, 0.0)
 *********************************************/
void TestAcceleration::add_zeroZero()
{
    Acceleration LHS(0.0, 0.0);
    Acceleration RHS(0.0, 0.0);
    LHS.add(RHS);
    assertEquals(LHS.getDDX(), 0.0);
    assertEquals(LHS.getDDY(), 0.0);
}

/*********************************************
 * name:    ADD NOTHING TO A VALUE
 * input:   aLHS=(1.1, 2.2) aRHS=(0.0, 0.0)
 * output:  aLHS=(1.1, 2.2)
 *********************************************/
void TestAcceleration::add_valueZero()
{
    Acceleration LHS(1.1, 2.2);
    Acceleration RHS(0.0, 0.0);
    LHS.add(RHS);
    assertEquals(LHS.getDDX(), 1.1);
    assertEquals(LHS.getDDY(), 2.2);
}

/*********************************************
 * name:    ADD A VALUE TO NOTHING
 * input:   aLHS=(0.0, 0.0) aRHS=(4.4, 7.7)
 * output:  aLHS=(4.4, 7.7)
 *********************************************/
void TestAcceleration::add_zeroValue()
{
    Acceleration LHS(0.0, 0.0);
    Acceleration RHS(4.4, 7.7);
    LHS.add(RHS);
    assertEquals(LHS.getDDX(), 4.4);
    assertEquals(LHS.getDDY(), 7.7);
}

/*********************************************
 * name:    ADD A VALUE TO ANOTHER VALUE
 * input:   aLHS=(1.1, 2.2) aRHS=(4.4, 7.7)
 * output:  aLHS=(5.5, 9.9)
 *********************************************/
void TestAcceleration::add_valueValue()
{
    Acceleration LHS(1.1, 2.2);
    Acceleration RHS(4.4, 7.7);
    LHS.add(RHS);
    assertEquals(LHS.getDDX(), 5.5);
    assertEquals(LHS.getDDY(), 9.9);
}
