#include <imgui.h>

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
