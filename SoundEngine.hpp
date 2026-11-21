#pragma once
#include "data.hpp"

inline int minp = 80;
inline int maxp = 100;

struct soundTypes {
    sf::SoundBuffer playerWalkingBuff{"soundAssets/playerWalking.ogg"};
    sf::Sound playerWalking{playerWalkingBuff};

    sf::SoundBuffer slashBuff{"soundAssets/slash.ogg"};
    sf::Sound slash{slashBuff};

    sf::SoundBuffer jabBuff{"soundAssets/jab.ogg"};
    sf::Sound jab{jabBuff};

    sf::SoundBuffer throwShurikenBuff{"soundAssets/throwShuriken.ogg"};
    sf::Sound throwShuriken{throwShurikenBuff};

    sf::SoundBuffer hitBuff{"soundAssets/hit.ogg"};
    sf::Sound hit{hitBuff};

    sf::SoundBuffer rollBuff{"soundAssets/roll.ogg"};
    sf::Sound roll{rollBuff};

    sf::SoundBuffer swimBuff{"soundAssets/swim.ogg"};
    sf::Sound playerSwimming{swimBuff};
};

inline soundTypes s;
