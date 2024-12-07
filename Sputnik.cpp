/***********************************************************************
 * Source File:
 *    SPUTNIK
 * Author:
 *    Chris Mijango & Seth Chen
 * Summary:
 *    The first artificial satellite in space
 ************************************************************************/


#include "Sputnik.h"


/*********************************************
* SPUTNIK: move
* overwrite move
*********************************************/
void Sputnik::move(double time)
{
    // Scale time by dilation factor for orbital motion
    Satellite::move(time * timeDilation);

    // Reset angle change to remove time dilation effect on rotation
    angle.add(-angularVelocity * (timeDilation - 1.0));  // Counteract the extra rotation
}


/*********************************************
* SPUTNIK: draw
* overwrite draw
*********************************************/
void Sputnik::draw(ogstream& gout)
{
    if (!isInvisible() && !isDead())
        gout.drawSputnik(pos, angle.getRadians());
}

/*********************************************
* SPUTNIK: destroy
* overwrite destroy
*********************************************/
void Sputnik::destroy(std::list<Satellite*>& satellites)
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
           for (int i = 0; i < 4; i++)
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
