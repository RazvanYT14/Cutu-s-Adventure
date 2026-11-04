#pragma once

#include <fstream>
#include <SFML/Graphics.hpp>

const int N = 25;

inline char groundMap[N][N];
inline char propsMap[N][N];

const char GRASS = 1;
    const char GRASS2 = 2;
    const char SPIKES = 3;
    const char WALL1 = 4;
    const char WALL2 = 5;
    const char WALL2t2 = 5;
    const char WALL3 = 6;
    const char CRAFTINGTABLE = 7;
    const char UPPER_GRASS = 8;
    const char STAIR = 9;
    const char WATER = 10;
    const char WATER1 = 11;
    const char WATER2 = 12;
    const char WATER3 = 13;
    const char WATER4 = 14;
    const char WATER5 = 15;
    const char WATER6 = 16;
    const char WATER7 = 17;
    const char WATER8 = 18;
    const char BRIDGE1 = 19;
    const char SHADEDGRASS1 = 20;
    const char SHADEDGRASS2 = 21;
    const char SHADEDGRASS3 = 22;
    const char SHADEDGRASS4 = 23;
    const char SHADEDGRASS5 = 24;
    const char SHADEDGRASS6 = 25;
    const char SHADEDGRASS7 = 26;
    const char SHADEDGRASS8 = 27;
    const char SHADEDGRASS9 = 28;
    const char SHADEDGRASS10 = 29;
    const char SHADEDGRASS11 = 30;
    const char SHADEDGRASS12 = 31;
    const char SHADEDGRASS13 = 32;
    const char SHADEDGRASS14 = 33;
    const char SHADEDGRASS15 = 34;
    const char SHADEDGRASS16 = 35;
    const char SHADEDGRASS17 = 36;
    const char SHADEDGRASS18 = 37;
    const char SHADEDGRASS19 = 38;
    const char SHADEDGRASS20 = 39;
    const char SHADEDGRASS21 = 40;
    const char BUSH = 41;
    const char SHADEDGRASS22 = 42;
    const char SHADEDGRASS23 = 43;
    const char SHADEDGRASS24 = 44;
    const char SHADEDGRASS25 = 45;
    const char WALL1t2 = 46;
    const char WALL1t3 = 47;
    const char WALL3t2 = 48;
    const char WALL3t3 = 49;
    const char DUMMY = 50;
    const char BARREL = 51;

