#include "../include/LinearStructuresGraphics.hpp"
#include "Functions.hpp"
#include "Vector2.hpp"
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <stack>
#include <string>

namespace Graphics {

StackGraphics::StackGraphics(int fontSize, raylib::Vector2 nodeCenter,
                             int nodeRadius, int nodeGap,
                             raylib::Color fontColor,
                             raylib::Color outlineColor) {
  this->fontSize = fontSize;
  this->nodeCenter = nodeCenter;
  this->nodeRadius = nodeRadius;
  this->nodeGap = nodeGap;
  this->fontColor = fontColor;
  this->outlineColor = outlineColor;
}

void StackGraphics::Draw() {
  std::stack<int> stackCopy = stack;
  int i = stackCopy.size();

  while (!stackCopy.empty()) {
    std::string nodeText = std::to_string(stackCopy.top());
    float nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    float nodeTextHeight = fontSize;

    while (nodeTextWidth > nodeRadius) {
      fontSize /= 2;
      nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    }

    float textX = nodeCenter.x - (nodeTextWidth / 2);
    float textY = (i * nodeGap) + nodeCenter.y - (nodeTextHeight / 2);

    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines(nodeCenter.x, (i * nodeGap) + nodeCenter.y, nodeRadius,
                    outlineColor);
    i--;
    stackCopy.pop();
  }
}

/*
  void QueueGraphics::Draw() {
  std::queue<int> queueCopy = queue;
  for (int i = 0; i < queue.size(); i++) {
    std::string nodeText = std::to_string(queueCopy.top());
    int nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    int nodeTextHeight = fontSize;

    int textX = (i * nodeGap) + nodeCenterX - (nodeTextWidth / 2);
    int textY = nodeCenterY - (nodeTextHeight / 2);

    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines((i * nodeGap) + nodeCenterX, nodeCenterY, nodeRadius,
                    outlineColor);

    queueCopy.pop();
  }
}
*/

} // namespace Graphics
