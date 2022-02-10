#ifndef ChunkH
#define ChunkH

#include <vector>
#include "raylib.h"
#include "block/block.h"

class Chunk {
protected:
    Vector2 offset;
    RenderTexture2D baked;
    bool needsBaking = true;
public:
    Block* blocks[16][32][16];
    Chunk(Vector2 offset){
        this->offset = offset;
        for(int x = 0; x < 16; x++) {
            for(int y = 0; y < 32; y++) {
                for(int z = 0; z < 16; z++) {
                    blocks[x][y][z] = NULL;
                }
            }
        }
    }
    void drawChunk(Camera3D camera);
    void bakeChunk(Camera3D camera);
};

#endif