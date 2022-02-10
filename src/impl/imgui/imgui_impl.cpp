#include "imgui_impl.h"

#include "raylib.h"
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"
#include "emscripten_utils.h"

namespace MercuryImGui {
    ImGuiIO* io = nullptr;

    void bind(){
        ImGuiContext* ctx = ImGui::CreateContext();
        Vector2 windowSize = EMS::getWindowSize();
        ImGui::SetCurrentContext(ctx);
        io = &ImGui::GetIO();
        io->WantSetMousePos = false;
        io->ConfigWindowsMoveFromTitleBarOnly = true;
        io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io->DisplaySize = ImVec2(windowSize.x, windowSize.y);
        ImGui_ImplOpenGL3_Init();
    }

    void update(){
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[0] = IsMouseButtonDown(MOUSE_LEFT_BUTTON);
        io.MouseDown[1] = IsMouseButtonDown(MOUSE_RIGHT_BUTTON);
        io.MouseDown[2] = IsMouseButtonDown(MOUSE_MIDDLE_BUTTON);
        io.MouseWheel += (float)GetMouseWheelMove();

        io.KeysDown[KEY_APOSTROPHE    ] = IsKeyDown(KEY_APOSTROPHE);
        io.KeysDown[KEY_COMMA         ] = IsKeyDown(KEY_COMMA);
        io.KeysDown[KEY_MINUS         ] = IsKeyDown(KEY_MINUS);
        io.KeysDown[KEY_PERIOD        ] = IsKeyDown(KEY_PERIOD);
        io.KeysDown[KEY_SLASH         ] = IsKeyDown(KEY_SLASH);
        io.KeysDown[KEY_ZERO          ] = IsKeyDown(KEY_ZERO);
        io.KeysDown[KEY_ONE           ] = IsKeyDown(KEY_ONE);
        io.KeysDown[KEY_TWO           ] = IsKeyDown(KEY_TWO);
        io.KeysDown[KEY_THREE         ] = IsKeyDown(KEY_THREE);
        io.KeysDown[KEY_FOUR          ] = IsKeyDown(KEY_FOUR);
        io.KeysDown[KEY_FIVE          ] = IsKeyDown(KEY_FIVE);
        io.KeysDown[KEY_SIX           ] = IsKeyDown(KEY_SIX);
        io.KeysDown[KEY_SEVEN         ] = IsKeyDown(KEY_SEVEN);
        io.KeysDown[KEY_EIGHT         ] = IsKeyDown(KEY_EIGHT);
        io.KeysDown[KEY_NINE          ] = IsKeyDown(KEY_NINE);
        io.KeysDown[KEY_SEMICOLON     ] = IsKeyDown(KEY_SEMICOLON);
        io.KeysDown[KEY_EQUAL         ] = IsKeyDown(KEY_EQUAL);
        io.KeysDown[KEY_A             ] = IsKeyDown(KEY_A);
        io.KeysDown[KEY_B             ] = IsKeyDown(KEY_B);
        io.KeysDown[KEY_C             ] = IsKeyDown(KEY_C);
        io.KeysDown[KEY_D             ] = IsKeyDown(KEY_D);
        io.KeysDown[KEY_E             ] = IsKeyDown(KEY_E);
        io.KeysDown[KEY_F             ] = IsKeyDown(KEY_F);
        io.KeysDown[KEY_G             ] = IsKeyDown(KEY_G);
        io.KeysDown[KEY_H             ] = IsKeyDown(KEY_H);
        io.KeysDown[KEY_I             ] = IsKeyDown(KEY_I);
        io.KeysDown[KEY_J             ] = IsKeyDown(KEY_J);
        io.KeysDown[KEY_K             ] = IsKeyDown(KEY_K);
        io.KeysDown[KEY_L             ] = IsKeyDown(KEY_L);
        io.KeysDown[KEY_M             ] = IsKeyDown(KEY_M);
        io.KeysDown[KEY_N             ] = IsKeyDown(KEY_N);
        io.KeysDown[KEY_O             ] = IsKeyDown(KEY_O);
        io.KeysDown[KEY_P             ] = IsKeyDown(KEY_P);
        io.KeysDown[KEY_Q             ] = IsKeyDown(KEY_Q);
        io.KeysDown[KEY_R             ] = IsKeyDown(KEY_R);
        io.KeysDown[KEY_S             ] = IsKeyDown(KEY_S);
        io.KeysDown[KEY_T             ] = IsKeyDown(KEY_T);
        io.KeysDown[KEY_U             ] = IsKeyDown(KEY_U);
        io.KeysDown[KEY_V             ] = IsKeyDown(KEY_V);
        io.KeysDown[KEY_W             ] = IsKeyDown(KEY_W);
        io.KeysDown[KEY_X             ] = IsKeyDown(KEY_X);
        io.KeysDown[KEY_Y             ] = IsKeyDown(KEY_Y);
        io.KeysDown[KEY_Z             ] = IsKeyDown(KEY_Z);
        io.KeysDown[KEY_SPACE         ] = IsKeyDown(KEY_SPACE);
        io.KeysDown[KEY_ESCAPE        ] = IsKeyDown(KEY_ESCAPE);
        io.KeysDown[KEY_ENTER         ] = IsKeyDown(KEY_ENTER);
        io.KeysDown[KEY_TAB           ] = IsKeyDown(KEY_TAB);
        io.KeysDown[KEY_BACKSPACE     ] = IsKeyDown(KEY_BACKSPACE);
        io.KeysDown[KEY_INSERT        ] = IsKeyDown(KEY_INSERT);
        io.KeysDown[KEY_DELETE        ] = IsKeyDown(KEY_DELETE);
        io.KeysDown[KEY_RIGHT         ] = IsKeyDown(KEY_RIGHT);
        io.KeysDown[KEY_LEFT          ] = IsKeyDown(KEY_LEFT);
        io.KeysDown[KEY_DOWN          ] = IsKeyDown(KEY_DOWN);
        io.KeysDown[KEY_UP            ] = IsKeyDown(KEY_UP);
        io.KeysDown[KEY_PAGE_UP       ] = IsKeyDown(KEY_PAGE_UP);
        io.KeysDown[KEY_PAGE_DOWN     ] = IsKeyDown(KEY_PAGE_DOWN);
        io.KeysDown[KEY_HOME          ] = IsKeyDown(KEY_HOME);
        io.KeysDown[KEY_END           ] = IsKeyDown(KEY_END);
        io.KeysDown[KEY_CAPS_LOCK     ] = IsKeyDown(KEY_CAPS_LOCK);
        io.KeysDown[KEY_SCROLL_LOCK   ] = IsKeyDown(KEY_SCROLL_LOCK);
        io.KeysDown[KEY_NUM_LOCK      ] = IsKeyDown(KEY_NUM_LOCK);
        io.KeysDown[KEY_PRINT_SCREEN  ] = IsKeyDown(KEY_PRINT_SCREEN);
        io.KeysDown[KEY_PAUSE         ] = IsKeyDown(KEY_PAUSE);
        io.KeysDown[KEY_F1            ] = IsKeyDown(KEY_F1);
        io.KeysDown[KEY_F2            ] = IsKeyDown(KEY_F2);
        io.KeysDown[KEY_F3            ] = IsKeyDown(KEY_F3);
        io.KeysDown[KEY_F4            ] = IsKeyDown(KEY_F4);
        io.KeysDown[KEY_F5            ] = IsKeyDown(KEY_F5);
        io.KeysDown[KEY_F6            ] = IsKeyDown(KEY_F6);
        io.KeysDown[KEY_F7            ] = IsKeyDown(KEY_F7);
        io.KeysDown[KEY_F8            ] = IsKeyDown(KEY_F8);
        io.KeysDown[KEY_F9            ] = IsKeyDown(KEY_F9);
        io.KeysDown[KEY_F10           ] = IsKeyDown(KEY_F10);
        io.KeysDown[KEY_F11           ] = IsKeyDown(KEY_F11);
        io.KeysDown[KEY_F12           ] = IsKeyDown(KEY_F12);
        io.KeysDown[KEY_LEFT_SHIFT    ] = IsKeyDown(KEY_LEFT_SHIFT);
        io.KeysDown[KEY_LEFT_CONTROL  ] = IsKeyDown(KEY_LEFT_CONTROL);
        io.KeysDown[KEY_LEFT_ALT      ] = IsKeyDown(KEY_LEFT_ALT);
        io.KeysDown[KEY_LEFT_SUPER    ] = IsKeyDown(KEY_LEFT_SUPER);
        io.KeysDown[KEY_RIGHT_SHIFT   ] = IsKeyDown(KEY_RIGHT_SHIFT);
        io.KeysDown[KEY_RIGHT_CONTROL ] = IsKeyDown(KEY_RIGHT_CONTROL);
        io.KeysDown[KEY_RIGHT_ALT     ] = IsKeyDown(KEY_RIGHT_ALT);
        io.KeysDown[KEY_RIGHT_SUPER   ] = IsKeyDown(KEY_RIGHT_SUPER);
        io.KeysDown[KEY_KB_MENU       ] = IsKeyDown(KEY_KB_MENU);
        io.KeysDown[KEY_LEFT_BRACKET  ] = IsKeyDown(KEY_LEFT_BRACKET);
        io.KeysDown[KEY_BACKSLASH     ] = IsKeyDown(KEY_BACKSLASH);
        io.KeysDown[KEY_RIGHT_BRACKET ] = IsKeyDown(KEY_RIGHT_BRACKET);
        io.KeysDown[KEY_GRAVE         ] = IsKeyDown(KEY_GRAVE);
        io.KeysDown[KEY_KP_0          ] = IsKeyDown(KEY_KP_0);
        io.KeysDown[KEY_KP_1          ] = IsKeyDown(KEY_KP_1);
        io.KeysDown[KEY_KP_2          ] = IsKeyDown(KEY_KP_2);
        io.KeysDown[KEY_KP_3          ] = IsKeyDown(KEY_KP_3);
        io.KeysDown[KEY_KP_4          ] = IsKeyDown(KEY_KP_4);
        io.KeysDown[KEY_KP_5          ] = IsKeyDown(KEY_KP_5);
        io.KeysDown[KEY_KP_6          ] = IsKeyDown(KEY_KP_6);
        io.KeysDown[KEY_KP_7          ] = IsKeyDown(KEY_KP_7);
        io.KeysDown[KEY_KP_8          ] = IsKeyDown(KEY_KP_8);
        io.KeysDown[KEY_KP_9          ] = IsKeyDown(KEY_KP_9);
        io.KeysDown[KEY_KP_DECIMAL    ] = IsKeyDown(KEY_KP_DECIMAL);
        io.KeysDown[KEY_KP_DIVIDE     ] = IsKeyDown(KEY_KP_DIVIDE);
        io.KeysDown[KEY_KP_MULTIPLY   ] = IsKeyDown(KEY_KP_MULTIPLY);
        io.KeysDown[KEY_KP_SUBTRACT   ] = IsKeyDown(KEY_KP_SUBTRACT);
        io.KeysDown[KEY_KP_ADD        ] = IsKeyDown(KEY_KP_ADD);
        io.KeysDown[KEY_KP_ENTER      ] = IsKeyDown(KEY_KP_ENTER);
        io.KeysDown[KEY_KP_EQUAL      ] = IsKeyDown(KEY_KP_EQUAL);
        io.KeyShift = (io.KeysDown[KEY_LEFT_SHIFT  ] || io.KeysDown[KEY_RIGHT_SHIFT  ]);
        io.KeyCtrl  = (io.KeysDown[KEY_LEFT_CONTROL] || io.KeysDown[KEY_RIGHT_CONTROL]);
        io.KeyAlt   = (io.KeysDown[KEY_LEFT_ALT    ] || io.KeysDown[KEY_RIGHT_ALT    ]);
        io.KeySuper = (io.KeysDown[KEY_LEFT_SUPER  ] || io.KeysDown[KEY_RIGHT_SUPER  ]);

        int key = GetKeyPressed();
        if ((key >= 32) && (key <= 125)) {
            io.AddInputCharacter(static_cast<ImWchar>(key));
        }

        io.DeltaTime = GetFrameTime();

        if (io.WantSetMousePos) {
            SetMousePosition((int)io.MousePos.x, (int)io.MousePos.y);
        } else {
            Vector2 mousePos = GetMousePosition();
            io.MousePos = ImVec2(mousePos.x, mousePos.y);
        }
    }

    void draw(){
        update();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
        ImGui::Begin("Mars Game Stats", NULL, ImGuiWindowFlags_None);
            ImGui::Text("FPS: %d", GetFPS());
        ImGui::End();
        ImGui::PopStyleColor();

    }

    void render(){
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}

namespace ImGuiExt {
    bool SliderFloatWithSteps(const char* label, float* v, float v_min, float v_max, float v_step, const char* display_format) {
        if (!display_format)
            display_format = "%.3f";

        char text_buf[64] = {};
        ImFormatString(text_buf, IM_ARRAYSIZE(text_buf), display_format, *v);

        // Map from [v_min,v_max] to [0,N]
        const int countValues = int((v_max-v_min)/v_step);
        int v_i = int((*v - v_min)/v_step);
        const bool value_changed = ImGui::SliderInt(label, &v_i, 0, countValues, text_buf);

        // Remap from [0,N] to [v_min,v_max]
        *v = v_min + float(v_i) * v_step;
        return value_changed;
    }
}