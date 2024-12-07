#include "CrewDragon.h"


/******************************************
 * CREW DRAGON CENTER: draw
 * overwrite draw
 *****************************************/
void CrewDragonCenter::draw(ogstream& gout)
{
   if (!isInvisible() && !isDead())
      gout.drawCrewDragonCenter(pos, angle.getRadians());
}

/******************************************
 * CREW DRAGON CENTER: destroy
 * overwrite destroy
 *****************************************/
void CrewDragonCenter::destroy(std::list<Satellite*>& satellites)
{
   auto it = satellites.begin();
   std::advance(it, 10);
   for (; it != satellites.end(); ++it)
   {
      if ((getPosition().getMetersX() - (*it)->getPosition().getMetersX()) *
          (getPosition().getMetersX() - (*it)->getPosition().getMetersX()) +
          (getPosition().getMetersY() - (*it)->getPosition().getMetersY()) *
          (getPosition().getMetersY() - (*it)->getPosition().getMetersY()) <=
          (getRadius() + (*it)->getRadius()) * (getRadius() + (*it)->getRadius())
          )
      {
         if (!isDead())
         {
            // Create fragments
            createFragments(satellites, 4);
            dead = true;
         }
      }
   }
}

/******************************************
 * CREW DRAGON LEFT: draw
 * overwrite draw
 *****************************************/
void CrewDragonLeft::draw(ogstream& gout)
{
   if (!isInvisible() && !isDead())
      gout.drawCrewDragonLeft(pos, angle.getRadians());
}

/******************************************
 * CREW DRAGON LEFT: destroy
 * overwrite destroy
 *****************************************/
void CrewDragonLeft::destroy(std::list<Satellite*>& satellites)
{
   auto it = satellites.begin();
   std::advance(it, 10);
   for (; it != satellites.end(); ++it)
   {
      if ((getPosition().getMetersX() - (*it)->getPosition().getMetersX()) *
          (getPosition().getMetersX() - (*it)->getPosition().getMetersX()) +
          (getPosition().getMetersY() - (*it)->getPosition().getMetersY()) *
          (getPosition().getMetersY() - (*it)->getPosition().getMetersY()) <=
          (getRadius() + (*it)->getRadius()) * (getRadius() + (*it)->getRadius())
          )
      {
         if (!isDead())
         {
            // Create fragments
            createFragments(satellites, 2);
            dead = true;
         }
      }
   }
}

/******************************************
 * CREW DRAGON RIGHT: draw
 * overwrite draw
 *****************************************/
void CrewDragonRight::draw(ogstream& gout)
{
   if (!isInvisible() && !isDead())
      gout.drawCrewDragonRight(pos, angle.getRadians());
}

/******************************************
 * CREW DRAGON RIGHT: destroy
 * overwrite destroy
 *****************************************/
void CrewDragonRight::destroy(std::list<Satellite*>& satellites)
{
   auto it = satellites.begin();
   std::advance(it, 10);
   for (; it != satellites.end(); ++it)
   {
      if ((getPosition().getMetersX() - (*it)->getPosition().getMetersX()) *
          (getPosition().getMetersX() - (*it)->getPosition().getMetersX()) +
          (getPosition().getMetersY() - (*it)->getPosition().getMetersY()) *
          (getPosition().getMetersY() - (*it)->getPosition().getMetersY()) <=
          (getRadius() + (*it)->getRadius()) * (getRadius() + (*it)->getRadius())
          )
      {
         if (!isDead())
         {
            // Create fragments
            createFragments(satellites, 2);
            dead = true;
         }
      }
   }
}

/******************************************
 * CREW DRAGON: move
 * overwrite move
 *****************************************/
void CrewDragon::move(double time)
{
   // Scale time by dilation factor for orbital motion
   Satellite::move(time * timeDilation);
   
   // Reset angle change to remove time dilation effect on rotation
   angle.add(-angularVelocity * (timeDilation - 1.0));
}

/******************************************
 * CREW DRAGON: destroy
 * overwrite destroy
 *****************************************/
void CrewDragon::destroy(std::list<Satellite*>& satellites)
{
   auto it = satellites.begin();
   std::advance(it, 10);
   for (; it != satellites.end(); ++it)
   {
      if ((getPosition().getMetersX() - (*it)->getPosition().getMetersX()) *
          (getPosition().getMetersX() - (*it)->getPosition().getMetersX()) +
          (getPosition().getMetersY() - (*it)->getPosition().getMetersY()) *
          (getPosition().getMetersY() - (*it)->getPosition().getMetersY()) <=
          (getRadius() + (*it)->getRadius()) * (getRadius() + (*it)->getRadius())
          )
      {
         if (!isDead())
         {
            satellites.push_back(new CrewDragonCenter(*this));
            satellites.push_back(new CrewDragonLeft(*this));
            satellites.push_back(new CrewDragonRight(*this));
            
            // Create fragments
            for (int i = 0; i < 2; i++)
            {
               Angle fragmentAngle;
               fragmentAngle.setDegrees(random(0.0, 360.0));
               satellites.push_back(new Fragment(*this, fragmentAngle));
            }
            dead = true;
         }
      }
   }
}

/******************************************
 * CREW DRAGON: draw
 * overwrite draw
 *****************************************/
void CrewDragon::draw(ogstream& gout)
{
   if (!isInvisible() && !isDead())
      gout.drawCrewDragon(pos, angle.getRadians());
}
