#pragma once
#include "animation.hpp"

inline void movementSystem(bool& wasMoving, float& vy,
                    float& vx, float& ACCELERATION,
                    sf::Clock& menuClock,
                    bool& rolling, sf::Sprite& player,
                    sf::Texture& playerTEX, bool& isMoving, const float& rollVAdd, float& dt ) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ) {  vy -= ACCELERATION*dt; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ) {  vy += ACCELERATION*dt; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ) {  player.setScale({1.f,1.f}); vx -= ACCELERATION*dt; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ) {  player.setScale({-1.f,1.f}); vx += ACCELERATION*dt; }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ) { isMoving = true;} else { isMoving=false; }

    //ROLLING
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        if(!rolling) {
            rolling = true;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) vy-=rollVAdd*dt;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) vy+=rollVAdd*dt;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) vx-=rollVAdd*dt;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) vx+=rollVAdd*dt;
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
        idle.play(player,dt);
    } else {
        run.play(player,dt);
    }
    if (rolling) {
        roll.play(player,dt);
    }
}
