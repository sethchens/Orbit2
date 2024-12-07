#include "Fragment.h"


/*********************************************
* FRAGMENT: move
* overwrite move
*********************************************/
void Fragment::move(double time)
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
* FRAGMENT: draw
* overwrite draw
*********************************************/
void Fragment::draw(ogstream& gout)
{
    if (!isInvisible() && !isDead())
        gout.drawFragment(pos, angle.getRadians());
}
