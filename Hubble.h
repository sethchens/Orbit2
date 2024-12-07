/***********************************************************************
 * Header File:
 *    Hubble
 * Author:
 *    Chris Mijango & Seth Chen
 * Summary:
 *    Hubble class
 ************************************************************************/


#pragma once
#include "satellite.h"
#include "velocity.h"
#include "uiDraw.h"
#include "part.h"
#include "Fragment.h"

class TestHubble;

/*********************************************
 * HUBBLE TELESCOPE
 * Telescope component of a destroyed Hubble satellite
 *********************************************/
class HubbleTelescope : public Part
{
public:
   HubbleTelescope(const Satellite& parent) : Part(10.0, 0.0, parent) {}
   
   virtual void draw(ogstream& gout) override;
   virtual void destroy(std::list<Satellite*>& satellites) override;
};

/*********************************************
 * HUBBLE COMPUTER
 * Computer component of a destroyed Hubble satellite
 *********************************************/
class HubbleComputer : public Part
{
public:
   HubbleComputer(const Satellite& parent) : Part(7.0, 0.0, parent) {}
   
   virtual void draw(ogstream& gout) override;
   virtual void destroy(std::list<Satellite*>& satellites) override;
};

/*********************************************
 * HUBBLE LEFT ARRAY
 * Left solar array of a destroyed Hubble satellite
 *********************************************/
class HubbleLeftArray : public Part
{
public:
   HubbleLeftArray(const Satellite& parent) : Part(8.0, 0.0, parent) {}
   
   virtual void draw(ogstream& gout) override;
   virtual void destroy(std::list<Satellite*>& satellites) override;
};

/*********************************************
 * HUBBLE RIGHT ARRAY
 * Right solar array of a destroyed Hubble satellite
 *********************************************/
class HubbleRightArray : public Part
{
public:
   HubbleRightArray(const Satellite& parent) : Part(8.0, 0.0, parent) {}
   
   virtual void draw(ogstream& gout) override;
   virtual void destroy(std::list<Satellite*>& satellites) override;
};

class Hubble : public Satellite {
public:
   friend TestHubble;
   
   Hubble() : Satellite(0, 10.0, 0.0) {
      pos.setMetersX(0.0);
      pos.setMetersY(-42164000.0);
      velocity.setDX(3100.0);
      velocity.setDY(0.0);
      timeDilation = 48.0;
   }
   
   virtual void destroy(std::list<Satellite*>& satellites) override;
   virtual void move(double time) override;
   virtual void draw(ogstream& gout) override;
   
private:
   double timeDilation;
};
