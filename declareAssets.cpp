#include "data.hpp"
#include "declareAssets.hpp"

void declareAssets() {
    static sf::RenderWindow window;

    static sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    window.create(desktopMode, "Game", sf::Style::None, sf::State::Windowed);
    window.setVerticalSyncEnabled(true);


    static float zoomFactor = 3.0f;

    static sf::View view;
    view.setSize(sf::Vector2f({
        (float)desktopMode.size.x / zoomFactor,
        (float)desktopMode.size.y / zoomFactor
    }));

    sf::Texture spearTEX("assets/spearTEX.png");

    static sf::Texture swordTEX("assets/swordTEX.png");

    static sf::Texture shurikenTEX("assets/shurikenTEX.png");

    static sf::Sprite shuriken(shurikenTEX);
    shuriken.setScale({0.5,0.5});
    shuriken.setOrigin({15.f, 15.f});

    static sf::Vector2f centerPosition{400.f, 300.f};
    shuriken.setPosition(centerPosition);

    static sf::View guiView;
    guiView.setSize({1280.f, 720.f});
    guiView.setCenter({1280.f / 2.f, 720.f / 2.f});

    view.setCenter(sf::Vector2f({px * 40.0f, py * 40.0f}));

    static sf::Texture playerTEX("assets/playerFrontIdle.png");
    static sf::Sprite player(playerTEX);

    static sf::Font f("assets/font/comic.ttf");

    static sf::Text weaponCount(f);
    weaponCount.setPosition({1150.f,650.f});
    weaponCount.setScale({2.f,2.f});

    static sf::Text selWeaponName(f);
    selWeaponName.setPosition({100.f,400.f});
    selWeaponName.setFillColor(sf::Color::Black);
    selWeaponName.setScale({2.f,2.f});

    static sf::Text selWeaponCount(f);
    selWeaponCount.setPosition({100.f,500.f});
    selWeaponCount.setFillColor(sf::Color::Black);
    selWeaponCount.setScale({2.f,2.f});


    static const sf::Texture equippedShuriken("assets/equippedShuriken.png");
    static const sf::Texture equippedSpear("assets/equippedSpear.png");
    static const sf::Texture equippedSword("assets/equippedSword.png");
    static const sf::Texture equippedFists("assets/equippedFists.png");

    static sf::Sprite equippedWeapon(equippedFists);


    static sf::Vector2u textureSize = playerTEX.getSize();
    player.setOrigin({textureSize.x/2.f,textureSize.y/2.f});
    equippedWeapon.setOrigin({textureSize.x/2.f,textureSize.y/2.f});

    static sf::Texture grassTEX("assets/grassTile.png");
    static sf::Sprite grass(grassTEX);

    static sf::Texture grassTEX2("assets/grassTile2.png");
    static sf::Sprite grass2(grassTEX2);

    static sf::Texture stairTEX("assets/stairTile.png");
    static sf::Sprite stair(stairTEX);

    static sf::Texture craftTabTEX("assets/craftingTable.png");
    static sf::Sprite craftingTable(craftTabTEX);

    static sf::Texture spikesTEX("assets/spikesTile.png");
    static sf::Sprite spikes(spikesTEX);

    static sf::Texture wall1TEX("assets/Wall1Tile.png");
    static sf::Sprite Wall1(wall1TEX);

    static sf::Texture wall1TEX2("assets/Wall1Tile2.png");
    static sf::Sprite Wall1_2(wall1TEX2);

    static sf::Texture wall1TEX3("assets/Wall1Tile3.png");
    static sf::Sprite Wall1_3(wall1TEX3);

    static sf::Texture wall2TEX("assets/Wall2Tile.png");
    static sf::Sprite Wall2(wall2TEX);

    static sf::Texture wall2TEX2("assets/Wall2Tile2.png");
    static sf::Sprite Wall2_2(wall2TEX2);

    static sf::Texture wall3TEX("assets/Wall3Tile.png");
    static sf::Sprite Wall3(wall3TEX);

    static sf::Texture wall3TEX2("assets/Wall3Tile2.png");
    static sf::Sprite Wall3_2(wall3TEX2);

    static sf::Texture wall3TEX3("assets/Wall3Tile3.png");
    static sf::Sprite Wall3_3(wall3TEX3);

    static sf::Texture waterTEX("assets/Water.png");
    static sf::Sprite Water(waterTEX);

    static sf::Texture bridge1TEX("assets/Bridge1.png");
    static sf::Sprite Bridge1(bridge1TEX);

    static sf::Texture water1TEX("assets/Water1.png");
    static sf::Sprite Water1(water1TEX);

    static sf::Texture water2TEX("assets/Water2.png");
    static sf::Sprite Water2(water2TEX);

    static sf::Texture water3TEX("assets/Water3.png");
    static sf::Sprite Water3(water3TEX);

    static sf::Texture water4TEX("assets/Water4.png");
    static sf::Sprite Water4(water4TEX);

    static sf::Texture water5TEX("assets/Water5.png");
    static sf::Sprite Water5(water5TEX);

    static sf::Texture water6TEX("assets/Water6.png");
    static sf::Sprite Water6(water6TEX);

    static sf::Texture water7TEX("assets/Water7.png");
    static sf::Sprite Water7(water7TEX);

    static sf::Texture water8TEX("assets/Water8.png");
    static sf::Sprite Water8(water8TEX);

    static sf::Texture upperGrassTEX("assets/UpperGrassTile.png");
    static sf::Sprite UpperGrass(upperGrassTEX);

    static sf::Texture ShadedGrass1TEX("assets/ShadedGrass1.png");
    static sf::Sprite ShadedGrass1(ShadedGrass1TEX);

    static sf::Texture ShadedGrass2TEX("assets/ShadedGrass2.png");
    static sf::Sprite ShadedGrass2(ShadedGrass2TEX);

    static sf::Texture ShadedGrass3TEX("assets/ShadedGrass3.png");
    static sf::Sprite ShadedGrass3(ShadedGrass3TEX);

    static sf::Texture ShadedGrass4TEX("assets/ShadedGrass4.png");
    static sf::Sprite ShadedGrass4(ShadedGrass4TEX);

    static sf::Texture ShadedGrass5TEX("assets/ShadedGrass5.png");
    static sf::Sprite ShadedGrass5(ShadedGrass5TEX);

    static sf::Texture ShadedGrass6TEX("assets/ShadedGrass6.png");
    static sf::Sprite ShadedGrass6(ShadedGrass6TEX);

    static sf::Texture ShadedGrass7TEX("assets/ShadedGrass7.png");
    static sf::Sprite ShadedGrass7(ShadedGrass7TEX);

    static sf::Texture ShadedGrass8TEX("assets/ShadedGrass8.png");
    static sf::Sprite ShadedGrass8(ShadedGrass8TEX);

    static sf::Texture ShadedGrass9TEX("assets/ShadedGrass9.png");
    static sf::Sprite ShadedGrass9(ShadedGrass9TEX);

    static sf::Texture ShadedGrass10TEX("assets/ShadedGrass10.png");
    static sf::Sprite ShadedGrass10(ShadedGrass10TEX);

    static sf::Texture ShadedGrass11TEX("assets/ShadedGrass11.png");
    static sf::Sprite ShadedGrass11(ShadedGrass11TEX);

    static sf::Texture ShadedGrass12TEX("assets/ShadedGrass12.png");
    static sf::Sprite ShadedGrass12(ShadedGrass12TEX);

    static sf::Texture ShadedGrass13TEX("assets/ShadedGrass13.png");
    static sf::Sprite ShadedGrass13(ShadedGrass13TEX);

    static sf::Texture ShadedGrass14TEX("assets/ShadedGrass14.png");
    static sf::Sprite ShadedGrass14(ShadedGrass14TEX);

    static sf::Texture ShadedGrass15TEX("assets/ShadedGrass15.png");
    static sf::Sprite ShadedGrass15(ShadedGrass15TEX);

    static sf::Texture ShadedGrass16TEX("assets/ShadedGrass16.png");
    static sf::Sprite ShadedGrass16(ShadedGrass16TEX);

    static sf::Texture ShadedGrass17TEX("assets/ShadedGrass17.png");
    static sf::Sprite ShadedGrass17(ShadedGrass17TEX);

    static sf::Texture ShadedGrass18TEX("assets/ShadedGrass18.png");
    static sf::Sprite ShadedGrass18(ShadedGrass18TEX);

    static sf::Texture ShadedGrass19TEX("assets/ShadedGrass19.png");
    static sf::Sprite ShadedGrass19(ShadedGrass19TEX);

    static sf::Texture ShadedGrass20TEX("assets/ShadedGrass20.png");
    static sf::Sprite ShadedGrass20(ShadedGrass20TEX);

    static sf::Texture ShadedGrass21TEX("assets/ShadedGrass21.png");
    static sf::Sprite ShadedGrass21(ShadedGrass21TEX);

    static sf::Texture ShadedGrass22TEX("assets/ShadedGrass22.png");
    static sf::Sprite ShadedGrass22(ShadedGrass22TEX);

    static sf::Texture ShadedGrass23TEX("assets/ShadedGrass23.png");
    static sf::Sprite ShadedGrass23(ShadedGrass23TEX);

    static sf::Texture ShadedGrass24TEX("assets/ShadedGrass24.png");
    static sf::Sprite ShadedGrass24(ShadedGrass24TEX);

    static sf::Texture ShadedGrass25TEX("assets/ShadedGrass25.png");
    static sf::Sprite ShadedGrass25(ShadedGrass25TEX);

    static sf::Texture bushTEX("assets/Bush.png");
    static sf::Sprite Bush(bushTEX);

    static sf::RectangleShape inventoryBACKGROUND;
    inventoryBACKGROUND.setSize({1200.f,600.f});
    inventoryBACKGROUND.setPosition({40.f,40.f});
    inventoryBACKGROUND.setFillColor(sf::Color(255, 255, 255, 150));
    inventoryBACKGROUND.setOutlineColor(sf::Color(0, 0, 0, 255));
    inventoryBACKGROUND.setOutlineThickness(10.f);

    static sf::RectangleShape primariesHUD;
    primariesHUD.setSize({900.f,120.f});
    primariesHUD.setPosition({60.f,112.f});
    primariesHUD.setFillColor(sf::Color::Yellow);

    static sf::RectangleShape secondariesHUD;
    secondariesHUD.setSize({900.f,120.f});
    secondariesHUD.setPosition({60.f,230.f});
    secondariesHUD.setFillColor(sf::Color::Blue);

    static sf::Texture arrowUP("assets/arrowUP.png");
    static sf::Texture arrowDOWN("assets/arrowDOWN.png");
    static sf::Texture arrowLEFT("assets/arrowLEFT.png");
    static sf::Texture arrowRIGHT("assets/arrowRIGHT.png");

    static sf::Texture inventoryBUTTON("assets/inventoryBUTTON.png");

    static sf::Texture exitBUT("assets/exitBUT.png");

    static sf::Texture equipTEX("assets/equipBUT.png");
}
