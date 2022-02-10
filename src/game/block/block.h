#ifndef BlockH
#define BlockH

#include "raylib.h"
#include <string>

class Block {
public:
    Vector2 position;
    std::string texture;
    RayCollision collision = { 0 };
    float scale = 0.5f;
    Color color;
};

#endif