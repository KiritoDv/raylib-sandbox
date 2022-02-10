#include "game.h"
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <string>
#include <map>
#include "imgui.h"
#include "impl/imgui/imgui_impl.h"
#include <math.h>
#include <vector>
#include "chunks/chunk.h"
#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"

using namespace std;

#define RAND (unsigned char) 255

vector<Chunk*> chunks;
map<string, Texture2D> textures;
map<string, Model> models;

Camera3D camera = { 0 };
Vector3 angle = Vector3({0.8f, -0.550f, 0.0f});
float targetDistance = 50.0f;
Ray ray = { 0 };
vector<Block*> hit_blocks;
Shader shader;

#define MAP_X_LIMIT 1
#define MAP_Y_LIMIT 1

void fillChunks(){
    for(int i = 0; i < MAP_X_LIMIT; i++){
        for(int j = 0; j < MAP_Y_LIMIT; j++){
            Chunk* chunk = new Chunk(Vector2({(float)i, (float)j}));
            for(int x = 0; x < 16; x++){
                for(int y = 0; y < 16; y++){
                    Block* b = new Block();
                    b->color = {RAND, RAND, RAND, 255};
                    b->position = Vector2({(float)x, (float)y});
                    b->texture = "Cube";
                    chunk->blocks[x][0][y] = b;
                }
            }
            chunk->bakeChunk(camera);
            chunks.push_back(chunk);
        }
    }
}

// 4.f

void loadTexture(string name, string path){
    Image tmp = LoadImage(path.c_str());
    textures[name] = LoadTextureFromImage(tmp);
    UnloadImage(tmp);
}

Vector3 lightPos = (Vector3){ -10.0f, 10.0f, 10.0f };

void MarsGame::init(){
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 2.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 35.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_ORTHOGRAPHIC;
    SetCameraMode(camera, CAMERA_FREE);
    loadTexture("Grass", "assets/textures/Grass.png");
    loadTexture("Cover", "assets/sprites/GrassTest.png");

    models["Cube"] = LoadModel("assets/models/Cube.obj");
    models["Cube"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = textures["Grass"];
    models["Rupee"] = LoadModel("assets/models/SmoothRupee.glb");

    shader = LoadShader("assets/shaders/base_lighting_instanced.vs", "assets/shaders/lighting.fs");
    shader.locs[SHADER_LOC_MATRIX_MVP] = GetShaderLocation(shader, "mvp");
    shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");
    shader.locs[SHADER_LOC_MATRIX_MODEL] = GetShaderLocationAttrib(shader, "instanceTransform");

    int ambientLoc = GetShaderLocation(shader, "ambient");
    SetShaderValue(shader, ambientLoc, (float[4]){ 0.2f, 0.2f, 0.2f, 1.0f }, SHADER_UNIFORM_VEC4);
    CreateLight(LIGHT_DIRECTIONAL, lightPos, Vector3Zero(), WHITE, shader);
    models["Cube"].materials[0].shader = shader;
    // material = LoadMaterialDefault();
    // material.shader = shader;
    // material.maps[MATERIAL_MAP_DIFFUSE].color = RED;
    fillChunks();
}

void MarsGame::imgui(){
    ImGui::Begin("Map Specifications", NULL, ImGuiWindowFlags_None);
        ImGui::Text("Cubes: %d", (MAP_X_LIMIT * MAP_Y_LIMIT) * (16 * 16));
        ImGuiExt::SliderFloatWithSteps("Angle X", &angle.x, -1.0f, 1.0f, 0.05f, NULL);
        ImGuiExt::SliderFloatWithSteps("Angle Y", &angle.y, -1.0f, 1.0f, 0.05f, NULL);
        ImGuiExt::SliderFloatWithSteps("Angle Z", &angle.z, -1.0f, 1.0f, 0.05f, NULL);
        ImGui::SliderFloat("Distance", &targetDistance, 0.0f, 1000.0f);
        ImGuiExt::SliderFloatWithSteps("FOV", &camera.fovy, .0f, 100.0f, 1.0f, NULL);
        ImGuiExt::SliderFloatWithSteps("UP Y", &camera.up.y, .0f, 100.0f, 1.0f, NULL);
    ImGui::End();
}

void MarsGame::update(){
    float deltaTime = GetFrameTime();
    float speed = 10.0f * deltaTime;
    ray = GetMouseRay(GetMousePosition(), camera);
    if(IsKeyDown(KEY_D)){
        camera.target.x -= speed;
    }
    if(IsKeyDown(KEY_A)){
        camera.target.x += speed;
    }
    if(IsKeyDown(KEY_W)){
        camera.target.y += speed;
    }
    if(IsKeyDown(KEY_S)){
        camera.target.y -= speed;
    }

    float wheel = GetMouseWheelMove();
    if(wheel > 0){
        targetDistance -= 1.f;
    }
    if(wheel < 0){
        targetDistance += 1.f;
    }

    // UpdateCamera(&camera);
    camera.position.x = -sinf(angle.x) * targetDistance * cosf(angle.y) + camera.target.x;
    camera.position.y = -sinf(angle.y) * targetDistance + camera.target.y;
    camera.position.z = -cosf(angle.x) * targetDistance * cosf(angle.y) + camera.target.z;
}

void MarsGame::draw(){
    // Vector2 mousePos = Vector2Sudabtract(GetMousePosition(), camera.offset);
    BeginDrawing();
        ClearBackground((Color){100, 149, 237, 255});
        BeginMode3D(camera);
            for(Chunk* chunk : chunks){
                chunk->drawChunk(camera);
            }

            DrawCube(lightPos, 1.0f, 1.0f, 1.0f, RED);

            // int xPos = (mousePos.x / 16 + mousePos.y / 8) / 2;
            // int yPos = (mousePos.y / 8  - mousePos.x / 16) / 2;
            // Vector2 blockPos = Vector2Multiply(Vector2({(xPos - yPos) * 16.0f - 16.0f, (xPos + yPos) * 8.0f - 16.0f}), Vector2({camera.zoom, camera.zoom}));
            // DrawTexture(textures["Cover"], blockPos.x, blockPos.y, RED);

            // if(IsMouseButtonPressed(0)){
            //     cout << "X: " << xPos << " Y: " << yPos << endl;
            // }
        EndMode3D();
    EndDrawing();
    // cout << "Found " << hit_blocks.size() << " blocks" << endl;
    hit_blocks.clear();
}

void MarsGame::exit(){

}