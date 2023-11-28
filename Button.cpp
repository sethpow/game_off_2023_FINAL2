#include "Button.h"

Button::Button(float x, float y, float width, float height, const char* buttonText)
    : bounds({ x, y, width, height }), text(buttonText) {}

bool Button::IsClicked() const {
    return CheckCollisionPointRec(GetMousePosition(), bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void Button::Draw() const {
    DrawRectangleRec(bounds, LIGHTGRAY);
    DrawText(text, static_cast<int>(bounds.x + bounds.width / 2 - MeasureText(text, 20) / 2),
             static_cast<int>(bounds.y + bounds.height / 2 - 10), 20, DARKGRAY);
}
