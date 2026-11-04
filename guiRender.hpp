#pragma once
#include "Button.hpp"
#include "data.hpp"

void RenderGUI(
    sf::RenderWindow& window,
    bool& inInv,
    VisWeapon& currentWeapon,
    guiStateMachine& guiState,
    settingsStateMachine& settingsState,
    float& zoomFactor,
    sf::Text& selWeaponName,
    sf::Text& selWeaponCount,
    sf::Text& selWeaponDamage,
    std::vector<secondary>& throwables,
    auto& animations,
    auto& melees,
    sf::RectangleShape& inventoryBACKGROUND,
    sf::RectangleShape& guiTOP,
    sf::Text& guiStateText,
    sf::Text& settingsStateText,
    Button& primaryBUT,
    Button& secondaryBUT,
    Button& ExitBUT,
    bool& pSel,
    bool& sSel,
    sf::Sprite& Arrow,
    Button& SwordBUT,
    Button& SpearBUT,
    Button& ShurikenBUT,
    Button& invBUT
) {

        if (!inInv) {
            invBUT.draw(window);
            if (animations) {
                if (zoomFactor > 3.5f) {
                    zoomFactor -= 0.05f;
                    if (zoomFactor < 3.5f) zoomFactor = 3.5f;
                }
            }
        }

            if (animations) {
                if (zoomFactor < 5.0f) {
                    zoomFactor += 0.05f;
                    if (zoomFactor > 5.0f) zoomFactor = 5.0f;
                }
            }
        if(inInv && guiState==guiStateMachine::Equipment) {

            if(currentWeapon==VisWeapon::None) {
                selWeaponName.setString("Name: None");
                selWeaponCount.setString("Count: NA");
                selWeaponDamage.setString("Damage: NA");
            }
            if(currentWeapon==VisWeapon::Shuriken) {
                selWeaponName.setString("Name: Shuriken");
                selWeaponCount.setString("Count: "+std::to_string(throwables[0].c));
                selWeaponDamage.setString("Damage: "+std::to_string(throwables[0].damage));
            }
            if(currentWeapon==VisWeapon::Spear) {
                selWeaponName.setString("Name: Spear");
                selWeaponCount.setString("OWNED");
                selWeaponDamage.setString("Damage: "+std::to_string(melees[0].damage));
            }
            if(currentWeapon==VisWeapon::Sword) {
                selWeaponName.setString("Name: Sword");
                selWeaponCount.setString("OWNED");
                selWeaponDamage.setString("Damage: "+std::to_string(melees[1].damage));
            }

            settingsState = settingsStateMachine::None;

            window.draw(inventoryBACKGROUND);
            window.draw(guiTOP);
            window.draw(guiStateText);

            primaryBUT.draw(window);
            secondaryBUT.draw(window);

            ExitBUT.draw(window);

            window.draw(selWeaponName);
            window.draw(selWeaponCount);
            window.draw(selWeaponDamage);

            if(pSel) {
                sSel=false;
                SwordBUT.draw(window);
                SpearBUT.draw(window);
            }
            else if(sSel) {
                pSel=false;
                ShurikenBUT.draw(window);
            }


        }
        else if(inInv && guiState==guiStateMachine::Settings) {

            if(settingsState==settingsStateMachine::None) { settingsState=settingsStateMachine::Video; }

            window.draw(inventoryBACKGROUND);
            window.draw(guiTOP);
            window.draw(guiStateText);
            window.draw(settingsStateText);
            ExitBUT.draw(window);
        }

}
