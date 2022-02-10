#ifndef MarsGameH
#define MarsGameH

#include "raylib.h"
#include "block/block.h"
#include <map>
#include <string>

extern std::map<std::string, Texture2D> textures;
extern std::map<std::string, Model> models;
extern Ray ray;
extern Block* found;
extern std::vector<Block*> hit_blocks;

class MarsGame {
public:
    void init();
    void imgui();
    void update();
    void draw();
    void exit();
};

#endif