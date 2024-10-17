#include "Color.hpp"
#include "LinearStructuresGraphics.hpp"
#include "Utils.hpp"
#include <imgui.h>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <rlImGui.h>

float h = GetScreenHeight();
float w = GetScreenWidth();
ImVec2 wh(w, h);

int MainMenuScreen() {
  ImVec2 buttonSize(w / 5, h / 8);

  // Choose style
  ImGui::SetNextWindowBgAlpha(0);
  ImGui::SetNextWindowPos(ImVec2(0, 0));
  ImGui::SetNextWindowSize(wh);
  if (ImGui::Begin("Main Menu", __null,
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_NoTitleBar)) {
    ImGui::Dummy(buttonSize);
    ImGui::SetWindowFontScale(4);
    TextCenteredOnLine("Estruturas Lineares");
    ImGui::SetWindowFontScale(2);
    ImGui::Dummy(buttonSize);
    ImGui::PushStyleColor(ImGuiCol_Button,
                          (ImVec4)ImColor::HSV(343, 0.5269, 0.9232));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered,
                          (ImVec4)ImColor::HSV(343, 0.5269, 0.9932));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive,
                          (ImVec4)ImColor::HSV(343, 0.5269, 0.8232));
    if (ButtonCenteredOnLine("Pilha", buttonSize)) {
      return 1;
    }
    ImGui::PopStyleColor(3);
    if (ButtonCenteredOnLine("Fila", buttonSize)) {
      return 2;
    }
    if (ButtonCenteredOnLine("Deque", buttonSize)) {
      return 3;
    }
    if (ButtonCenteredOnLine("Lista", buttonSize)) {
      return 4;
    }
  }
  ImGui::End();
  return 0;
}

bool GraphicsScreen(int structureIdentifier) {

  Graphics::StackGraphics sg;
  ImVec2 buttonSize(w / 5, h / 8);

  ClearBackground(raylib::Color::White());

  // Choose style
  ImGui::SetNextWindowBgAlpha(0);
  ImGui::SetNextWindowPos(ImVec2(0, 0));
  ImGui::SetNextWindowSize(wh);
  if (ImGui::Begin("Main Menu", __null,
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_NoTitleBar)) {
    ImGui::Dummy(buttonSize);
    ImGui::SetWindowFontScale(4);
    TextCenteredOnLine("Estruturas Lineares");
    ImGui::SetWindowFontScale(2);
    ImGui::Dummy(buttonSize);
    ImGui::PushStyleColor(ImGuiCol_Button,
                          (ImVec4)ImColor::HSV(343, 0.5269, 0.9232));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered,
                          (ImVec4)ImColor::HSV(343, 0.5269, 0.9932));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive,
                          (ImVec4)ImColor::HSV(343, 0.5269, 0.8232));
    ImGui::PopStyleColor(3);
    if (ButtonCenteredOnLine("Add", buttonSize)) {
      sg.stack.push(1);
      sg.stack.push(20);
      sg.stack.push(100);
    }
    if (ButtonCenteredOnLine("Remove", buttonSize)) {
      // Link to file
    }
    if (ButtonCenteredOnLine("Sair", buttonSize)) {
      return 0;
      // Link to file
    }
  }
  ImGui::End();
  sg.Draw();
  return structureIdentifier;
}
