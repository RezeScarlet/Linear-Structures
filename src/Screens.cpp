#include "Screens.hpp"
#include "LinearStructuresGraphics.hpp"
#include "Utils.hpp"
#include <imgui.h>
#include <iostream>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <rlImGui.h>
#include <string>

ScreenAtributes::ScreenAtributes(ImVec2 windowSize) {
  this->windowSize = windowSize;

  this->screenIdentifier = 0;

  this->structures[0] = "";
  this->structures[1] = "Pilha";
  this->structures[2] = "Fila";
  this->structures[3] = "Deque";
  this->structures[4] = "Lista";

  this->mainMenuButtonSize = ImVec2(windowSize.x / 5, windowSize.y / 8);
  this->graphicsScreenButtonSize = ImVec2(windowSize.x / 12, windowSize.y / 15);
}

void MainMenuScreen(ImVec2 windowSize, ScreenAtributes &atributes) {

  ImGui::SetNextWindowBgAlpha(0);
  ImGui::SetNextWindowPos(ImVec2(0, 0));
  ImGui::SetNextWindowSize(windowSize);
  if (ImGui::Begin("Main Menu", __null,
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_NoTitleBar)) {

    ImGui::Dummy(atributes.mainMenuButtonSize);

    ImGui::SetWindowFontScale(4);
    TextCenteredOnLine("ESTRUTURAS LINEARES");
    ImGui::SetWindowFontScale(2);

    ImGui::Dummy(atributes.mainMenuButtonSize);

    for (int i = 1; i < 5; i++) {
      StyleButton(i);
      if (ButtonCenteredOnLine(atributes.structures[i],
                               atributes.mainMenuButtonSize)) {
        atributes.screenIdentifier = i;
      }
      PopStyleColor(1, 5);
    }
  }

  ImGui::End();
}

<<<<<<< Updated upstream
void GraphicsScreen(ImVec2 windowSize, ScreenAtributes &atributes,
                    Graphics::StackGraphics &stackGraphics) {
=======
void GraphicsScreen(ImVec2 windowSize, ScreenAtributes &atributes) {
  Graphics::StackGraphics sg;
>>>>>>> Stashed changes
  ImGui::SetNextWindowBgAlpha(0);
  ImGui::SetNextWindowPos(ImVec2(0, 0));
  ImGui::SetNextWindowSize(windowSize);
  if (ImGui::Begin("Main Menu", __null,
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_NoTitleBar)) {

    ImGui::SeparatorText(atributes.structures[atributes.screenIdentifier]);

    ImGui::SetWindowFontScale(1.3);

    ImGui::PushItemWidth(40);
    static char insertValue[32] = "";
    ImGui::InputText(" ", insertValue, 32);
    ImGui::PopItemWidth();
    ImGui::SameLine();
    StyleButton(atributes.screenIdentifier);
    if (ImGui::Button("Empilhar", atributes.graphicsScreenButtonSize)) {
      switch (atributes.screenIdentifier) {
      case 1:

        stackGraphics.stack.push(std::atoi(insertValue));

        break;
      case 2:
        // queueGraphics.queue.push(1);
        break;
      case 3:
        break;
      case 4:
        break;
      }
    }
    ImGui::SameLine();
    if (ImGui::Button("Desempilhar", atributes.graphicsScreenButtonSize)) {
      switch (atributes.screenIdentifier) {
      case 1:
        stackGraphics.stack.pop();
        break;
      case 2:
        // queueGraphics.queue.pop();
        break;
      case 3:
        break;
      case 4:
        break;
      }
    }
    ImGui::SameLine();
    if (ImGui::Button("Sair", atributes.graphicsScreenButtonSize)) {
      atributes.screenIdentifier = 0;
    }
  }
  switch (atributes.screenIdentifier) {
  case 1:
    stackGraphics.Draw();
    break;
  case 2:
    // queueGraphics.Draw();
    break;
  case 3:
    break;
  case 4:
    break;
  }
  PopStyleColor(1, 5);
  ImGui::End();
}
