#include "../include/LinearStructuresGraphics.hpp"
#include "Color.hpp"
#include <imgui.h>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include <rlImGui.h>

// TODO CREATE HEADER FILES FOR THE TWO METHODS BELOW
// Got this function from an issue in the Dear ImGui Github
bool ButtonCenteredOnLine(const char *label, ImVec2 buttonSize,
                          float alignment = 0.5f) {
  ImGuiStyle &style = ImGui::GetStyle();

  float size = ImGui::CalcTextSize(label).x + style.FramePadding.x * 2.0f;
  float avail = ImGui::GetContentRegionAvail().x;

  float off = (avail - buttonSize.x) * alignment;
  if (off > 0.0f)
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);

  return ImGui::Button(label, buttonSize);
}

void TextCenteredOnLine(const char *label, float alignment = 0.5f) {
  ImGuiStyle &style = ImGui::GetStyle();

  float size = ImGui::CalcTextSize(label).x + style.FramePadding.x * 2.0f;
  float avail = ImGui::GetContentRegionAvail().x;

  float off = (avail - size) * alignment;
  if (off > 0.0f)
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);

  ImGui::Text("%s", label);
}

void ColorButton(float h, float s, float v);
int main() {

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  raylib::Window window(854, 480);
  SetTargetFPS(60);

  float h = window.GetHeight();
  float w = window.GetWidth();
  ImVec2 wh(w, h);

  rlImGuiSetup(true);

  ImVec2 buttonSize(w / 5, h / 8);

  while (WindowShouldClose() == false) {

    BeginDrawing();
    rlImGuiBegin();

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
      if (ButtonCenteredOnLine("Pilha", buttonSize)) {
        ClearBackground(raylib::Color::White());

        Graphics::StackGraphics sg;

        sg.stack.push(1);
        sg.stack.push(20);
        sg.stack.push(100);

        sg.Draw();
      }
      ImGui::PopStyleColor(3);
      if (ButtonCenteredOnLine("Fila", buttonSize)) {
        // Link to file
      }
      if (ButtonCenteredOnLine("Deque", buttonSize)) {
        // Link to file
      }
      if (ButtonCenteredOnLine("Lista", buttonSize)) {
        // Link to file
      }
    }
    ImGui::End();

    rlImGuiEnd();
    EndDrawing();
  }

  rlImGuiShutdown();

  CloseWindow();
  return 0;
}
