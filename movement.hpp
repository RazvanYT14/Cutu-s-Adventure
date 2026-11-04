#pragma once
#include "animation.hpp"

inline void movementSystem(bool& wasMoving, float& vy,
                    float& vx, float& ACCELERATION,
                    sf::Clock& menuClock,
                    bool& rolling, sf::Sprite& player,
                    sf::Texture& playerTEX, bool& isMoving, const float& rollVAdd) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ) {  vy -= ACCELERATION; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ) {  vy += ACCELERATION; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ) {  player.setScale({1.f,1.f}); vx -= ACCELERATION; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ) {  player.setScale({-1.f,1.f}); vx += ACCELERATION; }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ) { isMoving = true;} else { isMoving=false; }

    //ROLLING
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        if(!rolling) {
            rolling = true;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) vy-=rollVAdd;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) vy+=rollVAdd;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) vx-=rollVAdd;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) vx+=rollVAdd;
            menuClock.restart();
        }
    }

    if(rolling && menuClock.getElapsedTime() >= sf::milliseconds(350)) {
        rolling = false;
        wasMoving = !isMoving;
    }
    if(isMoving != wasMoving) {
        if(isMoving) {
        } else {

        }
        wasMoving = isMoving;
    }
    if (!isMoving) {
        idle.play(player);
    } else {
        run.play(player);
    }
    if (rolling) {
        roll.play(player);
    }
}
