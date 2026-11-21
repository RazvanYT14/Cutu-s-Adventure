#include <SFML/Graphics/RenderWindow.hpp>

struct OpenGLFix {
    OpenGLFix() {
        sf::RenderWindow dummy(sf::VideoMode({1, 1}), "Fix");
        dummy.close();
    }
};

static OpenGLFix g_ForceOpenGLInit;
