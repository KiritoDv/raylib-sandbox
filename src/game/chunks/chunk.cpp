#include "chunk.h"
#include "game.h"
#include "raymath.h"
#include <string>
#include <iostream>

using namespace std;

#define TILE_WIDTH_HALF  16.0f
#define TILE_HEIGHT_HALF 8.0f
#define DrawCenteredText(text, x, y, size) DrawText(text.c_str(), x - (MeasureText(text.c_str(), size) / 2), y, size, WHITE);

int maxInstances = 16 * 32 * 16;

Mesh cube;
Matrix *rotations;
Matrix *rotationsInc;
Matrix *translations;
Matrix *transforms;

void Chunk::bakeChunk(Camera3D camera){
    cube         = GenMeshCube(1.0f, 1.0f, 1.0f);
    rotations    = new Matrix[maxInstances];
    rotationsInc = new Matrix[maxInstances];
    translations = new Matrix[maxInstances];
    transforms   = new Matrix[maxInstances];
    int instanceId = 0;
    for(int x = 0; x < 16; x++) {
        for(int y = 0; y < 32; y++) {
            for(int z = 0; z < 16; z++) {
                if(!blocks[x][y][z]) continue;
                Block* block = blocks[x][y][z];
                Vector3 position = { (this->offset.x * 16.0f) + x, (float) y, (this->offset.y * 16.0f) + z };
                Model model = models[block->texture];
                rotationsInc[instanceId] = MatrixRotate(Vector3Normalize((Vector3){ 0.0f, .0f, 0.0f }), 0);
                translations[instanceId] = MatrixTranslate(x + this->offset.x * 16.0f, (float)y, (this->offset.y * 16.0f) + z);
                rotations [instanceId] = MatrixMultiply(MatrixIdentity(), rotationsInc[instanceId]);
                transforms[instanceId] = MatrixMultiply(rotations[instanceId], translations[instanceId]);
                transforms[instanceId] = MatrixMultiply(transforms[instanceId], MatrixScale(0.5, 0.3f, 0.5f));
                instanceId++;
            }
        }
    }
}

void Chunk::drawChunk(Camera3D camera) {
    float cameraPos[3] = { camera.position.x, camera.position.y, camera.position.z };
    float xPos = ((this->offset.x * 16) - (this->offset.y * 16)) * TILE_WIDTH_HALF;
    float yPos = ((this->offset.x * 16) + (this->offset.y * 16)) * TILE_HEIGHT_HALF;
    DrawMeshInstanced(models["Cube"].meshes[0], models["Cube"].materials[0], transforms, maxInstances);
}