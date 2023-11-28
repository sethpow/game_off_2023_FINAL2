#include "raylib.h"

class Button {
public:
    Rectangle bounds;
    const char* text;

    Button(float x, float y, float width, float height, const char* buttonText);

    bool IsClicked() const;

    void Draw() const;
};
