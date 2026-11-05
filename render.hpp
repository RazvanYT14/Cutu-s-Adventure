#pragma once
#include "tilemap.hpp"
#include "data.hpp"

void groundRender(
    sf::RenderWindow& window,
    char groundMap[N][N],
    tileTypes& t,
    sf::View& view
) {
        sf::Vector2f viewSize = view.getSize();
        sf::Vector2f viewCenter = view.getCenter();

        int startX = std::clamp((int)((viewCenter.x - viewSize.x / 2.0f) / 40.0f) - 1, 0, N);
        int startY = std::clamp((int)((viewCenter.y - viewSize.y / 2.0f) / 40.0f) - 1, 0, N);
        int endX   = std::clamp((int)((viewCenter.x + viewSize.x / 2.0f) / 40.0f) + 1, 0, N);
        int endY   = std::clamp((int)((viewCenter.y + viewSize.y / 2.0f) / 40.0f) + 1, 0, N);

        if (startX >= endX && endX > 0) startX = endX - 1;
        if (startY >= endY && endY > 0) startY = endY - 1;

        for (int ry = startY; ry < endY; ++ry) {
            for (int rx = startX; rx < endX; ++rx) {
                if (groundMap[ry][rx] == GRASS) {
                    t.grass.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.grass);
                }
                else if (groundMap[ry][rx] == GRASS2) {
                    t.grass2.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.grass2);
                }
                else if (groundMap[ry][rx] == SPIKES) {
                    t.grass.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.grass);
                    t.spikes.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.spikes);
                }
                else if (groundMap[ry][rx] == WALL1) {
                    t.Wall1.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Wall1);
                }
                else if (groundMap[ry][rx] == WALL1t2) {
                    t.Wall1_2.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Wall1_2);
                }
                else if (groundMap[ry][rx] == WALL1t3) {
                    t.Wall1_3.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Wall1_3);
                }
                else if (groundMap[ry][rx] == WALL2) {
                    t.Wall2.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Wall2);
                }
                else if (groundMap[ry][rx] == WALL2t2) {
                    t.Wall2_2.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Wall2_2);
                }
                else if (groundMap[ry][rx] == WALL3) {
                    t.Wall3.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Wall3);
                }
                else if (groundMap[ry][rx] == WALL3t2) {
                    t.Wall3_2.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Wall3_2);
                }
                else if (groundMap[ry][rx] == WALL3t3) {
                    t.Wall3_3.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Wall3_3);
                }
                else if (groundMap[ry][rx] == CRAFTINGTABLE) {
                    t.craftingTable.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.craftingTable);
                }
                else if (groundMap[ry][rx] == UPPER_GRASS) {
                    t.UpperGrass.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.UpperGrass);
                }
                else if (groundMap[ry][rx] == STAIR) {
                    t.stair.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.stair);
                }
                else if (groundMap[ry][rx] == WATER) {
                    t.Water.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Water);
                }
                else if (groundMap[ry][rx] == WATER1) {
                    t.Water1.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Water1);
                }
                else if (groundMap[ry][rx] == WATER2) {
                    t.Water2.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Water2);
                }
                else if (groundMap[ry][rx] == WATER3) {
                    t.Water3.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Water3);
                }
                else if (groundMap[ry][rx] == WATER4) {
                    t.Water4.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Water4);
                }
                else if (groundMap[ry][rx] == WATER5) {
                    t.Water5.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Water5);
                }
                else if (groundMap[ry][rx] == WATER6) {
                    t.Water6.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Water6);
                }
                else if (groundMap[ry][rx] == WATER7) {
                    t.Water7.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Water7);
                }
                else if (groundMap[ry][rx] == WATER8) {
                    t.Water8.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Water8);
                }
                else if (groundMap[ry][rx] == BRIDGE1) {
                    t.Bridge1.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.Bridge1);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS1) {
                    t.ShadedGrass1.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass1);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS2) {
                    t.ShadedGrass2.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass2);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS3) {
                    t.ShadedGrass3.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass3);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS4) {
                    t.ShadedGrass4.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass4);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS5) {
                    t.ShadedGrass5.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass5);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS6) {
                    t.ShadedGrass6.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass6);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS7) {
                    t.ShadedGrass7.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass7);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS8) {
                    t.ShadedGrass8.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass8);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS9) {
                    t.ShadedGrass9.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass9);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS10) {
                    t.ShadedGrass10.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass10);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS11) {
                    t.ShadedGrass11.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass11);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS12) {
                    t.ShadedGrass12.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass12);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS13) {
                    t.ShadedGrass13.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass13);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS14) {
                    t.ShadedGrass14.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass14);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS15) {
                    t.ShadedGrass15.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass15);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS16) {
                    t.ShadedGrass16.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass16);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS17) {
                    t.ShadedGrass17.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass17);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS18) {
                    t.ShadedGrass18.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass18);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS18) {
                    t.ShadedGrass18.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass18);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS19) {
                    t.ShadedGrass19.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass19);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS20) {
                    t.ShadedGrass20.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass20);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS21) {
                    t.ShadedGrass21.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass21);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS22) {
                    t.ShadedGrass22.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass22);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS23) {
                    t.ShadedGrass23.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass23);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS24) {
                    t.ShadedGrass24.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass24);
                }
                else if (groundMap[ry][rx] == SHADEDGRASS25) {
                    t.ShadedGrass25.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                    window.draw(t.ShadedGrass25);
                }
            }
        }
}

void propsRender(sf::RenderWindow& window, char propsMap[N][N], sf::View& view,
                 tileTypes& t , sf::RectangleShape& weaponHitbox,
                 bool& isAttacking, sf::Sprite& shuriken) {

    sf::Vector2f viewSize = view.getSize();
    sf::Vector2f viewCenter = view.getCenter();

    int startX = std::clamp((int)((viewCenter.x - viewSize.x / 2.0f) / 40.0f) - 1, 0, N);
    int startY = std::clamp((int)((viewCenter.y - viewSize.y / 2.0f) / 40.0f) - 1, 0, N);
    int endX   = std::clamp((int)((viewCenter.x + viewSize.x / 2.0f) / 40.0f) + 1, 0, N);
    int endY   = std::clamp((int)((viewCenter.y + viewSize.y / 2.0f) / 40.0f) + 1, 0, N);

    for(int ry = startY; ry < endY; ++ry) {
        for(int rx = startX; rx < endX; ++rx) {
            if(propsMap[ry][rx] == BUSH) {
                t.Bush.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                window.draw(t.Bush);
            }
            else if(propsMap[ry][rx] == DUMMY) {
                t.dummy.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                getAttacked(t.dummy, weaponHitbox, isAttacking, shuriken);

                window.draw(t.dummy);
            }
            else if(propsMap[ry][rx] == BARREL) {
                t.Barrel.setPosition(sf::Vector2f({rx * 40.0f, ry * 40.0f}));
                getDestroyed(t.Barrel, weaponHitbox, isAttacking, shuriken, rx, ry);

                window.draw(t.Barrel);
            }
        }
    }
}
