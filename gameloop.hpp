#pragma once

#include "data.hpp"

#include "Button.hpp"

#include "render.hpp"
#include "guiRender.hpp"
#include "tilemap.hpp"
#include "animation.hpp"
#include <memory>
#include "SoundEngine.hpp"

inline void meleeActivation(std::optional<sf::Event>& event, sf::Sprite& equippedWeapon, const sf::Texture& equippedSpear,
                            const sf::Texture& equippedSword, const sf::Texture& equippedScythe, sf::Clock& attackClock, sf::RenderWindow& window,
                            const sf::View& guiView, const sf::Sprite& player, const sf::Texture& equippedFists) {

    int delay = 300;
    if(melees[0].selected) { delay = melees[0].cooldown; }
    if(melees[1].selected) { delay = melees[1].cooldown; }
    if(melees[2].selected) { delay = melees[2].cooldown; }

    if (attackClock.getElapsedTime() < sf::milliseconds(delay)) {
        sf::Angle currentAngle = equippedWeapon.getRotation();
        sf::Vector2f attackDir(std::cos(currentAngle.asRadians()), std::sin(currentAngle.asRadians()));
        equippedWeapon.setPosition(player.getPosition() + (attackDir * 30.f));

        if(melees[1].selected) {
            s.slash.setVolume(80.f);

            static bool startedSlashing = true;

            if (startedSlashing) {
                float randomPitch = (minp + (rand() % (maxp - minp + 1))) / 100.0f;
                s.slash.setPitch(randomPitch);
                s.slash.play();

                startedSlashing = false;
            }
            if (s.slash.getStatus() == sf::Sound::Status::Stopped) {
                startedSlashing = true;
            }
        }
        else if(melees[0].selected) {
            s.jab.setVolume(80.f);

            static bool startedJabbing = true;

            if (startedJabbing) {
                float randomPitch = (minp + (rand() % (maxp - minp + 1))) / 100.0f;
                s.jab.setPitch(randomPitch);
                s.jab.play();

                startedJabbing = false;
            }
            if (s.jab.getStatus() == sf::Sound::Status::Stopped) {
                startedJabbing = true;
            }
        }
        else if(melees[2].selected) {
            s.slash.setVolume(80.f);

            static bool startedSlashing = true;

            if (startedSlashing) {
                float randomPitch = (minp + (rand() % (maxp - minp + 1))) / 100.0f;
                s.slash.setPitch(randomPitch);
                s.slash.play();

                startedSlashing = false;
            }
            if (s.slash.getStatus() == sf::Sound::Status::Stopped) {
                startedSlashing = true;
            }
        }
    }
    else {
        if (&equippedWeapon.getTexture() != &equippedFists) {
            equippedWeapon.setTexture(equippedFists);
        }
        sf::Vector2f mouseDir = window.mapPixelToCoords(sf::Mouse::getPosition(window)) - player.getPosition();
        if (mouseDir != sf::Vector2f(0.f, 0.f)) {
            equippedWeapon.setRotation(mouseDir.angle());
        }
        equippedWeapon.setPosition(player.getPosition());

        isAttacking = false;
    }

    if (!event.has_value()) return;

    if (const auto* mouseButtonEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mouseButtonEvent->button == sf::Mouse::Button::Left && !inInv) {

            if (attackClock.getElapsedTime() >= sf::milliseconds(delay)) {

                sf::Vector2f clickDir = window.mapPixelToCoords(sf::Mouse::getPosition(window)) - player.getPosition();
                if (clickDir != sf::Vector2f(0.f, 0.f)) {
                    equippedWeapon.setRotation(clickDir.angle());
                    equippedWeapon.setPosition(player.getPosition() + (clickDir.normalized() * 30.f));
                }

                if(melees[0].selected) { equippedWeapon.setTexture(equippedSpear); }
                if(melees[1].selected) { equippedWeapon.setTexture(equippedSword); }
                if(melees[2].selected) { equippedWeapon.setTexture(equippedScythe); }

                if(melees[0].selected && melees[0].dura>0) { isAttacking = true; } else if(melees[0].selected && melees[0].dura<=0){ isAttacking = false; }
                if(melees[1].selected && melees[1].dura>0) { isAttacking = true; } else if(melees[1].selected && melees[1].dura<=0){ isAttacking = false; }
                if(melees[2].selected && melees[2].dura>0) { isAttacking = true; } else if(melees[2].selected && melees[2].dura<=0){ isAttacking = false; }

                attackClock.restart();
            }
        }
    }
}

