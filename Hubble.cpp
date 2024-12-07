/***********************************************************************
 * Source File:
 *    Hubble
 * Author:
 *    Chris Mijango & Seth Chen
 * Summary:
 *    Hubble class
 ************************************************************************/


#include "Hubble.h"

/*********************************************
* HUBBLE TELESCOPE: draw
* overwrite draw
*********************************************/
void HubbleTelescope::draw(ogstream& gout)
{
    if (!isInvisible() && !isDead())
        gout.drawHubbleTelescope(pos, angle.getRadians());
}

/*********************************************
* HUBBLE TELESCOPE: destroy
* overwrite destroy
*********************************************/
void HubbleTelescope::destroy(std::list<Satellite*>& satellites)
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
* HUBBLE COMPUTER: draw
* overwrite draw
*********************************************/
void HubbleComputer::draw(ogstream& gout)
{
    if (!isInvisible() && !isDead())
        gout.drawHubbleComputer(pos, angle.getRadians());
}

/*********************************************
* HUBBLE COMPUTER: destroy
* overwrite destroy
*********************************************/
void HubbleComputer::destroy(std::list<Satellite*>& satellites)
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
            createFragments(satellites, 2);
            kill();
            (*it)->kill();
         }
      }
   }
}

/*********************************************
* HUBBLE LEFT ARRAY: draw
* overwrite draw
*********************************************/
void HubbleLeftArray::draw(ogstream& gout)
{
    if (!isInvisible() && !isDead())
        gout.drawHubbleLeft(pos, angle.getRadians());
}

/*********************************************
* HUBBLE LEFT ARRAY: destroy
* overwrite destroy
*********************************************/
void HubbleLeftArray::destroy(std::list<Satellite*>& satellites)
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
            createFragments(satellites, 2);
            kill();
            (*it)->kill();
         }
      }
   }
}

/*********************************************
* HUBBLE RIGHT ARRAY: draw
* overwrite draw
*********************************************/
void HubbleRightArray::draw(ogstream& gout)
{
    if (!isInvisible() && !isDead())
        gout.drawHubbleRight(pos, angle.getRadians());
}

/*********************************************
* HUBBLE RIGHT ARRAY: destroy
* overwrite destroy
*********************************************/
void HubbleRightArray::destroy(std::list<Satellite*>& satellites)
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
            createFragments(satellites, 2);
            kill();
            (*it)->kill();
         }
      }
   }
}

/*********************************************
* HUBBLE: destroy
* overwrite destroy
*********************************************/
void Hubble::destroy(std::list<Satellite*>& satellites)
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
            // Create component parts
            satellites.push_back(new HubbleTelescope(*this));
            satellites.push_back(new HubbleComputer(*this));
            satellites.push_back(new HubbleLeftArray(*this));
            satellites.push_back(new HubbleRightArray(*this));
            
            kill();
            (*it)->kill();
         }
      }
   }
}

/*********************************************
* HUBBLE: move
* overwrite move
*********************************************/
void Hubble::move(double time)
{
   Satellite::move(time * timeDilation);
   angle.add(-angularVelocity * (timeDilation - 1.0));
}

/*********************************************
* HUBBLE: draw
* overwrite draw
*********************************************/
void Hubble::draw(ogstream& gout)
{
   if (!isInvisible() && !isDead())
      gout.drawHubble(pos, angle.getRadians());
}
