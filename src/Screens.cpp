#include "LinearStructuresGraphics.hpp"
#include "Utils.hpp"
#include <imgui.h>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <rlImGui.h>

int MainMenuScreen(ImVec2 windowSize) {
  int structureIdentifier = 0;
  ImVec2 buttonSize(windowSize.x / 5, windowSize.y / 8);

  ImGui::SetNextWindowBgAlpha(0);
  ImGui::SetNextWindowPos(ImVec2(0, 0));
  ImGui::SetNextWindowSize(windowSize);
  if (ImGui::Begin("Main Menu", __null,
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_NoTitleBar)) {

    ImGui::Dummy(buttonSize);

    ImGui::SetWindowFontScale(4);
    TextCenteredOnLine("Estruturas Lineares");
    ImGui::SetWindowFontScale(2);

    ImGui::Dummy(buttonSize);

    const char *structures[] = {"Pilha", "Fila", "Deque", "Lista"};
    for (int i = 1; i <= sizeof(structures) / sizeof(structures[0]); i++) {
      StyleButton(i);
      if (ButtonCenteredOnLine(structures[i - 1], buttonSize)) {
        structureIdentifier = 1;
      }
      PopStyleColor(1, 5);
    }
  }

  ImGui::End();
  return structureIdentifier;
}

bool GraphicsScreen(ImVec2 windowSize, int structureIdentifier) {
  Graphics::StackGraphics sg;
  ImVec2 buttonSize(windowSize.x / 12, windowSize.y / 15);

  ImGui::SetNextWindowBgAlpha(0);
  ImGui::SetNextWindowPos(ImVec2(0, 0));
  ImGui::SetNextWindowSize(windowSize);
  if (ImGui::Begin("Main Menu", __null,
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_NoTitleBar)) {

    const char *structures[] = {"Pilha", "Fila", "Deque", "Lista"};
    ImGui::SeparatorText(structures[structureIdentifier - 1]);

    ImGui::SetWindowFontScale(1.3);
    StyleButton(structureIdentifier - 1);
    if (ImGui::Button("Add", buttonSize)) {
      sg.stack.push(1);
      sg.stack.push(2);

    }
    ImGui::SameLine();
    if (ImGui::Button("Remove", buttonSize)) {
      sg.stack.pop();

    }
    ImGui::SameLine();
    if (ImGui::Button("Sair", buttonSize)) {
      structureIdentifier = 0;

    }
  }
  PopStyleColor(1, 5);
  ImGui::End();
  sg.Draw();
  return structureIdentifier;
}
