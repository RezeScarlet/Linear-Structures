#include "../include/LinearStructuresGraphics.hpp"
#include "Color.hpp"
#include "Functions.hpp"
#include "Vector2.hpp"
#include <cmath>
#include <raylib-cpp.hpp>
#include <raylib.h>
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

void DrawSideNodeText(std::string sideNodeText,
                      raylib::Vector2 sideNodeTextPosition) {
  int sideNodeTextSize = 14;
  float sideNodeTextWidth =
      raylib::MeasureText(sideNodeText.c_str(), sideNodeTextSize);
  float sideNodeTextHeight = sideNodeTextSize;

  sideNodeTextPosition.x -= (sideNodeTextWidth / 2);
  sideNodeTextPosition.y -= (sideNodeTextHeight / 2);
  DrawText(sideNodeText, sideNodeTextPosition.x, sideNodeTextPosition.y,
           sideNodeTextSize, raylib::Color::White());
}

/* TODO FIX DrawArrows
void DrawArrows(raylib::Vector2 nodeCenter, raylib::Vector2 conectedNodeCenter,
                int nodeRadius, raylib::Color arrowColor) {
  if (lineText == "anterior") {
    raylib::DrawText("anterior", nodeCenter.x, nodeCenter.y - 35, 14,
                     raylib::Color::Blue());
    DrawLineV(nodeCenter, conectedNodeCenter, raylib::Color::Blue());
  } else if (lineText == "próximo") {
    raylib::DrawText("próximo", nodeCenter.x, nodeCenter.y + 35, 14,
                     raylib::Color::Blue());
    DrawLineV(nodeCenter, conectedNodeCenter, raylib::Color::Blue());
  }
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


}*/

LinearStructuresGraphics::LinearStructuresGraphics(int fontSize,
                                                   raylib::Vector2 nodeCenter,
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

void LinearStructuresGraphics::DrawStack() {
  nodeCenter.x = (float)GetScreenWidth() / 2;
  nodeCenter.y = (float)GetScreenHeight() - 40;

  for (int i = v.size() - 1; i >= 0; i--) {

    if (i == v.size() - 1) {
      // Draw TOP
      DrawSideNodeText("TOPO",
                       {nodeCenter.x - 75, nodeCenter.y + (i * nodeGap)});
    }
    raylib::Vector2 previousNodeCenter = {nodeCenter.x,
                                          (i - 1 * nodeGap) + nodeCenter.y};

    std::string nodeText = std::to_string(v.at(i));
    float nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    fontSize = CenterNodeText(nodeText, nodeTextWidth, nodeRadius, fontSize);
    float nodeTextHeight = fontSize;

    float textX = nodeCenter.x - (nodeTextWidth / 2);
    float textY = (i * nodeGap) + nodeCenter.y - (nodeTextHeight / 2);
    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines(nodeCenter.x, (i * nodeGap) + nodeCenter.y, nodeRadius,
                    outlineColor);

    float nextTextWidth = raylib::MeasureText("anterior", 14);
    float nextTextHeight = 14;

    raylib::Vector2 nextTextPosition = {nodeCenter.x - (nextTextWidth / 2),
                                        (i * nodeGap) + nodeCenter.y -
                                            (nextTextHeight / 2)};
    raylib::DrawText("anterior", nextTextPosition.x + 75,
                     nextTextPosition.y + 35, 14, raylib::Color::Blue());

    DrawLineV({nodeCenter.x, (i * nodeGap) + nodeCenter.y},
              {previousNodeCenter.x, previousNodeCenter.y - 20},
              raylib::Color::Blue());
  }
}
void LinearStructuresGraphics::DrawQueue() {
  nodeCenter.x = (float)GetScreenWidth() - 40;
  nodeCenter.y = (float)GetScreenHeight() / 2;

  for (int i = 0; i < v.size(); i++) {
    if (v.size() == 1) {
      DrawSideNodeText("INÍCIO",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y + 75});
      DrawSideNodeText("FIM",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y - 75});
    } else if (i == 0) {
      DrawSideNodeText("FIM",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y - 75});
    } else if (i == v.size() - 1) {
      DrawSideNodeText("INÍCIO",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y + 75});
    }

    raylib::Vector2 previousNodeCenter = {(i - 1 * nodeGap) + nodeCenter.x,
                                          nodeCenter.y};
    std::string nodeText = std::to_string(v.at(i));
    float nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    fontSize = CenterNodeText(nodeText, nodeTextWidth, nodeRadius, fontSize);
    float nodeTextHeight = fontSize;

    float textX = (i * nodeGap) + nodeCenter.x - (nodeTextWidth / 2);
    float textY = nodeCenter.y - (nodeTextHeight / 2);

    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines((i * nodeGap) + nodeCenter.x, nodeCenter.y, nodeRadius,
                    outlineColor);

    float nextTextWidth = raylib::MeasureText("próximo", 14);
    float nextTextHeight = 14;

    raylib::Vector2 nextTextPosition = {(i * nodeGap) + nodeCenter.x + 40 -
                                            (nextTextWidth / 2),
                                        nodeCenter.y - (nextTextHeight / 2)};
    raylib::DrawText("próximo", nextTextPosition.x, nextTextPosition.y - 35, 14,
                     raylib::Color::Blue());

    DrawLineV({(i * nodeGap) + nodeCenter.x + 30, nodeCenter.y - 20},
              {previousNodeCenter.x, previousNodeCenter.y - 20},
              raylib::Color::Blue());
  }
}

