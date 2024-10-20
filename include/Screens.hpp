#pragma once
#include <imgui.h>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <rlImGui.h>

class ScreenAtributes {
public:
  ImVec2 windowSize;
  int screenIdentifier;
  const char *structures[5];
  ImVec2 mainMenuButtonSize;
  ImVec2 graphicsScreenButtonSize;

  ScreenAtributes(ImVec2 windowSize);
};

void MainMenuScreen(ImVec2 windowSize, ScreenAtributes& atributes);

void GraphicsScreen(ImVec2 windowSize, ScreenAtributes& atributes);
