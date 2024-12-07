/***********************************************************************
 * Header File:
 *    SHIP
 * Author:
 *    Chris Mijango & Seth Chen
 * Summary:
 *    The ship class
 ************************************************************************/


#pragma once
#include "acceleration.h"
#include "Satellite.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "Projectile.h"

class TestShip;

class Ship : public Satellite
{
   
private:
   bool isThrusting;  // Track if engines are firing
   std::list<Satellite*>& satellites; // Reference to satellite list for projectiles
   
public:
   friend TestShip;
   
   // constructor
   Ship(std::list<Satellite*>& satellites) :
   Satellite(0, 10.0, 0.0),
   isThrusting(false),
   satellites(satellites)
   {
      pos.setPixelsX(-450.0);
      pos.setPixelsY(450.0);
      velocity.setDX(0.0);
      velocity.setDY(-2000.0);
      angle.setDown();
   }
   
   void draw(ogstream& gout) override;
   void input(const Interface& ui) override;
   void move(double time) override;
   void destroy(std::list<Satellite*>& satellites) override;
   bool getDefunct() override { return dead; }
};

class FakeShip : public Satellite
{
public:
   FakeShip() : Satellite(0, 10.0, 0.0)
   {
      pos.setPixelsX(-450.0);
      pos.setPixelsY(450.0);
      velocity.setDX(0.0);
      velocity.setDY(-2000.0);
      angle.setDown();
   }
   
   void input(bool isRight, bool isLeft, bool isDown, bool isSpace);
};

