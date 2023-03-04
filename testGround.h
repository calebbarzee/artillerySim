/***********************************************************************
 * Header File:
 *    Test Ground : Test the ground class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for the Ground class
 ************************************************************************/


#pragma once

#include "ground.h"
#include <cassert>
#include <vector>


using namespace std;

/*******************************
 * TEST GROUND
 * A friend class for Ground which contains the Ground unit tests
 ********************************/
class TestGround
{
public:
   void run()
   {
      test_constructor();

      test_getElevationMeters_out();
      test_getElevationMeters_two();

      test_reset_two();

      test_getTarget_two();
      test_getTarget_seven();

      test_draw();
   }

private:
   double metersFromPixels = -1.0;

   // Test the default constructor
   void test_constructor()
   {  // setup
      Position posUpperRight;
      double metersFromPixels = posUpperRight.metersFromPixels;
      posUpperRight.metersFromPixels = 1100.0;
      posUpperRight.x = 4400; // 4px
      posUpperRight.y = 5500; // 5px
      // exercise
      Ground g(posUpperRight);
      // verify
      assert(g.iHowitzer == 0);
      assert(g.ground != nullptr);
      assert(g.posUpperRight.x == 4400);
      assert(g.posUpperRight.y == 5500);
      assert(posUpperRight.x == 4400);
      assert(posUpperRight.y == 5500);
      // teardown
      posUpperRight.metersFromPixels = metersFromPixels;
   }  // teardown

   // when the shell is out of range
   void test_getElevationMeters_out()
   {  // setup
      Ground g;
      setupStandardFixture(g);
      Position pos;
      pos.x = -1100.0;
      pos.y = 5500.0;
      // exercise
      double elevation = g.getElevationMeters(pos);
      // verify
      assert(elevation == 0.0);
      verifyStandardFixture(g);
      // teardown
      teardownStandardFixture(g);
   }  

   // The shell is 2 pixels above the ground
   void test_getElevationMeters_two()
   {  // setup
      Ground g;
      setupStandardFixture(g);
      Position pos;
      pos.x = 2200.0;
      pos.y = 9900.0;
      // exercise
      double elevation = g.getElevationMeters(pos);
      // verify
      assert(elevation == 7700.0);  // 7 pixels high or 7700m
      verifyStandardFixture(g);
      // teardown
      teardownStandardFixture(g);
   }  

   // test the ground
   void test_reset_two()
   {  // setup
      Position posHowitzer;
      Ground g;
      setupStandardFixture(g);
      posHowitzer.x = 3300.0;  // 3px
      posHowitzer.y = 4400.0;  // 4px
      // exercise
      g.reset(posHowitzer);
      // verify
      assert(g.iHowitzer == 3);
      assert(g.iTarget >= 0 && g.iTarget < 10);
      assert(g.posUpperRight.x == 11000.0);  // 10px
      assert(g.posUpperRight.y == 11000.0);  // 10px
      assert(g.ground != nullptr);
      if (g.ground != nullptr)
      {
         assert(g.ground[0] >= 0.0 && g.ground[0] < 10.0);
         assert(g.ground[1] >= 0.0 && g.ground[1] < 10.0);
         assert(g.ground[2] >= 0.0 && g.ground[2] < 10.0);
         assert(g.ground[3] >= 0.0 && g.ground[3] < 10.0);
         assert(g.ground[4] >= 0.0 && g.ground[4] < 10.0);
         assert(g.ground[5] >= 0.0 && g.ground[5] < 10.0);
         assert(g.ground[6] >= 0.0 && g.ground[6] < 10.0);
         assert(g.ground[7] >= 0.0 && g.ground[7] < 10.0);
         assert(g.ground[8] >= 0.0 && g.ground[8] < 10.0);
         assert(g.ground[9] >= 0.0 && g.ground[9] < 10.0);
      }
      // teardown
      teardownStandardFixture(g);
   }  


   // The shell is 2 pixels above the ground
   void test_getTarget_two()
   {  // setup
      Position pos;
      Ground g;
      setupStandardFixture(g);
      int iTargetSave = g.iTarget;
      g.iTarget = 2;
      // exercise
      Position posTarget = g.getTarget();
      // verify
      assert(posTarget.x == 2200.0);  // 2px
      assert(posTarget.y == 7700.0);  // 7px
      g.iTarget = iTargetSave;
      verifyStandardFixture(g);
      // teardown
      teardownStandardFixture(g);
   }  

   // The shell is 7 pixels above the ground
   void test_getTarget_seven()
   {  // setup
      Position pos;
      Ground g;
      setupStandardFixture(g);
      int iTargetSave = g.iTarget;
      g.iTarget = 7;
      // exercise
      Position posTarget = g.getTarget();
      // verify
      assert(posTarget.x == 7700.0);  // 7px
      assert(posTarget.y == 2200.0);  // 2px
      g.iTarget = iTargetSave;
      verifyStandardFixture(g);
      // teardown
      teardownStandardFixture(g);
   }  

   // Spy to see exactly what ogstream::draw*() methods are called... and how.
   class ogstreamSpy : public ogstreamDummy
   {
   public:
      // ignore lines
      void drawLine(const Position& begin, const Position& end,
         double red, double green, double blue) { }
      // ignore text
      void drawText(const Position& topLeft, const char* text) { }
      // flush is a no-op
      void flush() { }
      // remember target
      void drawTarget(const Position& pos)
      {
         targets.push_back(pos);
      }
      // remember rectangles
      void drawRectangle(const Position& begin, const Position& end,
         double red, double green, double blue)
      {
         rectanglesBegin.push_back(begin);
         rectanglesEnd.push_back(end);
      }
      vector <Position>  targets;
      vector <Position>  rectanglesBegin;
      vector <Position>  rectanglesEnd;
   };

