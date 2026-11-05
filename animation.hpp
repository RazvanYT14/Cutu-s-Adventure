#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

struct Animation {
    std::vector<std::shared_ptr<sf::Texture>> textures;
    float ticksPerFrame;
    float tickCounter = 0.f;
    size_t currentFrame = 0.f;

    Animation(size_t frameCount, const std::vector<std::string>& filePaths, float speedInTicks)
        : ticksPerFrame(speedInTicks) {

        size_t limit = std::min(frameCount, filePaths.size());
        for (size_t i = 0; i < limit; ++i) {
            auto texture = std::make_shared<sf::Texture>();
            if (texture->loadFromFile(filePaths[i])) {
                textures.push_back(texture);
            }
        }
    }

    void play(sf::Sprite& sprite, float& dt) {
        if (textures.empty()) return;

        tickCounter+=dt;
        if (tickCounter >= ticksPerFrame) {
            tickCounter = 0;
            currentFrame = (currentFrame + 1) % textures.size();
        }

        sprite.setTexture(*textures[currentFrame]);
    }
};

inline Animation idle(2,{"assets/Idle/idle1.png","assets/Idle/idle2.png"},1.f);
inline Animation run(2,{"assets/Run/run1.png","assets/Run/run2.png"},0.3f);
inline Animation roll(2,{"assets/Roll/roll1.png","assets/Roll/roll2.png"},0.5f);
