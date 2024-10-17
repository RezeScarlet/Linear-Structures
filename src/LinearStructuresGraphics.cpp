#include "../include/LinearStructuresGraphics.hpp"
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <stack>
#include <string>

// Implementação do construtor e métodos
namespace Graphics {

StackGraphics::StackGraphics(int posY, int fontSize, int nodeCenterX,
                             int nodeCenterY, int nodeRadius, int nodeGap,
                             raylib::Color fontColor,
                             raylib::Color outlineColor) {
  this->nodeCenterY = posY;
  this->fontSize = fontSize;
  this->nodeCenterX = nodeCenterX;
  this->nodeCenterY = nodeCenterY;
  this->nodeRadius = nodeRadius;
  this->nodeGap = nodeGap;
  this->fontColor = fontColor;
  this->outlineColor = outlineColor;
}

void StackGraphics::Draw() {
  std::stack<int> stackCopy = stack;
  for (std::stack<int>::size_type i = 0; i < stack.size(); i++) {
    std::string nodeText = std::to_string(stackCopy.top());
    int nodeTextWidth = raylib::MeasureText(nodeText.c_str(), fontSize);

    // Desenha o texto e o círculo
    raylib::DrawText(nodeText.c_str(), (i * nodeGap) + nodeCenterX, nodeCenterY,
                     fontSize, fontColor);
    DrawCircleLines((i * nodeGap) + nodeCenterX, nodeCenterY, nodeRadius,
                    outlineColor);

    stackCopy.pop();
  }
}

} // namespace Graphics
