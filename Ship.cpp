/***********************************************************************
 * Source File:
 *    SHIP
 * Author:
 *    Chris Mijango & Seth Chen
 * Summary:
 *    The ship class
 ************************************************************************/


#include "Ship.h"


/*********************************************
* SHIP: draw
* overwrite draw
*********************************************/
void Ship::draw(ogstream& gout)
{
    if (!isInvisible() && !isDead())
        gout.drawShip(pos, angle.getRadians(), isThrusting);
}

/*********************************************
* SHIP: input
* overwrite input
*********************************************/
void Ship::input(const Interface& ui)
{
   if (getDefunct() == false)
   {
      // Rotate 0.1 radians left or right based on input
      if (ui.isRight())
         this->angle.add(0.1);
      if (ui.isLeft())
         this->angle.add(-0.1);
      
      // Track thrust state for drawing
      isThrusting = ui.isDown();
      
      if (isThrusting)
      {
         // Calculate thrust effect based on the direction the ship is pointing
         Acceleration thrust;
         
         // Apply 2.0 m/s² thrust in the ship's current direction
         thrust.setDDX(2.0 * sin(angle.getRadians()));
         thrust.setDDY(2.0 * cos(angle.getRadians()));
         
         // Apply single velocity update with 48 second time dilation
         velocity.addDX(thrust.getDDX() * 48.0);
         velocity.addDY(thrust.getDDY() * 48.0);
         
         // Update position with new velocity
         pos.addMetersX(velocity.getDX());
         pos.addMetersY(velocity.getDY());
      }
      
      // Fire projectile when space is pressed
      if (ui.isSpace() && !isDead() && !isInvisible())
      {
         
         Projectile* projectile = new Projectile(*this, angle.getRadians());
         satellites.push_back(projectile);
         
         // Debug log
         std::cout << "Projectile fired! Current satellite count: " << satellites.size() << std::endl;
         
      }
   }
}

/*********************************************
* SHIP: move
* overwrite move
*********************************************/
void Ship::move(double time)
{
    Satellite::move(48.0);

    // Reset angle change to remove time dilation effect on rotation
    angle.add(-angularVelocity * (48.0 - 1.0));
}


/*********************************************
* SHIP: destroy
* overwrite destroy
*********************************************/
void Ship::destroy(std::list<Satellite*>& satellites)
{
   int count = 0;
   for (auto it = satellites.begin(); it != satellites.end(); ++it)
   {
      count ++;
      if (count == 11) continue;
      if ((getPosition().getMetersX() - (*it)->getPosition().getMetersX()) *
          (getPosition().getMetersX() - (*it)->getPosition().getMetersX()) +
          (getPosition().getMetersY() - (*it)->getPosition().getMetersY()) *
          (getPosition().getMetersY() - (*it)->getPosition().getMetersY()) <=
          (getRadius() + (*it)->getRadius()) * (getRadius() + (*it)->getRadius())
          )
      {
         if (!isDead() && !(*it)->isDead())
         {
            kill();
            (*it)->kill();
         }
      }
         
   }
}

/*********************************************
* FAKE SHIP: input
* overwrite input
*********************************************/
void FakeShip::input(bool isRight, bool isLeft, bool isDown, bool isSpace)
{
   if (isRight)
      this->angle.add(0.1);
   if (isLeft)
      this->angle.add(-0.1);
   
   if (isDown)
   {
      // Calculate thrust effect based on the direction the ship is pointing
      Acceleration thrust;
      for (int i = 0; i < 48; i++)
      {
         thrust.setDDX(2.0 * sin(angle.getRadians()));
         thrust.setDDY(2.0 * cos(angle.getRadians()));
         
         // udpate velocity
         velocity.addDX(thrust.getDDX() * 1.0);  // v = v0 + at
         velocity.addDY(thrust.getDDY() * 1.0);
         
         // Update the position using the current velocity
         pos.addMetersX(velocity.getDX() * 1.0);   // x = x0 + vt
         pos.addMetersY(velocity.getDY() * 1.0);
      }
   }
}
