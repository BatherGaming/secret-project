#ifndef __GENERAL_H__
#define __GENERAL_H__

#include <bits/stdc++.h>

class Game;
class Background;
class Platform;
class Player;

struct Point {double x, y; };
struct Rectangle { double x1, y1, x2, y2; };
struct Color { int red, green, blue; };

const double kMaxCoordinate = 1;

const double kWheelCenterX = -0.25;
const double kWheelCenterY = 0;
const double kWheelRadius = 0.6;
const double kWheelAngVelocity = 1;

const double kPlatformLength = 0.10;
const double kPlatformWidth = 0.05;

const double kPI = atan2(0., -1.);

const size_t kNumOfPlatforms = 2;
const size_t kNumOfPlayers = 2;

const size_t kBackgroundDepth = 0;
const size_t kPlatformDepth = 1; 
#endif
