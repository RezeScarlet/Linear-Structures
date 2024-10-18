#include "Color.hpp"
#include <Screens.hpp>
#include <imgui.h>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <rlImGui.h>

int main() {

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  raylib::Window window(854, 480);
  SetTargetFPS(60);

  float h = GetScreenHeight();
  float w = GetScreenWidth();
  ImVec2 windowSize(w, h);

  /*
    0: Main Menu
    1: Stack
    2: Queue
    3: Deque
    4: List
  */
  int currentScreen = 0;

  rlImGuiSetup(true);

  while (WindowShouldClose() == false) {

    BeginDrawing();
    rlImGuiBegin();

    ClearBackground(raylib::Color::FromHSV(249, 0.3607, 0.1464));
    if (currentScreen == 0) {
      currentScreen = MainMenuScreen(windowSize);
    } else {
      currentScreen = GraphicsScreen(windowSize,currentScreen);
    }

    rlImGuiEnd();
    EndDrawing();
  }

  rlImGuiShutdown();

  CloseWindow();
  return 0;
}
