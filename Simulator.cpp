/***********************************************************************
 * Source File:
 *    SIMULATOR
 * Author:
 *    Chris Mijangos and Seth Chen
 * Summary:
 *    The main simulator class that handles the orbital simulation
 ************************************************************************/
#include "uiInteract.h"
#include "uiDraw.h"
#include "position.h"
#include "sputnik.h"
#include "test.h"
#include "hubble.h"
#include "starlink.h"
#include "crewDragon.h"
#include "GPS.h"
#include "Ship.h"
using namespace std;

/*********************************************
 * SIMULATOR
 * The main simulator class
 *********************************************/
class Simulator
{
   public:
   // Constructor initializes the simulation
   Simulator(Position ptUpperRight) :
   ptUpperRight(ptUpperRight)
   {
      
      // Initialize satellites list with initial satellites
      satellites.push_back(new Sputnik());
      satellites.push_back(new Hubble());
      satellites.push_back(new Starlink());
      satellites.push_back(new CrewDragon());
      satellites.push_back(new GPS());
      satellites.push_back(new GPS(GPS().getInitialPositions()[1].first, GPS().getInitialPositions()[1].second));
      satellites.push_back(new GPS(GPS().getInitialPositions()[2].first, GPS().getInitialPositions()[2].second));
      satellites.push_back(new GPS(GPS().getInitialPositions()[3].first, GPS().getInitialPositions()[3].second));
      satellites.push_back(new GPS(GPS().getInitialPositions()[4].first, GPS().getInitialPositions()[4].second));
      satellites.push_back(new GPS(GPS().getInitialPositions()[5].first, GPS().getInitialPositions()[5].second));
      satellites.push_back(new Ship(satellites));
      
      // Initialize the random stars
      for (int i = 0; i < NUM_STARS; i++)
      {
         Position pt;
         pt.setPixelsX(random(-ptUpperRight.getPixelsX(), ptUpperRight.getPixelsX()));
         pt.setPixelsY(random(-ptUpperRight.getPixelsY(), ptUpperRight.getPixelsY()));
         stars[i] = pt;
         phases[i] = random(0, 255);  // Random initial phase for twinkling
      }
   }
   
   /*********************************************
    * SIMULATOR: destructor
    *********************************************/
   ~Simulator() {}
   
   /*********************************************
    * SIMULATOR: update
    *********************************************/
   void update(const Interface& pUI)
   {
      
      for (Satellite* satellite : satellites)
      {
         if (!satellite->isDead())
         {
            satellite->move(1.0);
            satellite->destroy(satellites);
         }
      }
      
      auto itShip = satellites.begin();
      std::advance(itShip, 10);
      if ((*itShip) && !(*itShip)->isDead())
      {
         (*itShip)->input(pUI);
      }
      
      // Update star phases for twinkling
      for (int i = 0; i < NUM_STARS; i++)
         phases[i] = (phases[i] + 1) % 256;
   }
   
   /*********************************************
    * SIMULATOR: destructor
    *********************************************/
   void draw(ogstream& gout)
   {
      // Draw the stars first (background)
      for (int i = 0; i < NUM_STARS; i++)
         gout.drawStar(stars[i], phases[i]);
      
      // Draw stationary Earth
      Position posEarth;
      gout.drawEarth(posEarth, 0.0);
      
      for (Satellite* satellite : satellites)
      {
         if (!satellite->isDead())
         {
            satellite->draw(gout);
         }
      }
      
      
   }
   
   private:
   Position ptUpperRight;         // Size of the screen
   std::list<Satellite*> satellites;
   static const int NUM_STARS = 100;
   Position stars[NUM_STARS];     // Array of star positions
   uint8_t phases[NUM_STARS];     // Array of star phases
};

/*************************************
 * CALLBACK
 * Handle all the frames by moving everything and drawing
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // Cast the void pointer to a simulator object
   Simulator* pSim = (Simulator*)p;
   
   // Update the simulation
   pSim->update(*pUI);
   
   // Draw everything
   Position pos;  // Center of the screen
   ogstream gout(pos);
   pSim->draw(gout);
}

/*********************************
 * Main handles command line parameters and creates the game
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
                    _In_ HINSTANCE hInstance,
                    _In_opt_ HINSTANCE hPrevInstance,
                    _In_ PWSTR pCmdLine,
                    _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Run unit tests first
   testRunner();
   
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   
   // Initialize the game
   Interface ui(argc, argv, "Orbital Simulator", ptUpperRight);
   Simulator sim(ptUpperRight);
   
   // Play the game
   ui.run(callBack, &sim);
   
   return 0;
}
