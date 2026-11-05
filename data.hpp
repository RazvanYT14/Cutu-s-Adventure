#pragma once

#include "iostream"
#include "fstream"
#include "windows.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stdio.h>

#include "Primary.hpp"
#include "Secondary.hpp"

#include "weaponActivation.hpp"

#include "tilemap.hpp"

#include "movement.hpp"
#include "Dummy.hpp"
#include "Barrel.hpp"

struct Button;

inline float px=12, py=12;

inline float vx = 0.0f;
inline float vy = 0.0f;
inline float ACCELERATION = 0.6f;
inline const float FRICTION = 0.77f;

inline std::string username;

inline bool isMoving = false;

inline int playerHP = 3;

inline float tileSize = 40.f;

inline bool wasMoving = false;

inline bool isAttacking = false;

inline const float rollVAdd = 30.f;

enum class VisWeapon {
    Shuriken,
    Spear,
    Sword,
    None
};

inline VisWeapon currentWeapon = VisWeapon::None;

enum class guiStateMachine {
    Equipment,
    Settings,
    None
};

inline guiStateMachine guiState = guiStateMachine::None;

enum class settingsStateMachine {
    Video,
    Sound,
    None
};

inline settingsStateMachine settingsState = settingsStateMachine::None;

inline std::string currentWeaponName = "None";

inline sf::Clock menuClock;

inline bool isFlying = false;
inline sf::Vector2f velocity{0.f, 0.f};
inline const float speedPerFrame = 8.f;

inline int selectedThrowable=0;

inline int level = 0;

inline bool inInv = false;

inline bool pSel = false;
inline bool sSel = false;

inline std::vector<secondary> throwables {
    {"Shuriken", 50, true, true, 8}
};

inline std::vector<primary> melees {
    {"Spear", false, true, 5, 200},
    {"Sword", true, true, 10, 300}
};


inline bool isAnyPrimarySelected() {
    for (size_t i = 0; i < melees.size(); i++) {
        if (melees[i].selected) {
            return true;
        }
    }
    return false;
}

inline bool isAnySecondarySelected() {
    for (size_t i = 0; i < throwables.size(); i++) {
        if (throwables[i].selected) {
            return true;
        }
    }
    return false;
}



inline bool animations = true;

inline int walkAnim = 1;

inline bool rolling = false;

inline sf::Clock deltaClock;


