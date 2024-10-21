#pragma once

#include "Vector2.hpp"
#include <deque>
#include <list>
#include <queue>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <stack>

namespace Graphics {

class LinearStructuresGraphics {
protected:
  raylib::Vector2 nodeCenter;
  int nodeRadius;
  int nodeGap; // distance between the nodes
  int fontSize;
  raylib::Color fontColor;
  raylib::Color outlineColor;

  virtual void Draw() = 0;
  virtual ~LinearStructuresGraphics() = default;
};

class StackGraphics : public LinearStructuresGraphics {
public:
  std::stack<int> stack;

  StackGraphics(int fontSize = 20,
                raylib::Vector2 nodeCenter = {(float)GetScreenWidth() / 2,
                                              (float)GetScreenHeight()},
                int nodeRadius = 30, int nodeGap = -75,
                raylib::Color fontColor = raylib::Color::Red(),
                raylib::Color outlineColor = raylib::Color::Red());

  void Draw();
};

class QueueGraphics : public LinearStructuresGraphics {
public:
  std::queue<int> queue;

  QueueGraphics(int fontSize = 20,
                raylib::Vector2 nodeCenter = {(float)GetScreenWidth() - 40,
                                              (float)GetScreenHeight() / 2},
                int nodeRadius = 30, int nodeGap = -75,
                raylib::Color fontColor = raylib::Color::Red(),
                raylib::Color outlineColor = raylib::Color::Red());

  void Draw();
};

class DequeGraphics : public LinearStructuresGraphics {
public:
  std::deque<int> deque;

  DequeGraphics(int fontSize = 20,
                raylib::Vector2 nodeCenter = {(float)GetScreenWidth() - 40,
                                              (float)GetScreenHeight() / 2},
                int nodeRadius = 30, int nodeGap = -75,
                raylib::Color fontColor = raylib::Color::Red(),
                raylib::Color outlineColor = raylib::Color::Red());

  void Draw();
};
class ListGraphics : public LinearStructuresGraphics {
public:
  std::list<int> list;

  ListGraphics(int fontSize = 20,
               raylib::Vector2 nodeCenter = {(float)GetScreenWidth() - 40,
                                             (float)GetScreenHeight() / 2},
               int nodeRadius = 30, int nodeGap = -75,
               raylib::Color fontColor = raylib::Color::Red(),
               raylib::Color outlineColor = raylib::Color::Red());

  void Draw();
};
int CenterNodeText(std::string nodeText, float nodeTextWidth, float nodeRadius,
                   int fontSize);

double ToRadians(double degree);

void DrawArrows(raylib::Vector2 nodeCenter, raylib::Vector2 previousNodeCenter,
                int nodeRadius, raylib::Color arrowColor);
} // namespace Graphics
