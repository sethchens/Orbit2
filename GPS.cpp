#include "GPS.h"

/*********************************************
* GPS CENTER: draw
* overwrite draw
*********************************************/
void GPSCenter::draw(ogstream& gout)
{
    if (!isDead())
        gout.drawGPSCenter(pos, angle.getRadians());
}

/*********************************************
* GPS CENTER: destroy
* overwrite destroy
*********************************************/
void GPSCenter::destroy(std::list<Satellite*>& satellites)
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
* GPS LEFT: draw
* overwrite draw
*********************************************/
void GPSLeftArray::draw(ogstream& gout)
{
   if (!isInvisible() && !isDead())
    {
        Position offset;
        offset.setPixelsX(0.0);
        offset.setPixelsY(-12.0);
        gout.drawGPSLeft(pos, angle.getRadians(), offset);
    }
}

/*********************************************
* GPS LEFT: destroy
* overwrite destroy
*********************************************/
void GPSLeftArray::destroy(std::list<Satellite*>& satellites)
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
* GPS RIGHT: draw
* overwrite draw
*********************************************/
void GPSRightArray::draw(ogstream& gout)
{
    if (!isDead())
    {
        Position offset;
        offset.setPixelsX(0.0);
        offset.setPixelsY(12.0);
        gout.drawGPSRight(pos, angle.getRadians(), offset);
    }
}

/*********************************************
* GPS RIGHT: destroy
* overwrite destroy
*********************************************/
void GPSRightArray::destroy(std::list<Satellite*>& satellites)
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
* GPS: destroy
* overwrite destroy
*********************************************/
void GPS::destroy(std::list<Satellite*>& satellites)
{
   auto it = satellites.begin();
   std::advance(it, 10);
   for (; it != satellites.end(); ++it)
   {
      if ((this->getPosition().getMetersX() - (*it)->getPosition().getMetersX()) *
         (this->getPosition().getMetersX() - (*it)->getPosition().getMetersX()) +
         (this->getPosition().getMetersY() - (*it)->getPosition().getMetersY()) *
         (this->getPosition().getMetersY() - (*it)->getPosition().getMetersY()) <=
         (this->getRadius() + (*it)->getRadius()) * (this->getRadius() + (*it)->getRadius())
      )
      {
         if (!isDead() && !(*it)->isDead())
         {
            satellites.push_back(new GPSCenter(*this));
            satellites.push_back(new GPSLeftArray(*this));
            satellites.push_back(new GPSRightArray(*this));
            
            // Create fragments
            createFragments(satellites, 2);
            kill();
            (*it)->kill();
         }
      }
   }
}

/*********************************************
* GPS: move
* overwrite move
*********************************************/
void GPS::move(double time)
{
   Satellite::move(time * timeDilation);
   angle.add(-angularVelocity * (timeDilation - 1.0));
}

/*********************************************
* GPS: draw
* overwrite draw
*********************************************/
void GPS::draw(ogstream& gout)
{
   if (!isInvisible() && !isDead())
      gout.drawGPS(pos, angle.getRadians());
}

/*********************************************
* GPS: createFragment
* overwrite createFragment
*********************************************/
void GPS::createFragments(std::list<Satellite*>& satellites, int count)
{
   for (int i = 0; i < count; i++)
   {
      Angle fragmentAngle;
      fragmentAngle.setDegrees(random(0.0, 360.0));
      satellites.push_back(new Fragment(*this, fragmentAngle));
   }
}