   // draw
   void test_draw()
   {  // setup
      Position pos;
      Ground g;
      setupStandardFixture(g);
      ogstreamSpy goutSpy;
      // exercise
      g.draw(goutSpy);
      // verify
      assert(goutSpy.targets.size() == 1);
      assert(0.0 <= goutSpy.targets.front().x && goutSpy.targets.front().x < 11000.0);
      assert(0.0 <= goutSpy.targets.front().y && goutSpy.targets.front().y < 11000.0);
      assert(goutSpy.rectanglesBegin.size() == 10);
      assert(goutSpy.rectanglesEnd.size() == 10);
      assert(goutSpy.rectanglesBegin[0].x == 0.0);
      assert(goutSpy.rectanglesBegin[1].x == 1100.0);
      assert(goutSpy.rectanglesBegin[2].x == 2200.0);
      assert(goutSpy.rectanglesBegin[3].x == 3300.0);
      assert(goutSpy.rectanglesBegin[4].x == 4400.0);
      assert(goutSpy.rectanglesBegin[5].x == 5500.0);
      assert(goutSpy.rectanglesBegin[6].x == 6600.0);
      assert(goutSpy.rectanglesBegin[7].x == 7700.0);
      assert(goutSpy.rectanglesBegin[8].x == 8800.0);
      assert(goutSpy.rectanglesBegin[9].x == 9900.0);
      assert(goutSpy.rectanglesBegin[0].y == 0.0);
      assert(goutSpy.rectanglesBegin[1].y == 0.0);
      assert(goutSpy.rectanglesBegin[2].y == 0.0);
      assert(goutSpy.rectanglesBegin[3].y == 0.0);
      assert(goutSpy.rectanglesBegin[4].y == 0.0);
      assert(goutSpy.rectanglesBegin[5].y == 0.0);
      assert(goutSpy.rectanglesBegin[6].y == 0.0);
      assert(goutSpy.rectanglesBegin[7].y == 0.0);
      assert(goutSpy.rectanglesBegin[8].y == 0.0);
      assert(goutSpy.rectanglesBegin[9].y == 0.0);
      assert(goutSpy.rectanglesEnd[0].x == 1100.0);
      assert(goutSpy.rectanglesEnd[1].x == 2200.0);
      assert(goutSpy.rectanglesEnd[2].x == 3300.0);
      assert(goutSpy.rectanglesEnd[3].x == 4400.0);
      assert(goutSpy.rectanglesEnd[4].x == 5500.0);
      assert(goutSpy.rectanglesEnd[5].x == 6600.0);
      assert(goutSpy.rectanglesEnd[6].x == 7700.0);
      assert(goutSpy.rectanglesEnd[7].x == 8800.0);
      assert(goutSpy.rectanglesEnd[8].x == 9900.0);
      assert(goutSpy.rectanglesEnd[9].x == 11000.0);
      assert(goutSpy.rectanglesEnd[0].y == 9900.0);
      assert(goutSpy.rectanglesEnd[1].y == 8800.0);
      assert(goutSpy.rectanglesEnd[2].y == 7700.0);
      assert(goutSpy.rectanglesEnd[3].y == 6600.0);
      assert(goutSpy.rectanglesEnd[4].y == 5500.0);
      assert(goutSpy.rectanglesEnd[5].y == 4400.0);
      assert(goutSpy.rectanglesEnd[6].y == 3300.0);
      assert(goutSpy.rectanglesEnd[7].y == 2200.0);
      assert(goutSpy.rectanglesEnd[8].y == 1100.0);
      assert(goutSpy.rectanglesEnd[9].y == 0.0);
      verifyStandardFixture(g);
      // teardown
      teardownStandardFixture(g);
   }  


   //
   // STANDARD FIXTURE
   //


   // standard fixture: 10 x 10 with howitzer at 5 and target at 7
   void setupStandardFixture(Ground& g)
   {
      metersFromPixels = g.posUpperRight.metersFromPixels;
      g.posUpperRight.metersFromPixels = 1100.0;

      // delete the old
      if (g.ground != nullptr)
         delete [] g.ground;
      g.ground = new double[10];

      for (int i = 0; i < 10; i++)
         g.ground[i] = 9.0 - (double)i;

      g.posUpperRight.x = 11000.0;   // 10 pixels
      g.posUpperRight.y = 11000.0;   // 10 pixels
      g.iHowitzer = 5;
      g.iTarget = 7;
   }

   // verify the standard fixture: 10 x 10 with howitzer at 5 and target at 7
   void verifyStandardFixture(Ground& g)
   {
      assert(g.iHowitzer == 5);
      assert(g.iTarget == 7);
      assert(g.posUpperRight.x == 11000.0);
      assert(g.posUpperRight.y == 11000.0);
      assert(g.posUpperRight.metersFromPixels == 1100.0);
      assert(g.ground != nullptr);
      if (g.ground != nullptr)
      {
         assert(g.ground[0] == 9.0);
         assert(g.ground[1] == 8.0);
         assert(g.ground[2] == 7.0);
         assert(g.ground[3] == 6.0);
         assert(g.ground[4] == 5.0);
         assert(g.ground[5] == 4.0);
         assert(g.ground[6] == 3.0);
         assert(g.ground[7] == 2.0);
         assert(g.ground[8] == 1.0);
         assert(g.ground[9] == 0.0);
      }
   }

   // standard fixture: teardown
   void teardownStandardFixture(Ground& g)
   {
      assert(-1.0 != metersFromPixels);
      g.posUpperRight.metersFromPixels = metersFromPixels;
   }
};
