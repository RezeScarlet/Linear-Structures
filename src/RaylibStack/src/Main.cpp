#include "../include/raylib-cpp.hpp"
#include <raylib.h>
#include <stack>

int main() {
  std::stack<int> stack;
  int num = 0;
  SetConfigFlags(FLAG_MSAA_4X_HINT);
  raylib::Window window(854, 480);
  SetTargetFPS(60);

  while (WindowShouldClose() == false) {
    BeginDrawing();
    if (IsMouseButtonPressed(0)) {
      stack.push(num++);
    }
    if (IsMouseButtonPressed(1)) {
      stack.pop();
    }
    ClearBackground(raylib::Color::White());
    std::stack<int> stackCopy = stack;
    for (int i = 0; i < stack.size(); i++) {
      raylib::DrawText(TextFormat("%d", stackCopy.top()), (i * 100)+30, 40, 20, raylib::Color::Red());
      DrawCircleLinesV({static_cast<float>((i * 100) + 5 + 30), 40 + 10 }, 30, raylib::Color::Red());
      DrawLineV({static_cast<float>((i * 100) + 5 + 30 + 30), 40 + 10 }, {static_cast<float>(i * 100 + 5 + 100), 40 + 10 }, raylib::Color::Red());
      stackCopy.pop();
    }
    EndDrawing();
  }
  return 0;
}
