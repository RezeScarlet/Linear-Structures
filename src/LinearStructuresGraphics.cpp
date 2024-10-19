#include "../include/LinearStructuresGraphics.hpp"
#include "Functions.hpp"
#include "Vector2.hpp"
#include <queue>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <stack>
#include <string>

namespace Graphics {

int fixNodeTextSize(std::string nodeText, float nodeTextWidth, float nodeRadius,
                    int fontSize) {
  while (nodeTextWidth >
         nodeRadius) { // change fontSize in cases where the text is too big
    fontSize /= 2;
    nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
  }

  return fontSize;
}

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

  for (int i = stackCopy.size(); i > 0; i--) {
    std::string nodeText = std::to_string(stackCopy.top());
    float nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    fontSize = fixNodeTextSize(nodeText, nodeTextWidth, nodeRadius, fontSize);
    float nodeTextHeight = fontSize;

    float textX = nodeCenter.x - (nodeTextWidth / 2);
    float textY = (i * nodeGap) + nodeCenter.y - (nodeTextHeight / 2);

    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines(nodeCenter.x, (i * nodeGap) + nodeCenter.y, nodeRadius,
                    outlineColor);

    stackCopy.pop();
  }
}

void QueueGraphics::Draw() {
  std::queue<int> queueCopy = queue;
  for (int i = 0; i < queue.size(); i++) {
    std::string nodeText = std::to_string(queueCopy.front());
    float nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    fontSize = fixNodeTextSize(nodeText, nodeTextWidth, nodeRadius, fontSize);
    float nodeTextHeight = fontSize;

    float textX = (i * nodeGap) + nodeCenter.x - (nodeTextWidth / 2);
    float textY = nodeCenter.y - (nodeTextHeight / 2);

    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines((i * nodeGap) + nodeCenter.x, nodeCenter.y, nodeRadius,
                    outlineColor);

    queueCopy.pop();
  }
}

} // namespace Graphics
