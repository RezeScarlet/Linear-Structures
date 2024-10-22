#include "Screens.hpp"
#include "Utils.hpp"
#include <cstdlib>
#include <imgui.h>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <rlImGui.h>

ScreenAtributes::ScreenAtributes(ImVec2 windowSize) {
  this->windowSize = windowSize;

  this->screenIdentifier = 0;

  this->structures[0] = "";
  this->structures[1] = "Pilha";
  this->structures[2] = "Fila";
  this->structures[3] = "Deque";
  this->structures[4] = "Lista";

  this->mainMenuButtonSize = ImVec2(windowSize.x / 5, windowSize.y / 8);
  this->graphicsScreenButtonSize = ImVec2(windowSize.x / 7, windowSize.y / 21);
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

void GraphicsScreen(ImVec2 windowSize, ScreenAtributes &atributes,
                    Graphics::LinearStructuresGraphics &linearStructure) {
  ImGui::SetNextWindowBgAlpha(0);
  ImGui::SetNextWindowPos(ImVec2(0, 0));
  ImGui::SetNextWindowSize(windowSize);
  if (ImGui::Begin("Main Menu", __null,
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_NoTitleBar)) {

    ImGui::SeparatorText(atributes.structures[atributes.screenIdentifier]);

    ImGui::SetWindowFontScale(1.3);

    StyleButton(atributes.screenIdentifier);
    ImGui::PushItemWidth(40);
    // ImGui::Text("Valor");
    // ImGui::SameLine();
    static char insertValue[32] = "1";
    ImGui::InputText("Valor", insertValue, 32);
    ImGui::PopItemWidth();

    ImGui::SameLine();

    static char insertPosition[32] = "0";
    if (atributes.screenIdentifier == 4) {
      ImGui::PushItemWidth(40);
      // ImGui::Text("Posição");
      // ImGui::SameLine();
      ImGui::InputText("Posição", insertPosition, 32);
      ImGui::PopItemWidth();
    }
    static int e = 0;
    if (atributes.screenIdentifier == 3) {
      ImGui::PushItemWidth(40);
      ImGui::RadioButton("Inicio", &e, 0);
      ImGui::SameLine();
      ImGui::RadioButton("Fim", &e, 1);
      ImGui::PopItemWidth();
    }
    ImGui::SameLine();
    if (ImGui::Button("Adicionar", atributes.graphicsScreenButtonSize)) {
      if (atributes.screenIdentifier == 1) {
        linearStructure.v.insert(linearStructure.v.end(),
                                 std::atoi(insertValue));
      } else if (atributes.screenIdentifier == 3) {
        if (e == 0) {
          linearStructure.v.insert(linearStructure.v.begin(),
                                   std::atoi(insertValue));
        } else {
          linearStructure.v.insert(linearStructure.v.end(),
                                   std::atoi(insertValue));
        }
      } else {
        linearStructure.v.insert(linearStructure.v.begin() +
                                     std::atoi(insertPosition),
                                 std::atoi(insertValue));
      }
      if (atributes.screenIdentifier == 4) {
        snprintf(insertPosition, sizeof(insertPosition), "%d",
                 atoi(insertPosition) + 1); // Converte de volta para string
      }
    }

    ImGui::SameLine();

    if (ImGui::Button("Remover", atributes.graphicsScreenButtonSize)) {
      if (!linearStructure.v.empty()) {
        if (atributes.screenIdentifier == 2) {
          linearStructure.v.erase(linearStructure.v.end()); // to com preguiça de simplesmente ajustar a fila pra apagar do inicio.
        } else if (atributes.screenIdentifier == 3) {
          if (e == 0) {
            linearStructure.v.erase(linearStructure.v.begin());
          } else {
            linearStructure.v.erase(linearStructure.v.end());
          }
        } else {
          linearStructure.v.erase(linearStructure.v.begin() +
                                  std::atoi(insertPosition));
        }
        if (atributes.screenIdentifier == 4) {
          snprintf(insertPosition, sizeof(insertPosition), "%d",
                   atoi(insertPosition) - 1); // Converte de volta para string
        }
      }
    }

    ImGui::SameLine();

    if (ImGui::Button("Sair", atributes.graphicsScreenButtonSize)) {
      linearStructure.v.clear();
      atributes.screenIdentifier = 0;
    }
  }
  switch (atributes.screenIdentifier) {
  case 1:
    linearStructure.DrawStack();
    break;
  case 2:
    linearStructure.DrawQueue();
    break;
  case 3:
    linearStructure.DrawDeque();
    break;
  case 4:
    linearStructure.DrawList();
    break;
  }
  PopStyleColor(1, 5);
  ImGui::End();
}
