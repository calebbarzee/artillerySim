#pragma once

#include "position.h"
#include "ground.h"
#include "projectile.h"
#include "uiDraw.h"
#include "uiInteract.h"

class TestArtillery;

class Artillery
{
public:
  friend class TestArtillery;
   Artillery() : position(Position()), elevation(M_PI_4), timeSinceFire(-1) {};
   Artillery(Position pos) : position(pos), elevation(M_PI_4), timeSinceFire(-1){};
  void generateXPosition(const Position & pos);
  void generateYPosition(const Ground & ground);
  void moveRight();
  void moveLeft();
  void moveUp();
  void moveDown();
  void setElevation(double elevation) { this->elevation = elevation; }
  void setPosition(Position position) { this->position = position; }
   void setTimeSinceFire(double time) { this->timeSinceFire = time; }
  Position getPosition() const { return position; }
  double getElevation() const { return elevation; }
  double getMuzzleVelocity() const { return muzzleVelocity; }
   double getTimeSinceFire() const { return timeSinceFire; }

  void fireShell();
  void update(const Interface* pUI);
  void draw(ogstream & gout);

  Projectile shell;
private:
  constexpr static double muzzleVelocity = 827.0;
  Position position;
  double elevation;
  double timeSinceFire;
};
