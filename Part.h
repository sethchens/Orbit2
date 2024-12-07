/***********************************************************************
 * Header File:
 *    Part
 * Author:
 *    Chris Mijango & Seth Chen
 * Summary:
 *    Base class for satellite parts that break off during collision
 ************************************************************************/


#pragma once
#include "satellite.h"
#include "velocity.h"
#include "Fragment.h"
#include "angle.h"


class Part : public Satellite
{
    friend TestPart;
public:
    Part(double radius, double angularVelocity, const Satellite& parent) :
        Satellite(0, radius, angularVelocity)
    {
       // Set position offset from parent
       this->pos = parent.getPosition();
       Position posKick;
       posKick.setPixelsX(4.0 * sin(parent.getAngle().getRadians()));
       posKick.setPixelsY(4.0 * cos(parent.getAngle().getRadians()));
       pos.addMetersX(posKick.getMetersX());
       pos.addMetersY(posKick.getMetersY());

       // Set velocity with random kick
       this->velocity = parent.velocity;
       double speed = random(1000.0, 3000.0);
       Velocity kick;
       kick.set(parent.getAngle().getRadians(), speed);
       velocity.add(kick);
       
      this->timeDilation = 48.0;
    }

   virtual void move(double time) override;

protected:
   void createFragments(std::list<Satellite*>& satellites, int count);

    double timeDilation;
};

