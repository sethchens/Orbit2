#pragma once
#include "satellite.h"
#include "velocity.h"
#include "uiDraw.h"
#include "Fragment.h"
#include "part.h"

class TestCrewDragon;

/*********************************************
 * CREW DRAGON CENTER
 * Center component of a destroyed Crew Dragon spacecraft
 *********************************************/
class CrewDragonCenter : public Part
{
public:
   CrewDragonCenter(const Satellite& parent) : Part(6.0, 0.0, parent) {}
   
   virtual void draw(ogstream& gout) override ;
   virtual void destroy(std::list<Satellite*>& satellites) override;
};

/*********************************************
 * CREW DRAGON LEFT
 * Left side component of a destroyed Crew Dragon spacecraft
 *********************************************/
class CrewDragonLeft : public Part
{
public:
   CrewDragonLeft(const Satellite& parent) : Part(6.0, 0.0, parent) {}
   
   virtual void draw(ogstream& gout) override;
   virtual void destroy(std::list<Satellite*>& satellites) override;
};

/*********************************************
 * CREW DRAGON RIGHT
 * Right side component of a destroyed Crew Dragon spacecraft
 *********************************************/
class CrewDragonRight : public Part
{
public:
   CrewDragonRight(const Satellite& parent) : Part(6.0, 0.0, parent) {}
   
   virtual void draw(ogstream& gout) override;
   virtual void destroy(std::list<Satellite*>& satellites) override;
};




/*********************************************
 * CREW DRAGON
 * SpaceX Crew Dragon spacecraft in low Earth orbit
 *********************************************/
class CrewDragon : public Satellite
{
public:
   friend TestCrewDragon;
   CrewDragon() : Satellite(0, 7.0, 0.0)
   // age=0, radius=8.0 (larger than other satellites), no rotation
   {
      // Initial position at ISS-like orbit (~400km altitude)
      pos.setMetersX(0.0);
      pos.setMetersY(8000000.0);  //
      
      // Initial velocity for circular orbit at ISS altitude
      // m/s - slightly faster than Starlink due to lower orbit
      velocity.setDX(-7900.0);
      velocity.setDY(0.0);      // m/s
      
      timeDilation = 48.0; // Same time dilation as other satellites
   }
   
   virtual void move(double time) override;
   void destroy(std::list<Satellite*>& satellites) override;
   virtual void draw(ogstream& gout) override;
   
private:
   double timeDilation;  // Time scaling factor for this satellite
};

