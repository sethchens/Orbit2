/***********************************************************************
 * Source File:
 *    SPUTNIK
 * Author:
 *    Chris Mijango & Seth Chen
 * Summary:
 *    The first artificial satellite in space
 ************************************************************************/


#pragma once
#include "satellite.h"
#include "velocity.h"
#include "uiDraw.h"
#include "Fragment.h"

class TestSputnik;


class Sputnik : public Satellite
{
public:
   friend TestSputnik;
   Sputnik() : Satellite(0, 4.0, 0.001)  // age=0, radius=4.0, angularVelocity=0.1
   {
      // Initial position and velocity for retrograde orbit
      pos.setMetersX(-36515095.13);
      pos.setMetersY(21082000.0);
      
      velocity.setDX(2050.0);  // m/s
      velocity.setDY(2684.68); // m/s
      
      timeDilation = 48.0; // Slowed down from 1440 for better visualization
   }
   
   virtual void move(double time) override;
   virtual void draw(ogstream& gout) override;
   virtual void destroy(std::list<Satellite*>& satellites) override;
   
private:
   double timeDilation;  // Time scaling factor for this satellite
};
