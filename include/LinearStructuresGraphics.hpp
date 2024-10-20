#pragma once

#include "Vector2.hpp"
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
                int nodeRadius = 30, int nodeGap = 75,
                raylib::Color fontColor = raylib::Color::Red(),
                raylib::Color outlineColor = raylib::Color::Red());

  void Draw();
};

int fixNodeTextSize(std::string nodeText, float nodeTextWidth, float nodeRadius,
                    int fontSize);

double toRadians(double degree);
} // namespace Graphics
