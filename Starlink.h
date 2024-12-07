/***********************************************************************
 * Header File:
 *    STARLINK
 * Author:
 *    Chris Mijango & Seth Chen
 * Summary:
 *    Body component of a destroyed Starlink satellite
 ************************************************************************/


#pragma once
#include "satellite.h"
#include "velocity.h"
#include "uiDraw.h"
#include "part.h"
#include "Fragment.h"

class TestStarlink;


class StarlinkBody : public Part
{
public:
   StarlinkBody(const Satellite& parent) : Part(2.0, 0.0, parent) {}
   
   void draw(ogstream& gout) override;
   void destroy(std::list<Satellite*>& satellites) override;
};

/*********************************************
 * STARLINK ARRAY
 * Solar array component of a destroyed Starlink satellite
 *********************************************/
class StarlinkArray : public Part
{
public:
   StarlinkArray(const Satellite& parent) : Part(4.0, 0.0, parent) {}
   
   void draw(ogstream& gout) override;
   void destroy(std::list<Satellite*>& satellites) override;
};


/*********************************************
 * STARLINK
 * A Starlink satellite in low Earth orbit
 *********************************************/
class Starlink : public Satellite
{
public:
   friend TestStarlink;
   Starlink() : Satellite(0, 6.0, 0.0002)  // age=0, radius=6.0, angularVelocity=0.0002
   {
      // Initial position at lower orbit (low Earth orbit, ~550km altitude)
      pos.setMetersX(0.0);
      pos.setMetersY(-13020000.0);  // Earth radius (6378km) + 550km altitude
      
      // Initial velocity for circular orbit (faster due to lower orbit)
      velocity.setDX(5800.0);  // m/s
      velocity.setDY(0.0);      // m/s
      
      timeDilation = 48.0; // Same time dilation as other satellites for consistency
   }
   
   virtual void move(double time) override;
   virtual void destroy(std::list<Satellite*>& satellites) override;
   virtual void draw(ogstream& gout) override;
   
private:
   double timeDilation;  // Time scaling factor for this satellite
};

