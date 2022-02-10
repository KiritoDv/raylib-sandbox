#include <iostream>
#include "raylib.h"
#include "emscripten_utils.h"
#include "impl/imgui_impl.h"
#include "game/game.h"

using namespace std;

MarsGame* game = nullptr;

void UpdateDrawFrame(void) {
    game->update();
    game->draw();
    MercuryImGui::draw();
    game->imgui();
    MercuryImGui::render();
}

int main() {
    Vector2 windowSize = EMS::getWindowSize();
    SetTargetFPS(144);
    InitWindow(windowSize.x, windowSize.y, NULL);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    ToggleFullscreen();
    game = new MarsGame();
    game->init();
    MercuryImGui::bind();
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
    CloseWindow();
    return 0;
}