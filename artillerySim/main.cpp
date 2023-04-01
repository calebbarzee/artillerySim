/*************************************************************
 * 1. Name:
 *      The Key
 * 2. Assignment Name:
 *      Lab 08: M777 Artillery
 * 3. Assignment Description:
 *      Simulate firing the M777 artillery 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/
#pragma once

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
#include "artillery.h"
#include "test.h"
#include <iostream>


using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{
public:
   Simulator(Position ptUpperRight) : ptUpperRight(ptUpperRight), ground(ptUpperRight)
   {
      artillery = Artillery();
      artillery.generatePosition(ptUpperRight);
      Position artilleryPos = artillery.getPosition();
      ground.reset(artilleryPos);
   }
   const double timeInterval = 2; // simulation runs 2 seconds per frame 30 frames per second
   Ground ground;                 // the ground
   Artillery artillery;             // the artillery object
   Position  ptUpperRight;        // size of the screen
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.
   Simulator* pSimulator = (Simulator*)p;

   pSimulator->artillery.update(*pUI);

   if(pSimulator->artillery.shell.getStatus() == Status::IN_FLIGHT)
      pSimulator->artillery.shell.advance(pSimulator->ground);

   ogstream gout(Position(10.0, pSimulator->ptUpperRight.getPixelsY() - 20.0));

   // draw the ground first
   pSimulator->ground.draw(gout);

   // draw the artillery
   pSimulator->artillery.draw(gout);

   // draw the projectile
   pSimulator->artillery.shell.draw(gout);

   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time since the bullet was fired: "
      << pSimulator->artillery.shell.getElapsedTime() << "s\n";
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
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
   testRunner();
   cout << "All tests passed." << endl;

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setPixelsX(700.0);
   ptUpperRight.setPixelsY(500.0);
   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
   Interface ui(0, NULL,
      "M777 Artillery Simulator",   /* name on the window */
      ptUpperRight);

   // Initialize the simulator
   Simulator simulator(ptUpperRight);

   // set everything into action
   ui.run(callBack, &simulator);


   return 0;
}

