#pragma once
#include <imgui.h>

void StyleButton(int mode);
void PopStyleColor(int style, int color);
bool ButtonCenteredOnLine(const char *label, ImVec2 buttonSize,
                          float alignment = 0.5f);

void TextCenteredOnLine(const char *label, float alignment = 0.5f);