inline void readTiledFile(const char* filename, std::string layerName) {
    FILE* file = fopen(filename, "r");

    if (!file) {
        return;
    }

    int tileID;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (fscanf(file, "%d", &tileID) == 1) {

                if (layerName == "groundMap") {
                    switch (tileID) {
                        case 0: groundMap[y][x] = GRASS; break;
                        case 1: groundMap[y][x] = GRASS2; break;
                        case 5: groundMap[y][x] = WALL1; break;
                        case 6: groundMap[y][x] = WALL2; break;
                        case 7: groundMap[y][x] = WALL3; break;
                        case 13: groundMap[y][x] = UPPER_GRASS; break;
                        case 15: groundMap[y][x] = SPIKES; break;
                        case 16: groundMap[y][x] = STAIR; break;
                        case 18: groundMap[y][x] = WATER; break;
                        case 19: groundMap[y][x] = WATER1; break;
                        case 20: groundMap[y][x] = WATER2; break;
                        case 21: groundMap[y][x] = WATER3; break;
                        case 22: groundMap[y][x] = WATER4; break;
                        case 23: groundMap[y][x] = WATER5; break;
                        case 24: groundMap[y][x] = WATER6; break;
                        case 25: groundMap[y][x] = WATER7; break;
                        case 26: groundMap[y][x] = WATER8; break;
                        case 34: groundMap[y][x] = BRIDGE1; break;
                        case 35: groundMap[y][x] = SHADEDGRASS1; break;
                        case 36: groundMap[y][x] = SHADEDGRASS2; break;
                        case 37: groundMap[y][x] = SHADEDGRASS3; break;
                        case 38: groundMap[y][x] = SHADEDGRASS4; break;
                        case 39: groundMap[y][x] = SHADEDGRASS5; break;
                        case 40: groundMap[y][x] = SHADEDGRASS6; break;
                        case 41: groundMap[y][x] = SHADEDGRASS7; break;
                        case 42: groundMap[y][x] = SHADEDGRASS8; break;
                        case 43: groundMap[y][x] = SHADEDGRASS9; break;
                        case 44: groundMap[y][x] = SHADEDGRASS10; break;
                        case 45: groundMap[y][x] = SHADEDGRASS11; break;
                        case 46: groundMap[y][x] = SHADEDGRASS12; break;
                        case 47: groundMap[y][x] = SHADEDGRASS13; break;
                        case 48: groundMap[y][x] = SHADEDGRASS14; break;
                        case 49: groundMap[y][x] = SHADEDGRASS16; break;
                        case 50: groundMap[y][x] = SHADEDGRASS15; break;
                        case 51: groundMap[y][x] = SHADEDGRASS17; break;
                        case 52: groundMap[y][x] = SHADEDGRASS18; break;
                        case 53: groundMap[y][x] = SHADEDGRASS19; break;
                        case 54: groundMap[y][x] = SHADEDGRASS20; break;
                        case 55: groundMap[y][x] = SHADEDGRASS21; break;
                        case 62: groundMap[y][x] = WALL1t2; break;
                        case 63: groundMap[y][x] = WALL3t2; break;
                        case 64: groundMap[y][x] = SHADEDGRASS22; break;
                        case 65: groundMap[y][x] = WALL1t3; break;
                        case 66: groundMap[y][x] = WALL3t3; break;
                        case 67: groundMap[y][x] = SHADEDGRASS23; break;
                        case 68: groundMap[y][x] = SHADEDGRASS24; break;
                        case 69: groundMap[y][x] = SHADEDGRASS25; break;
                        default: groundMap[y][x] = GRASS; break;
                    }
                }
                else if (layerName == "propsMap") {
                    switch (tileID) {
                        case 58: propsMap[y][x] = BUSH; break;
                        case 70: propsMap[y][x] = DUMMY; break;
                        case 71: propsMap[y][x] = BARREL; break;
                        case 0:  propsMap[y][x] = 0; break;
                        case -1: propsMap[y][x] = 0; break;
                        default: propsMap[y][x] = 0; break;
                    }
                }

                fscanf(file, "%*[, \n\r]");
            }
            else {
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
}

struct tileTypes {
    // 1. Declarăm texturile (Ordinea contează! Texturile trebuie declarate ÎNAINTEA sprite-urilor)
    sf::Texture grassTEX{"assets/grassTile.png"};
    sf::Texture grassTEX2{"assets/grassTile2.png"};
    sf::Texture stairTEX{"assets/stairTile.png"};
    sf::Texture craftTabTEX{"assets/craftingTable.png"};
    sf::Texture spikesTEX{"assets/spikesTile.png"};
    sf::Texture wall1TEX{"assets/Wall1Tile.png"};
    sf::Texture wall1TEX2{"assets/Wall1Tile2.png"};
    sf::Texture wall1TEX3{"assets/Wall1Tile3.png"};
    sf::Texture wall2TEX{"assets/Wall2Tile.png"};
    sf::Texture wall2TEX2{"assets/Wall2Tile2.png"};
    sf::Texture wall3TEX{"assets/Wall3Tile.png"};
    sf::Texture wall3TEX2{"assets/Wall3Tile2.png"};
    sf::Texture wall3TEX3{"assets/Wall3Tile3.png"};
    sf::Texture waterTEX{"assets/Water.png"};
    sf::Texture bridge1TEX{"assets/Bridge1.png"};
    sf::Texture water1TEX{"assets/Water1.png"};
    sf::Texture water2TEX{"assets/Water2.png"};
    sf::Texture water3TEX{"assets/Water3.png"};
    sf::Texture water4TEX{"assets/Water4.png"};
    sf::Texture water5TEX{"assets/Water5.png"};
    sf::Texture water6TEX{"assets/Water6.png"};
    sf::Texture water7TEX{"assets/Water7.png"};
    sf::Texture water8TEX{"assets/Water8.png"};
    sf::Texture upperGrassTEX{"assets/UpperGrassTile.png"};
    sf::Texture ShadedGrass1TEX{"assets/ShadedGrass1.png"};
    sf::Texture ShadedGrass2TEX{"assets/ShadedGrass2.png"};
    sf::Texture ShadedGrass3TEX{"assets/ShadedGrass3.png"};
    sf::Texture ShadedGrass4TEX{"assets/ShadedGrass4.png"};
    sf::Texture ShadedGrass5TEX{"assets/ShadedGrass5.png"};
    sf::Texture ShadedGrass6TEX{"assets/ShadedGrass6.png"};
    sf::Texture ShadedGrass7TEX{"assets/ShadedGrass7.png"};
    sf::Texture ShadedGrass8TEX{"assets/ShadedGrass8.png"};
    sf::Texture ShadedGrass9TEX{"assets/ShadedGrass9.png"};
    sf::Texture ShadedGrass10TEX{"assets/ShadedGrass10.png"};
    sf::Texture ShadedGrass11TEX{"assets/ShadedGrass11.png"};
    sf::Texture ShadedGrass12TEX{"assets/ShadedGrass12.png"};
    sf::Texture ShadedGrass13TEX{"assets/ShadedGrass13.png"};
    sf::Texture ShadedGrass14TEX{"assets/ShadedGrass14.png"};
    sf::Texture ShadedGrass15TEX{"assets/ShadedGrass15.png"};
    sf::Texture ShadedGrass16TEX{"assets/ShadedGrass16.png"};
    sf::Texture ShadedGrass17TEX{"assets/ShadedGrass17.png"};
    sf::Texture ShadedGrass18TEX{"assets/ShadedGrass18.png"};
    sf::Texture ShadedGrass19TEX{"assets/ShadedGrass19.png"};
    sf::Texture ShadedGrass20TEX{"assets/ShadedGrass20.png"};
    sf::Texture ShadedGrass21TEX{"assets/ShadedGrass21.png"};
    sf::Texture ShadedGrass22TEX{"assets/ShadedGrass22.png"};
    sf::Texture ShadedGrass23TEX{"assets/ShadedGrass23.png"};
    sf::Texture ShadedGrass24TEX{"assets/ShadedGrass24.png"};
    sf::Texture ShadedGrass25TEX{"assets/ShadedGrass25.png"};
    sf::Texture bushTEX{"assets/Bush.png"};
    sf::Texture dummyTEX{"assets/Dummy.png"};
    sf::Texture barrelTEX{"assets/Barrel.png"};

    // 2. În SFML 3, Sprite-urile TREBUIE inițializate direct cu textura lor ca referință lvalue
    sf::Sprite grass{grassTEX};
    sf::Sprite grass2{grassTEX2};
    sf::Sprite stair{stairTEX};
    sf::Sprite craftingTable{craftTabTEX};
    sf::Sprite spikes{spikesTEX};
    sf::Sprite Wall1{wall1TEX};
    sf::Sprite Wall1_2{wall1TEX2};
    sf::Sprite Wall1_3{wall1TEX3};
    sf::Sprite Wall2{wall2TEX};
    sf::Sprite Wall2_2{wall2TEX2};
    sf::Sprite Wall3{wall3TEX};
    sf::Sprite Wall3_2{wall3TEX2};
    sf::Sprite Wall3_3{wall3TEX3};
    sf::Sprite Water{waterTEX};
    sf::Sprite Bridge1{bridge1TEX};
    sf::Sprite Water1{water1TEX};
    sf::Sprite Water2{water2TEX};
    sf::Sprite Water3{water3TEX};
    sf::Sprite Water4{water4TEX};
    sf::Sprite Water5{water5TEX};
    sf::Sprite Water6{water6TEX};
    sf::Sprite Water7{water7TEX};
    sf::Sprite Water8{water8TEX};
    sf::Sprite UpperGrass{upperGrassTEX};
    sf::Sprite ShadedGrass1{ShadedGrass1TEX};
    sf::Sprite ShadedGrass2{ShadedGrass2TEX};
    sf::Sprite ShadedGrass3{ShadedGrass3TEX};
    sf::Sprite ShadedGrass4{ShadedGrass4TEX};
    sf::Sprite ShadedGrass5{ShadedGrass5TEX};
    sf::Sprite ShadedGrass6{ShadedGrass6TEX};
    sf::Sprite ShadedGrass7{ShadedGrass7TEX};
    sf::Sprite ShadedGrass8{ShadedGrass8TEX};
    sf::Sprite ShadedGrass9{ShadedGrass9TEX};
    sf::Sprite ShadedGrass10{ShadedGrass10TEX};
    sf::Sprite ShadedGrass11{ShadedGrass11TEX};
    sf::Sprite ShadedGrass12{ShadedGrass12TEX};
    sf::Sprite ShadedGrass13{ShadedGrass13TEX};
    sf::Sprite ShadedGrass14{ShadedGrass14TEX};
    sf::Sprite ShadedGrass15{ShadedGrass15TEX};
    sf::Sprite ShadedGrass16{ShadedGrass16TEX};
    sf::Sprite ShadedGrass17{ShadedGrass17TEX};
    sf::Sprite ShadedGrass18{ShadedGrass18TEX};
    sf::Sprite ShadedGrass19{ShadedGrass19TEX};
    sf::Sprite ShadedGrass20{ShadedGrass20TEX};
    sf::Sprite ShadedGrass21{ShadedGrass21TEX};
    sf::Sprite ShadedGrass22{ShadedGrass22TEX};
    sf::Sprite ShadedGrass23{ShadedGrass23TEX};
    sf::Sprite ShadedGrass24{ShadedGrass24TEX};
    sf::Sprite ShadedGrass25{ShadedGrass25TEX};
    sf::Sprite Bush{bushTEX};
    sf::Sprite dummy{dummyTEX};
    sf::Sprite Barrel{barrelTEX};
};


