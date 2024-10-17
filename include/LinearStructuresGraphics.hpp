#ifndef LINEAR_STRUCTURES_GRAPHICS_HPP_INCLUDED
#define LINEAR_STRUCTURES_GRAPHICS_HPP_INCLUDED

#include "Vector2.hpp"
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <stack>

namespace Graphics {

class LinearStructuresGraphics {
public:
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
                                              (float)GetScreenHeight() + 40},
                int nodeRadius = 30, int nodeGap = -75,
                raylib::Color fontColor = raylib::Color::Red(),
                raylib::Color outlineColor = raylib::Color::Red());

  void Draw();
};

} // namespace Graphics

#endif
