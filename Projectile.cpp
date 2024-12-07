/***********************************************************************
 * Source File:
 *    PROJECTILE
 * Author:
 *    Chris Mijango & Seth Chen
 * Summary:
 *    A bullet fired from the Dream Chaser that expires after 2 seconds
 ************************************************************************/


#include "Projectile.h"


/*********************************************
* PROJECTILE: move
* overwrite move
*********************************************/
void Projectile::move(double time)
{

    lifetime--;
    if (lifetime <= 0)
    {
        kill();
        return;
    }

    Satellite::move(time * timeDilation);
    angle.add(-angularVelocity * (timeDilation - 1.0));
}

/*********************************************
* PROJECTILE: draw
* overwrite draw
*********************************************/
void Projectile::draw(ogstream& gout)
{
    if (!isInvisible() && !isDead())
        gout.drawProjectile(pos);
}
