#pragma once
#include "animation.hpp"
#include "SoundEngine.hpp"

inline void movementSystem(bool& wasMoving, float& vy,
                    float& vx, float& ACCELERATION,
                    sf::Clock& menuClock,
                    bool& rolling, sf::Sprite& player,
                    sf::Texture& playerTEX, bool& isMoving, const float& rollVAdd, float& dt,
                    soundTypes& s, int& maxp, int& minp, bool& inWater) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ) {  vy -= ACCELERATION*dt; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ) {  vy += ACCELERATION*dt; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ) {  player.setScale({1.f,1.f}); vx -= ACCELERATION*dt; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ) {  player.setScale({-1.f,1.f}); vx += ACCELERATION*dt; }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ) { isMoving = true;} else { isMoving=false; }

    //ROLLING
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !inWater) {
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
        wasMoving = isMoving;
    }

    if (!isMoving && !inWater) {
        idle.play(player,dt);
    }
    else if(isMoving && !rolling && !inWater) {
        run.play(player, dt);

        s.playerWalking.setVolume(5.f);

        static bool startedWalking = true;

        if (startedWalking) {
            float randomPitch = (minp + (rand() % (maxp - minp + 1))) / 100.0f;
            s.playerWalking.setPitch(randomPitch);
            s.playerWalking.play();

            startedWalking = false;
        }
        if (s.playerWalking.getStatus() == sf::Sound::Status::Stopped) {
            startedWalking = true;
        }
    }

    if (!isMoving && inWater) {
        swimIdle.play(player,dt);
    }
    else if(isMoving && !rolling && inWater) {
        swim.play(player, dt);

        s.playerSwimming.setVolume(50.f);

        static bool startedSwimming = true;

        if (startedSwimming) {
            float randomPitch = (minp + (rand() % (maxp - minp + 1))) / 100.0f;
            s.playerSwimming.setPitch(randomPitch);
            s.playerSwimming.play();

            startedSwimming = false;
        }
        if (s.playerSwimming.getStatus() == sf::Sound::Status::Stopped) {
            startedSwimming = true;
        }
    }
    if (rolling) {
        roll.play(player,dt);

        s.roll.setVolume(50.f);

        static bool startedRolling = true;

        if (startedRolling) {
            float randomPitch = (minp + (rand() % (maxp - minp + 1))) / 100.0f;
            s.roll.setPitch(randomPitch);
            s.roll.play();

            startedRolling = false;
        }
        if (s.roll.getStatus() == sf::Sound::Status::Stopped) {
            startedRolling = true;
        }
    }
}
