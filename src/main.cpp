#include "Color.hpp"
#include <Screens.hpp>
#include <imgui.h>
#include <iostream>
#include <ostream>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <rlImGui.h>

int main() {

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  raylib::Window window(854, 480);
  SetTargetFPS(60);

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
    ClearBackground(raylib::Color::FromHSV(249, 0.22, 0.12));
    if (currentScreen == 0) {
      std::cout << "0";
      currentScreen = MainMenuScreen();
    } else {
      std::cout << currentScreen << "\n";
      GraphicsScreen(currentScreen);
    }

    rlImGuiBegin();

    rlImGuiEnd();
    EndDrawing();
  }

  rlImGuiShutdown();

  CloseWindow();
  return 0;
}
