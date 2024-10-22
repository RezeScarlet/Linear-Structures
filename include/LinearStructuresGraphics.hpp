#pragma once

#include "Vector2.hpp"
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <vector>

namespace Graphics {

class LinearStructuresGraphics {
protected:
  raylib::Vector2 nodeCenter;
  int nodeRadius;
  int nodeGap; // distance between the nodes
  int fontSize;
  raylib::Color fontColor;
  raylib::Color outlineColor;

public:
  std::vector<int> v;
  LinearStructuresGraphics(
      int fontSize = 20,
      raylib::Vector2 nodeCenter = {(float)GetScreenWidth() - 40,
                                    (float)GetScreenHeight() / 2},
      int nodeRadius = 30, int nodeGap = -75,
      raylib::Color fontColor = raylib::Color::Red(),
      raylib::Color outlineColor = raylib::Color::Red());
  void DrawStack();
  void DrawQueue();
  void DrawDeque();
  void DrawList();
  ~LinearStructuresGraphics() = default;
};

double ToRadians(double degree);

void DrawArrows(raylib::Vector2 nodeCenter, raylib::Vector2 previousNodeCenter,
                int nodeRadius, raylib::Color arrowColor);
} // namespace Graphics
