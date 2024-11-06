#include "Color.hpp"
#include "LinearStructuresGraphics.hpp"
#include <Screens.hpp>
#include <imgui.h>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <rlImGui.h>

/*Desenvolvido por Aloísio Marques Lingo Filho e Guilherme de Souza Dionisio
 * Rosseti*/
int main() {

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  raylib::Window window(1280, 720); // 854, 480
  SetTargetFPS(60);

  /*
    0: Main Menu
    1: Stack
    2: Queue
    3: Deque
    4: List
  */

  ScreenAtributes atributes(ImVec2(GetScreenWidth(), GetScreenHeight()));
  Graphics::LinearStructuresGraphics LinearStructure;

  rlImGuiSetup(true);

  while (WindowShouldClose() == false) {

    BeginDrawing();
    rlImGuiBegin();

    ClearBackground(raylib::Color::FromHSV(249, 0.3607, 0.1464));
    if (atributes.screenIdentifier == 0) {
      MainMenuScreen(atributes.windowSize, atributes);
    } else {
      GraphicsScreen(atributes.windowSize, atributes, LinearStructure);
    }

    rlImGuiEnd();
    EndDrawing();
  }

  rlImGuiShutdown();

  CloseWindow();
  return 0;
}
