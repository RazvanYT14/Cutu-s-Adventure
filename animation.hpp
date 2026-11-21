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

inline Animation Water0a(2,{"assets/WaterAnim/Water/WaterA.png","assets/WaterAnim/Water/WaterB.png"},1.2f);
inline Animation Water1a(2,{"assets/WaterAnim/Water1/Water1A.png","assets/WaterAnim/Water1/Water1B.png"},1.2f);
inline Animation Water2a(2,{"assets/WaterAnim/Water2/Water2A.png","assets/WaterAnim/Water2/Water2B.png"},1.2f);
inline Animation Water3a(2,{"assets/WaterAnim/Water3/Water3A.png","assets/WaterAnim/Water3/Water3B.png"},1.2f);
inline Animation Water4a(2,{"assets/WaterAnim/Water4/Water4A.png","assets/WaterAnim/Water4/Water4B.png"},1.2f);
inline Animation Water5a(2,{"assets/WaterAnim/Water5/Water5A.png","assets/WaterAnim/Water5/Water5B.png"},1.2f);
inline Animation Water6a(2,{"assets/WaterAnim/Water6/Water6A.png","assets/WaterAnim/Water6/Water6B.png"},1.2f);
inline Animation Water7a(2,{"assets/WaterAnim/Water7/Water7A.png","assets/WaterAnim/Water7/Water7B.png"},1.2f);
inline Animation Water8a(2,{"assets/WaterAnim/Water8/Water8A.png","assets/WaterAnim/Water8/Water8B.png"},1.2f);

inline Animation bushAnim(2,{"assets/PropsAnim/Bush/Bush1.png","assets/PropsAnim/Bush/Bush2.png"},1.f);

inline Animation barrelBreak(5,{"assets/PropsAnim/Barrel/BarrelBreak1.png",
                                "assets/PropsAnim/Barrel/BarrelBreak2.png",
                                "assets/PropsAnim/Barrel/BarrelBreak3.png",
                                "assets/PropsAnim/Barrel/BarrelBreak4.png",
                                "assets/PropsAnim/Barrel/BarrelBreak5.png"},0.5f);

inline Animation bsIdle(2,{"assets/BlackSmithIdle/bsIdle1.png","assets/BlackSmithIdle/bsIdle2.png"},1.f);

inline Animation swimIdle(2,{"assets/swimIdle/swimIdle1.png","assets/swimIdle/swimIdle2.png"},1.f);
inline Animation swim(2,{"assets/Swim/swimIdle1.png","assets/Swim/swimIdle2.png"},1.f);