inline void secondaryActivation(std::optional<sf::Event>& event, sf::RenderWindow& window, sf::View& view,
                                sf::Sprite& shuriken, sf::Sprite& equippedWeapon, const sf::Texture& equippedShuriken) {
    if (const auto* mouseButtonEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
        if(throwables[0].selected && !isFlying && throwables[0].c>0) {
            if (mouseButtonEvent->button == sf::Mouse::Button::Right) {

                sf::Vector2f mousePos = window.mapPixelToCoords(mouseButtonEvent->position, view);

                sf::Vector2f centerPosition = view.getCenter();

                shuriken.setPosition(centerPosition);

                sf::Vector2f direction = mousePos - centerPosition;
                float length = std::hypot(direction.x, direction.y);

                if (length > 0.1f) {
                    velocity = (direction / length) * speedPerFrame;
                    isFlying = true;
                }
                throwables[0].c--;

                s.throwShuriken.setVolume(50.f);

                float randomPitch = (minp + (rand() % (maxp - minp + 1))) / 100.0f;
                s.throwShuriken.setPitch(randomPitch);
                s.throwShuriken.play();

            }
        }
    }
}

inline void start() {

    sf::RenderWindow window;

    sf::VideoMode gameMode({800, 450});

    window.create(gameMode, "Cutu's Adventure", sf::State::Fullscreen);
    sf::Image icon;
    if(icon.loadFromFile("assets/icon.png")) {}
    window.setIcon(icon);

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    float zoomFactor = 3.5f;

    sf::View view;
    view.setSize(sf::Vector2f({
        (float)gameMode.size.x * 2 / zoomFactor,
        (float)gameMode.size.y * 2 / zoomFactor
    }));

    sf::Texture spearTEX("assets/spearTEX.png");
    sf::Texture swordTEX("assets/swordTEX.png");
    sf::Texture scytheTEX("assets/scytheTEX.png");
    sf::Texture shurikenTEX("assets/shurikenTEX.png");

    sf::Texture equippedShuriken("assets/equippedShuriken.png");
    sf::Texture equippedSpear("assets/equippedSpear.png");
    sf::Texture equippedSword("assets/equippedSword.png");
    sf::Texture equippedFists("assets/equippedFists.png");
    sf::Texture equippedScythe("assets/equippedScythe.png");

    sf::Sprite shuriken(equippedShuriken);
    shuriken.setScale({0.5f, 0.5f});
    shuriken.setOrigin(sf::Vector2f(shurikenTEX.getSize()) / 2.0f);

    sf::Vector2f centerPosition{400.f, 300.f};
    shuriken.setPosition(centerPosition);

    sf::View guiView;
    guiView.setSize({1280.f, 720.f});
    guiView.setCenter({1280.f / 2.f, 720.f / 2.f});

    sf::Texture playerTEX("assets/Idle/idle1.png");
    sf::Sprite player(playerTEX);

    sf::Texture healthBarTEX100("assets/Health100%.png");
    sf::Texture healthBarTEX66("assets/Health66%.png");
    sf::Texture healthBarTEX33("assets/Health33%.png");
    sf::Texture healthBarTEX0("assets/Health0%.png");
    sf::Sprite healthBar(healthBarTEX100);
    healthBar.setScale({8.f,8.f});
    healthBar.setPosition({10.f,480.f});

    player.setPosition({px * 40.0f, py * 40.0f});
    player.setOrigin(sf::Vector2f(playerTEX.getSize()) / 2.0f);

    view.setCenter(player.getPosition());


    std::string fontPath = "C:\\Windows\\Fonts\\arial.ttf";

    sf::Font f(fontPath);

    sf::Text weaponCount(f);
    weaponCount.setPosition({1150.f,650.f});
    weaponCount.setScale({2.f,2.f});

    sf::Text selWeaponName(f);
    selWeaponName.setPosition({760.f,450.f});
    selWeaponName.setFillColor(sf::Color::Black);
    selWeaponName.setScale({2.f,2.f});

    sf::Text selWeaponCount(f);
    selWeaponCount.setPosition({760.f,530.f});
    selWeaponCount.setFillColor(sf::Color::Black);
    selWeaponCount.setScale({2.f,2.f});

    sf::Text selWeaponDamage(f);
    selWeaponDamage.setPosition({760.f,610.f});
    selWeaponDamage.setFillColor(sf::Color::Black);
    selWeaponDamage.setScale({2.f,2.f});

    sf::Text guiStateText(f);
    guiStateText.setPosition({850.f,15.f});
    guiStateText.setFillColor(sf::Color::Black);
    guiStateText.setScale({2.f,2.f});

    sf::Text settingsStateText(f);
    settingsStateText.setPosition({850.f,90.f});
    settingsStateText.setFillColor(sf::Color::Black);
    settingsStateText.setScale({2.f,2.f});

    sf::Sprite equippedWeapon(equippedFists);


    sf::Vector2u textureSize = playerTEX.getSize();
    player.setOrigin({textureSize.x/2.f,textureSize.y/2.f});
    equippedWeapon.setOrigin({textureSize.x/2.f,textureSize.y/2.f});

    auto t_ptr = std::make_unique<tileTypes>();
    tileTypes& t = *t_ptr;

    sf::RectangleShape inventoryBACKGROUND;
    inventoryBACKGROUND.setSize({1200.f,1200.f});
    inventoryBACKGROUND.setPosition({750.f,0.f});
    inventoryBACKGROUND.setFillColor(sf::Color(127, 127, 127, 240));
    inventoryBACKGROUND.setOutlineColor(sf::Color(83, 83, 83, 250));
    inventoryBACKGROUND.setOutlineThickness(8.f);

    sf::RectangleShape guiTOP;
    guiTOP.setSize({600.f,100.f});
    guiTOP.setPosition({750.f,0.f});
    guiTOP.setFillColor(sf::Color(83, 83, 83, 250));

    sf::RectangleShape primariesHUD;
    primariesHUD.setSize({900.f,120.f});
    primariesHUD.setPosition({60.f,112.f});
    primariesHUD.setFillColor(sf::Color::Transparent);

    sf::RectangleShape secondariesHUD;
    secondariesHUD.setSize({900.f,120.f});
    secondariesHUD.setPosition({60.f,230.f});
    secondariesHUD.setFillColor(sf::Color::Transparent);

    static sf::Texture ArrowTEX("assets/Arrow.png");
    sf::Sprite Arrow(Arrow);

    static sf::Texture arrowUP("assets/arrowUP.png");
    static sf::Texture arrowDOWN("assets/arrowDOWN.png");
    static sf::Texture arrowLEFT("assets/arrowLEFT.png");
    static sf::Texture arrowRIGHT("assets/arrowRIGHT.png");

    static sf::Texture inventoryBUTTON("assets/inventoryBUTTON.png");

    static sf::Texture exitBUT("assets/exitBUT.png");

    static sf::Texture equipTEX("assets/equipBUT.png");

    Button aUP(arrowUP,150.f,500.f,{2.f,2.f});
    Button aDOWN(arrowDOWN,150.f,600.f,{2.f,2.f});
    Button aLEFT(arrowLEFT,96.5f,550.f,{2.f,2.f});
    Button aRIGHT(arrowRIGHT,202.5f,550.f,{2.f,2.f});

    Button invBUT(inventoryBUTTON,1190.f,10.f,{2.5f,2.5f});

    Button ExitBUT(exitBUT,10.f,10.f,{2.5f,2.5f});

    Button SpearBUT(spearTEX,885.f,300.f,{3.f,3.f});
    Button SwordBUT(swordTEX,760.f,300.f,{3.f,3.f});
    Button ScytheBUT(scytheTEX,1010.f,300.f,{3.f,3.f});

    Button ShurikenBUT(shurikenTEX,760.f,300.f,{3.f,3.f});

    Button primaryBUT(swordTEX,800.f,125.f,{4.f,4.f});
    Button secondaryBUT(shurikenTEX,1000.f,125.f,{4.f,4.f});

    readTiledFile("map_Ground.csv","groundMap");
    readTiledFile("map_Props.csv","propsMap");

    static sf::RectangleShape weaponHitbox;
    weaponHitbox.setOrigin({20.f,20.f});
    weaponHitbox.setSize({40.f,40.f});
    weaponHitbox.setFillColor(sf::Color(255,0,0,125));

    Button SwordGetBut(swordTEX, 250.f, 110.f, {3.f,3.f});
    Button SpearGetBut(spearTEX, 420.f, 110.f, {3.f,3.f});
    Button ScytheGetBut(scytheTEX, 250.f, 250.f, {3.f,3.f});

    while (window.isOpen()) {

        view.setSize(sf::Vector2f({
            (float)gameMode.size.x * 2 / zoomFactor,
            (float)gameMode.size.y * 2 / zoomFactor
        }));


        while (std::optional<sf::Event> event = window.pollEvent()) {


            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            sf::Vector2f inputGuiPos;

            if (auto* touchBegan = event->getIf<sf::Event::TouchBegan>()) {
                inputGuiPos = window.mapPixelToCoords(touchBegan->position, guiView);
            }
            else if (auto* touchEnded = event->getIf<sf::Event::TouchEnded>()) {
                inputGuiPos = window.mapPixelToCoords(touchEnded->position, guiView);
            }
            else {
                inputGuiPos = window.mapPixelToCoords(sf::Mouse::getPosition(window), guiView);
            }

            aUP.handleEvent(*event, inputGuiPos);
            aDOWN.handleEvent(*event, inputGuiPos);
            aLEFT.handleEvent(*event, inputGuiPos);
            aRIGHT.handleEvent(*event, inputGuiPos);

            invBUT.handleEvent(*event, inputGuiPos);

            ExitBUT.handleEvent(*event, inputGuiPos);

            ShurikenBUT.handleEvent(*event, inputGuiPos);

            SpearBUT.handleEvent(*event, inputGuiPos);
            SwordBUT.handleEvent(*event, inputGuiPos);
            ScytheBUT.handleEvent(*event, inputGuiPos);

            primaryBUT.handleEvent(*event, inputGuiPos);
            secondaryBUT.handleEvent(*event, inputGuiPos);

            SwordGetBut.handleEvent(*event, inputGuiPos);
            SpearGetBut.handleEvent(*event, inputGuiPos);
            ScytheGetBut.handleEvent(*event, inputGuiPos);

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
            }
            if (const auto* resized = event->getIf<sf::Event::Resized>()) {


                 view.setSize(sf::Vector2f({
                    (float)resized->size.x / zoomFactor,
                    (float)resized->size.y / zoomFactor
                 }));
            }


            meleeActivation(event, equippedWeapon, equippedSpear, equippedSword, equippedScythe, attackClock, window, guiView, player, equippedFists);
            secondaryActivation(event, window, view, shuriken, equippedWeapon, equippedShuriken);

            std::optional<sf::Event> noEvent = std::nullopt;
        }

        float dt = deltaClock.restart().asSeconds();

        if(dt>0.1f) { dt=0.1f; }

        for(int i = 0; i<melees.size(); i++) {
            if(melees[i].dura<=0 && melees[i].selected) melees[i].selected=false;
        }


        if(guiState==guiStateMachine::None) { guiStateText.setString(" "); }
        else if(guiState==guiStateMachine::Equipment) { guiStateText.setString("Equipment"); }
        else if(guiState==guiStateMachine::Settings) { guiStateText.setString("Settings"); }

        if(settingsState==settingsStateMachine::None) { settingsStateText.setString(" "); }

        //MOVEMENT
        movementSystem(wasMoving,vy,vx,ACCELERATION,menuClock,rolling,player,playerTEX,isMoving, rollVAdd, dt, s, maxp, minp, inWater);


        if (isFlying) {
            shuriken.move(velocity);
            shuriken.rotate(sf::degrees(12.f));

            sf::Vector2f playerPos = player.getPosition();
            sf::Vector2f shurikenPos = shuriken.getPosition();
            float distanța = std::hypot(shurikenPos.x - playerPos.x, shurikenPos.y - playerPos.y);

            if (distanța > 600.f) {
                isFlying = false;
            }
        }

        if(playerHP==3) { healthBar.setTexture(healthBarTEX100); }
        if(playerHP==2) { healthBar.setTexture(healthBarTEX66); }
        if(playerHP==1) { healthBar.setTexture(healthBarTEX33); }
        if(playerHP==0) { healthBar.setTexture(healthBarTEX0); }

        if(ShurikenBUT.isClicked() && sSel) { currentWeapon=VisWeapon::Shuriken; secondaryBUT.m_sprite.setTexture(shurikenTEX); throwables[0].selected=true; }

        if(SpearBUT.isClicked() && pSel) {
            currentWeapon=VisWeapon::Spear;
            primaryBUT.m_sprite.setTexture(spearTEX);
            melees[0].selected=true;
            for(int i=0; i<melees.size(); i++) {
                if(melees[i].selected && melees[i].name!="Spear") {
                    melees[i].selected=false;
                }
            }
        }
        if(SwordBUT.isClicked() && pSel) {
            currentWeapon=VisWeapon::Sword;
            primaryBUT.m_sprite.setTexture(swordTEX);
            melees[1].selected=true;
            for(int i=0; i<melees.size(); i++) {
                if(melees[i].selected && melees[i].name!="Sword") {
                    melees[i].selected=false;
                }
            }
        }
        if(ScytheBUT.isClicked() && pSel) {
            currentWeapon=VisWeapon::Scythe;
            primaryBUT.m_sprite.setTexture(scytheTEX);
            melees[2].selected=true;
            for(int i=0; i<melees.size(); i++) {
                if(melees[i].selected && melees[i].name!="Scythe") {
                    melees[i].selected=false;
                }
            }
        }

        if(primaryBUT.isClicked()) {
            pSel = !pSel;
        }
        if(secondaryBUT.isClicked()) {
            sSel = !sSel;
        }


        if(SwordGetBut.isClicked()) { melees[1].dura=melees[1].maxDura; }
        if(SpearGetBut.isClicked()) { melees[0].dura=melees[0].maxDura; }
        if(ScytheGetBut.isClicked()) { melees[2].dura=melees[2].maxDura; }





        if(!isAnyPrimarySelected() && !isAnySecondarySelected() ) {
            equippedWeapon.setTexture(equippedFists);
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) && inInv) {
            if (menuClock.getElapsedTime() >= sf::milliseconds(200)) {

                if (guiState == guiStateMachine::Equipment) {
                    guiState = guiStateMachine::Settings;
                }
                else if (guiState == guiStateMachine::Settings) {
                    guiState = guiStateMachine::Equipment;
                }

                menuClock.restart();
            }
        }

        if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ) &&
             (settingsState==settingsStateMachine::Video || settingsState==settingsStateMachine::Sound ) ) {
            if (menuClock.getElapsedTime() >= sf::milliseconds(200)) {

                if (settingsState == settingsStateMachine::Video) {
                    settingsState = settingsStateMachine::Sound;
                    settingsStateText.setString("Sound");
                }
                else if (settingsState == settingsStateMachine::Sound) {
                    settingsState = settingsStateMachine::Video;
                    settingsStateText.setString("Video");
                }

                menuClock.restart();
            }
        }


        if(invBUT.isClicked()) { inInv=true; guiState=guiStateMachine::Equipment; }
        if(ExitBUT.isClicked()) { inInv=false; guiState=guiStateMachine::None; }

        // MOVEMENT

        vx *= FRICTION;
        vy *= FRICTION;

        float nextX = px + vx;
        float nextY = py + vy;

        int tileX = std::clamp((int)nextX, 0, N - 1);
        int tileY = std::clamp((int)nextY, 0, N - 1);


        // COLLISIONS
        if(groundMap[tileY][tileX] == WALL1 ||
           groundMap[tileY][tileX] == WALL2t2 ||
           groundMap[tileY][tileX] == WALL2 ||
           groundMap[tileY][tileX] == WALL3 ||
           groundMap[tileY][tileX] == SPIKES ||
           groundMap[tileY][tileX] == SHADEDGRASS1 ||
           groundMap[tileY][tileX] == SHADEDGRASS2 ||
           groundMap[tileY][tileX] == SHADEDGRASS3 ||
           groundMap[tileY][tileX] == SHADEDGRASS4 ||
           groundMap[tileY][tileX] == SHADEDGRASS5 ||
           groundMap[tileY][tileX] == SHADEDGRASS6 ||
           groundMap[tileY][tileX] == SHADEDGRASS7 ||
           groundMap[tileY][tileX] == SHADEDGRASS8 ||
           groundMap[tileY][tileX] == SHADEDGRASS9 ||
           groundMap[tileY][tileX] == SHADEDGRASS10 ||
           groundMap[tileY][tileX] == SHADEDGRASS11 ||
           groundMap[tileY][tileX] == SHADEDGRASS12 ||
           groundMap[tileY][tileX] == SHADEDGRASS13 ||
           groundMap[tileY][tileX] == SHADEDGRASS14 ||
           groundMap[tileY][tileX] == SHADEDGRASS15 ||
           groundMap[tileY][tileX] == SHADEDGRASS16 ||
           groundMap[tileY][tileX] == SHADEDGRASS17 ||
           groundMap[tileY][tileX] == SHADEDGRASS18 ||
           groundMap[tileY][tileX] == SHADEDGRASS19 ||
           groundMap[tileY][tileX] == SHADEDGRASS20 ||
           groundMap[tileY][tileX] == SHADEDGRASS21 ||
           groundMap[tileY][tileX] == SHADEDGRASS22 ||
           groundMap[tileY][tileX] == SHADEDGRASS23 ||
           groundMap[tileY][tileX] == SHADEDGRASS24 ||
           groundMap[tileY][tileX] == SHADEDGRASS25 ||

           propsMap[tileY][tileX] == BUSH ||
           propsMap[tileY][tileX] == BARREL ||
           propsMap[tileY][tileX] == DUMMY
          ) {
            vx = 0.0f;
            vy = 0.0f;
        } else {
            px = nextX;
            py = nextY;
        }

        if(groundMap[scInt(py)][scInt(px)]==WATER  || groundMap[scInt(py)][scInt(px)]==WATER1 ||
            groundMap[scInt(py)][scInt(px)]==WATER2 || groundMap[scInt(py)][scInt(px)]==WATER3 ||
            groundMap[scInt(py)][scInt(px)]==WATER4  || groundMap[scInt(py)][scInt(px)]==WATER5 ||
            groundMap[scInt(py)][scInt(px)]==WATER6 || groundMap[scInt(py)][scInt(px)]==WATER7 ||
            groundMap[scInt(py)][scInt(px)]==WATER8) { inWater=true; FRICTION=0.65; }
        else { inWater=false; FRICTION=0.77;  }


        if (px < 0.0f) { px = 0.0f; vx = 0.0f; }
        if (px > (float)N - 1.0f) { px = (float)N - 1.0f; vx = 0.0f; }
        if (py < 0.0f) { py = 0.0f; vy = 0.0f; }
        if (py > (float)N - 1.0f) { py = (float)N - 1.0f; vy = 0.0f; }


        player.setPosition(sf::Vector2f({px * 40.0f, py * 40.0f}));

        weaponHitbox.setPosition(equippedWeapon.getPosition());


        view.setCenter(player.getPosition());
        window.setView(view);


        // RENDER

        groundRender(window, groundMap, t, dt, view);
        propsRender(window, propsMap, view, t, weaponHitbox, isAttacking, dt, shuriken, guiView);

        if(animations) {
            Water0a.play(t.Water,dt);
            Water1a.play(t.Water1,dt);
            Water2a.play(t.Water2,dt);
            Water3a.play(t.Water3,dt);
            Water4a.play(t.Water4,dt);
            Water5a.play(t.Water5,dt);
            Water6a.play(t.Water6,dt);
            Water7a.play(t.Water7,dt);
            Water8a.play(t.Water8,dt);
            bushAnim.play(t.Bush,dt);
        }
        bsIdle.play(t.Blacksmith,dt);

        window.setView(view);

        window.draw(player);

        window.draw(equippedWeapon);
        //window.draw(weaponHitbox);

        if (isFlying && throwables[0].selected) {
            window.draw(shuriken);
        }

        window.setView(guiView);

        blacksmithDetection(px,py,propsMap,window,f,SwordGetBut,SpearGetBut,ScytheGetBut);

        window.draw(healthBar);

        RenderGUI(window, inInv, currentWeapon, guiState, settingsState,
                  zoomFactor, selWeaponName, selWeaponCount, selWeaponDamage, throwables,
                  animations, melees, inventoryBACKGROUND, guiTOP, guiStateText,
                  settingsStateText, primaryBUT, secondaryBUT, ExitBUT, pSel,
                  sSel, Arrow, SwordBUT, SpearBUT, ScytheBUT, ShurikenBUT, invBUT);

        window.setView(view);

        window.display();

    }

}
