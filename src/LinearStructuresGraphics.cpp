#include "../include/LinearStructuresGraphics.hpp"
#include "Functions.hpp"
#include "Vector2.hpp"
#include <cmath>
#include <list>
#include <queue>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <stack>
#include <string>

namespace Graphics {

int CenterNodeText(std::string nodeText, float nodeTextWidth, float nodeRadius,
                   int fontSize) {
  while (nodeTextWidth >
         nodeRadius) { // change fontSize in cases where the text is too big
    fontSize /= 2;
    nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
  }

  return fontSize;
}

double ToRadians(double degree) {
  double pi = 3.14159265359;
  return (degree * (pi / 180));
}

/* TODO FIX DrawArrows*/
void DrawArrows(raylib::Vector2 nodeCenter, raylib::Vector2 previousNodeCenter,
                int nodeRadius, raylib::Color arrowColor) {
  // arrows
  // initial point (45º)
  raylib::Vector2 arrowStart = {
      nodeCenter.x + (float)std::cos(ToRadians(45)) * nodeRadius,
      nodeCenter.y + (float)std::sin(ToRadians(45)) * nodeRadius};

  // final point (315º)
  raylib::Vector2 arrowEnd = {
      previousNodeCenter.x + (float)std::cos(ToRadians(315)) * nodeRadius,
      previousNodeCenter.y + (float)std::sin(ToRadians(315)) * nodeRadius};

  // arrow spline control points
  raylib::Vector2 arrowControl = {(arrowStart.x + arrowEnd.x) / 2 + 30, // + 20
                                  (arrowStart.y + arrowEnd.y) / 2};

  DrawSplineSegmentBezierQuadratic(arrowStart, arrowControl, arrowEnd, 1,
                                   arrowColor);
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

QueueGraphics::QueueGraphics(int fontSize, raylib::Vector2 nodeCenter,
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
DequeGraphics::DequeGraphics(int fontSize, raylib::Vector2 nodeCenter,
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

ListGraphics::ListGraphics(int fontSize, raylib::Vector2 nodeCenter,
                           int nodeRadius, int nodeGap, raylib::Color fontColor,
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
    raylib::Vector2 previousNodeCenter = {nodeCenter.x,
                                          (i * nodeGap) + nodeCenter.y};

    std::string nodeText = std::to_string(stackCopy.top());
    float nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    fontSize = CenterNodeText(nodeText, nodeTextWidth, nodeRadius, fontSize);
    float nodeTextHeight = fontSize;

    float textX = nodeCenter.x - (nodeTextWidth / 2);
    float textY = (i * nodeGap) + nodeCenter.y - (nodeTextHeight / 2);
    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines(nodeCenter.x, (i * nodeGap) + nodeCenter.y, nodeRadius,
                    outlineColor);
    DrawArrows(nodeCenter, previousNodeCenter, nodeRadius,
               raylib::Color::Blue());

    stackCopy.pop();
  }
}

void QueueGraphics::Draw() {
  std::queue<int> queueCopy = queue;
  for (int i = 0; i < queue.size(); i++) {
    raylib::Vector2 previousNodeCenter = {nodeCenter.x,
                                          (i * nodeGap) + nodeCenter.y};
    std::string nodeText = std::to_string(queueCopy.front());
    float nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    fontSize = CenterNodeText(nodeText, nodeTextWidth, nodeRadius, fontSize);
    float nodeTextHeight = fontSize;

    float textX = (i * nodeGap) + nodeCenter.x - (nodeTextWidth / 2);
    float textY = nodeCenter.y - (nodeTextHeight / 2);

    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines((i * nodeGap) + nodeCenter.x, nodeCenter.y, nodeRadius,
                    outlineColor);
    DrawArrows(nodeCenter, previousNodeCenter, nodeRadius,
               raylib::Color::Blue());
    queueCopy.pop();
  }
}

/* TODO FIX DEQUE AND LIST DRAW LOOP */
void DequeGraphics::Draw() {
  std::deque<int> dequeCopy = deque;
  for (int i = 0; i < deque.size(); i++) {
    raylib::Vector2 previousNodeCenter = {nodeCenter.x,
                                          (i * nodeGap) + nodeCenter.y};
    std::string nodeText = std::to_string(dequeCopy.front());
    float nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    fontSize = CenterNodeText(nodeText, nodeTextWidth, nodeRadius, fontSize);
    float nodeTextHeight = fontSize;

    float textX = (i * nodeGap) + nodeCenter.x - (nodeTextWidth / 2);
    float textY = nodeCenter.y - (nodeTextHeight / 2);

    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines((i * nodeGap) + nodeCenter.x, nodeCenter.y, nodeRadius,
                    outlineColor);
    DrawArrows(nodeCenter, previousNodeCenter, nodeRadius,
               raylib::Color::Blue());

    dequeCopy.pop_front();
  }
}

void ListGraphics::Draw() {
  std::list<int> listCopy = list;
  for (int i = 0; i < list.size(); i++) {
    raylib::Vector2 previousNodeCenter = {nodeCenter.x,
                                          (i * nodeGap) + nodeCenter.y};
    std::string nodeText = std::to_string(listCopy.front());
    float nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    fontSize = CenterNodeText(nodeText, nodeTextWidth, nodeRadius, fontSize);
    float nodeTextHeight = fontSize;

    float textX = (i * nodeGap) + nodeCenter.x - (nodeTextWidth / 2);
    float textY = nodeCenter.y - (nodeTextHeight / 2);

    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines((i * nodeGap) + nodeCenter.x, nodeCenter.y, nodeRadius,
                    outlineColor);
    DrawArrows(nodeCenter, previousNodeCenter, nodeRadius,
               raylib::Color::Blue());

    listCopy.pop_front();
  }
}
/* TODO FIX DEQUE AND LIST DRAW LOOP */
} // namespace Graphics
