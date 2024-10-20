#include <imgui.h>

// Got this function from an issue in the Dear ImGui Github
void StyleButton(int mode) {
  ImVec4 colors[] = {
      ImColor(235, 111, 146), // Red
      ImColor(235, 188, 186), // Pink
      ImColor(196, 167, 231), // Purple
      ImColor(156, 207, 216), // Turquoise
  };


  ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1);

  ImGui::PushStyleColor(ImGuiCol_Text, colors[mode- 1]);
  ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(64, 61, 82));
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(82, 79, 103));
  ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(33, 32, 46));
  ImGui::PushStyleColor(ImGuiCol_Border, colors[mode - 1]);
}

void PopStyleColor(int style, int color) {
  ImGui::PopStyleVar(style);
  ImGui::PopStyleColor(color);
}

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