/* TODO FIX DEQUE AND LIST DRAW LOOP */
void LinearStructuresGraphics::DrawDeque() {
  nodeCenter.x = (float)GetScreenWidth() - 40;
  nodeCenter.y = (float)GetScreenHeight() / 2;

  for (int i = 0; i < v.size(); i++) {
    if (v.size() == 1) {
      DrawSideNodeText("INÍCIO",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y + 75});
      DrawSideNodeText("FIM",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y - 75});
    } else if (i == 0) {
      DrawSideNodeText("INÍCIO",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y + 75});
    } else if (i == v.size() - 1) {
      DrawSideNodeText("FIM",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y - 75});
    }

    raylib::Vector2 previousNodeCenter = {(i - 1 * nodeGap) + nodeCenter.x,
                                          nodeCenter.y};
    raylib::Vector2 nextNodeCenter = {(i + 1 * nodeGap) + nodeCenter.x,
                                      nodeCenter.y};

    std::string nodeText = std::to_string(v.at(i));
    float nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    fontSize = CenterNodeText(nodeText, nodeTextWidth, nodeRadius, fontSize);
    float nodeTextHeight = fontSize;

    float textX = (i * nodeGap) + nodeCenter.x - (nodeTextWidth / 2);
    float textY = nodeCenter.y - (nodeTextHeight / 2);

    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines((i * nodeGap) + nodeCenter.x, nodeCenter.y, nodeRadius,
                    outlineColor);

    float nextTextWidth = raylib::MeasureText("próximo", 14);
    float nextTextHeight = 14;

    raylib::Vector2 nextTextPosition = {(i * nodeGap) + nodeCenter.x + 40 -
                                            (nextTextWidth / 2),
                                        nodeCenter.y - (nextTextHeight / 2)};
    raylib::DrawText("próximo", nextTextPosition.x - 75, nextTextPosition.y - 35, 14,
                     raylib::Color::Blue());

    DrawLineV({(i * nodeGap) + nodeCenter.x + 30, nodeCenter.y - 20},
              {nextNodeCenter.x + (i * nodeGap), nextNodeCenter.y - 20}, raylib::Color::Blue());

    nextTextWidth = raylib::MeasureText("anterior", 14);

    nextTextPosition.x =
        (i * nodeGap) + nodeCenter.x + 40 - (nextTextWidth / 2);
    nextTextPosition.y = nodeCenter.y - (nextTextHeight / 2);

    raylib::DrawText("anterior", nextTextPosition.x, nextTextPosition.y + 35,
                     14, raylib::Color::Blue());

    DrawLineV({(i * nodeGap) + nodeCenter.x + 30, nodeCenter.y + 20},
              {previousNodeCenter.x, previousNodeCenter.y + 20},
              raylib::Color::Blue());
  }
}

void LinearStructuresGraphics::DrawList() {
  nodeCenter.x = (float)GetScreenWidth() - 40;
  nodeCenter.y = (float)GetScreenHeight() / 2;
  for (int i = 0; i < v.size(); i++) {
    if (v.size() == 1) {
      DrawSideNodeText("INÍCIO",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y + 75});
      DrawSideNodeText("FIM",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y - 75});
    } else if (i == 0) {
      DrawSideNodeText("INÍCIO",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y + 75});
    } else if (i == v.size() - 1) {
      DrawSideNodeText("FIM",
                       {nodeCenter.x + (i * nodeGap), nodeCenter.y - 75});
    }

    raylib::Vector2 previousNodeCenter = {(i - 1 * nodeGap) + nodeCenter.x,
                                          nodeCenter.y};
    raylib::Vector2 nextNodeCenter = {(i + 1 * nodeGap) + nodeCenter.x,
                                      nodeCenter.y};
    std::string nodeText = std::to_string(v.at(i));
    float nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);
    fontSize = CenterNodeText(nodeText, nodeTextWidth, nodeRadius, fontSize);
    float nodeTextHeight = fontSize;

    float textX = (i * nodeGap) + nodeCenter.x - (nodeTextWidth / 2);
    float textY = nodeCenter.y - (nodeTextHeight / 2);

    raylib::DrawText(nodeText, textX, textY, fontSize, fontColor);
    DrawCircleLines((i * nodeGap) + nodeCenter.x, nodeCenter.y, nodeRadius,
                    outlineColor);

    float nextTextWidth = raylib::MeasureText("próximo", 14);
    float nextTextHeight = 14;

    raylib::Vector2 nextTextPosition = {(i * nodeGap) + nodeCenter.x + 40 -
                                            (nextTextWidth / 2),
                                        nodeCenter.y - (nextTextHeight / 2)};
    raylib::DrawText("próximo", nextTextPosition.x - 75, nextTextPosition.y - 35, 14,
                     raylib::Color::Blue());

    DrawLineV({(i * nodeGap) + nodeCenter.x + 30, nodeCenter.y - 20},
              {nextNodeCenter.x + (i * nodeGap), nextNodeCenter.y - 20}, raylib::Color::Blue());

    nextTextWidth = raylib::MeasureText("anterior", 14);

    nextTextPosition.x =
        (i * nodeGap) + nodeCenter.x + 40 - (nextTextWidth / 2);
    nextTextPosition.y = nodeCenter.y - (nextTextHeight / 2);

    raylib::DrawText("anterior", nextTextPosition.x, nextTextPosition.y + 35,
                     14, raylib::Color::Blue());

    DrawLineV({(i * nodeGap) + nodeCenter.x + 30, nodeCenter.y + 20},
              {previousNodeCenter.x, previousNodeCenter.y + 20},
              raylib::Color::Blue());
  }
}
/* TODO FIX DEQUE AND LIST DRAW LOOP */
} // namespace Graphics
