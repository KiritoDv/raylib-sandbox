#include "emscripten_utils.h"

EM_JS(int, getWindowWidth, (), {
    return Math.round(window.innerWidth);
});

EM_JS(int, getWindowHeigth, (), {
    return Math.round(window.innerHeight);
});

namespace EMS {
    Vector2 getWindowSize() {
        return { (float) getWindowWidth(), (float) getWindowHeigth() };
    }
}