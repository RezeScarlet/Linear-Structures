#pragma once

#include <raylib-cpp.hpp>
#include <raylib.h>
#include <stack>

namespace Graphics {

class LinearStructuresGraphics {
public:
  int nodeCenterX;
  int nodeCenterY;
  int nodeRadius;
  int nodeGap; // distance between the nodes
  int fontSize;
  raylib::Color fontColor;
  raylib::Color outlineColor;
};

class StackGraphics : public LinearStructuresGraphics {
public:
  std::stack<int> stack;

  StackGraphics(int posY = 40, int fontSize = 20, int nodeCenterX = 30,
                int nodeCenterY = 40, int nodeRadius = 30, int nodeGap = 100,
                raylib::Color fontColor = raylib::Color::Red(),
                raylib::Color outlineColor = raylib::Color::Red());

  void Draw();
};

} // namespace Graphics
