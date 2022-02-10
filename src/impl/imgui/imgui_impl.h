#ifndef MercuryImplH
#define MercuryImplH

namespace MercuryImGui {
    void bind();
    void draw();
    void render();
}

namespace ImGuiExt {
    bool SliderFloatWithSteps(const char* label, float* v, float v_min, float v_max, float v_step, const char* display_format);
}

#endif