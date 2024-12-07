#include "Part.h"


/*********************************************
* PART: move
* overwrite move
*********************************************/
void Part::move(double time)
{
    Satellite::move(time * timeDilation);
    angle.add(-angularVelocity * (timeDilation - 1.0));
}

/*********************************************
* PART: createFragment
* overwrite createFragment
*********************************************/
void Part::createFragments(std::list<Satellite*>& satellites, int count)
{
    for (int i = 0; i < count; i++)
    {
        Angle fragmentAngle;
        fragmentAngle.setDegrees(random(0.0, 360.0));
        satellites.push_back(new Fragment(*this, fragmentAngle));
    }
}
