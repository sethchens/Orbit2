#pragma once
#include "satellite.h"
#include "velocity.h"
#include "part.h"
#include "uiDraw.h"
#include <vector>
#include "Fragment.h"
#include <list>
#include <iterator>

class TestGPS;

/*********************************************
* GPS CENTER
* Center component of a destroyed GPS satellite
*********************************************/
class GPSCenter : public Part
{
public:
    GPSCenter(const Satellite& parent) : Part(7.0, 0.001, parent) {}

   virtual void draw(ogstream& gout) override;
   virtual void destroy(std::list<Satellite*>& satellites) override;
};

/*********************************************
* GPS LEFT ARRAY
* Left solar array of a destroyed GPS satellite
*********************************************/
class GPSLeftArray : public Part
{
public:
    GPSLeftArray(const Satellite& parent) : Part(8.0, 0.001, parent) {}

   virtual void draw(ogstream& gout) override;
   virtual void destroy(std::list<Satellite*>& satellites) override;
};

/*********************************************
* GPS RIGHT ARRAY
* Right solar array of a destroyed GPS satellite
*********************************************/
class GPSRightArray : public Part
{
public:
    GPSRightArray(const Satellite& parent) : Part(8.0, 0.001, parent) {}

   virtual void draw(ogstream& gout) override;
   virtual void destroy(std::list<Satellite*>& satellites) override;
};

/*********************************************
* GPS
* GPS satellite in medium Earth orbit
*********************************************/
class GPS : public Satellite
{
public:
    friend TestGPS;

    GPS(const Position& pos, const Velocity& vel) :
        Satellite(0, 12.0, 0.001)
    {
        this->pos = pos;
        this->velocity = vel;
        timeDilation = 48.0;
    }

    GPS() : GPS(
        Position(0.0, 26560000.0),
        Velocity(-3880.0, 0.0)
    ) {}

    static std::vector<std::pair<Position, Velocity>> getInitialPositions()
    {
        return {
            {Position(0.0, 26560000.0), Velocity(-3880.0, 0.0)},
            {Position(23001634.72, 13280000.0), Velocity(-1940.00, 3360.18)},
            {Position(23001634.72, -13280000.0), Velocity(1940.00, 3360.18)},
            {Position(0.0, -26560000.0), Velocity(3880.0, 0.0)},
            {Position(-23001634.72, -13280000.0), Velocity(1940.00, -3360.18)},
            {Position(-23001634.72, 13280000.0), Velocity(-1940.00, -3360.18)}
        };
    }

   virtual void destroy(std::list<Satellite*>& satellites) override;
   virtual void move(double time) override;
   virtual void draw(ogstream& gout) override;

protected:
   void createFragments(std::list<Satellite*>& satellites, int count);

private:
    double timeDilation;
};
