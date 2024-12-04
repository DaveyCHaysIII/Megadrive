#include <raylib.h>
class Screen {
public:
    const char *title;
    Vector2 screenCenter;

    Screen(const char *title, float center_x, float center_y) :
    title(title),
    screenCenter{center_x, center_y} {}
};

class Title : public Screen {
public:
    const char *player1, *player2, *exit;

    using Screen::Screen; // use Screen constructor
};

class Gameplay : public Screen {
public:

};

class Ending : public Screen {
public:

};
