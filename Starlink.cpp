/***********************************************************************
 * Source File:
 *    STARLINK
 * Author:
 *    Chris Mijango & Seth Chen
 * Summary:
 *    Body component of a destroyed Starlink satellite
 ************************************************************************/


#include "Starlink.h"


/*********************************************
* STARLINK BODY: draw
* overwrite draw
*********************************************/
void StarlinkBody::draw(ogstream& gout)
{
   if (!isInvisible() && !isDead())
      gout.drawStarlinkBody(pos, angle.getRadians());
}

/*********************************************
* STARLINK BODY : destroy
* overwrite destroy
*********************************************/
void StarlinkBody::destroy(std::list<Satellite*>& satellites)
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
         if (!isDead() && !(*it)->isDead())
         {
            // Create fragments
            createFragments(satellites, 3);
            kill();
            (*it)->kill();
         }
      }
   }
}


/*********************************************
* STARLINK ARRAY: draw
* overwrite draw
*********************************************/
void StarlinkArray::draw(ogstream& gout)
{
   if (!isInvisible() && !isDead())
      gout.drawStarlinkArray(pos, angle.getRadians());
}

/*********************************************
* STARLINK ARRAY : destroy
* overwrite destroy
*********************************************/
void StarlinkArray::destroy(std::list<Satellite*>& satellites)
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
         if (!isDead() && !(*it)->isDead())
         {
            // Create fragments
            createFragments(satellites, 3);
            kill();
            (*it)->kill();
         }
      }
   }
}

/*********************************************
* STARLINK : move
* overwrite move
*********************************************/
void Starlink::move(double time)
{
   // Scale time by dilation factor for orbital motion
   Satellite::move(time * timeDilation);
   
   // Reset angle change to remove time dilation effect on rotation
   angle.add(-angularVelocity * (timeDilation - 1.0));
}

/*********************************************
* STARLINK : destroy
* overwrite destroy
*********************************************/
void Starlink::destroy(std::list<Satellite*>& satellites)
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
         if (!isDead() && !(*it)->isDead())
         {
            satellites.push_back(new StarlinkBody(*this));
            satellites.push_back(new StarlinkArray(*this));
            
            // Create fragments
            for (int i = 0; i < 2; i++)
            {
               Angle fragmentAngle;
               fragmentAngle.setDegrees(random(0.0, 360.0));
               satellites.push_back(new Fragment(*this, fragmentAngle));
            }
            kill();
            (*it)->kill();
         }
      }
   }
}

/*********************************************
* STARLINK: draw
* overwrite draw
*********************************************/
void Starlink::draw(ogstream& gout)
{
   if (!isInvisible() && !isDead())
      gout.drawStarlink(pos, angle.getRadians());
}
