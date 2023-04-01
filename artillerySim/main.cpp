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

#include <iostream>
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
#include "artillery.h"
#include "simulator.h"
#include "test.h"

void callBack(const Interface* pUI, void* p)
{
   ogstream gout;
   Simulator* pSimulator = (Simulator*)p;
   
   pSimulator->input(pUI);
   pSimulator->update();
   pSimulator->draw(gout);
}

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
   // run unit tests
   testRunner();
   std::cout << "All tests passed.\n";

   // Initialize OpenGL
   Position ptUpperRight;
   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
   ptUpperRight.setPixelsX(700.0);
   ptUpperRight.setPixelsY(500.0);
   Interface ui(0, NULL, "M77 Howitzer Artillery Simulation", ptUpperRight);

   // Initialize the demo
   Simulator sim(ptUpperRight);

   // set everything into action
   ui.run(callBack, &sim); // getting a bad reference error (zombie)
   return 0;
}
