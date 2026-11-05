#include "Barrel.hpp"
#include "data.hpp"

void getDestroyed(sf::Sprite& Barrel, sf::RectangleShape& weaponHitbox, bool& isAttacking, sf::Sprite& shuriken, int&rx, int&ry) {
    sf::FloatRect rect1 = weaponHitbox.getGlobalBounds();
    sf::FloatRect rect2 = Barrel.getGlobalBounds();
    sf::FloatRect rect3 = shuriken.getGlobalBounds();

    if (rect1.findIntersection(rect2).has_value() && isAttacking) {
        propsMap[ry][rx]=-1;
    }
    else if (rect3.findIntersection(rect2).has_value()) {
        propsMap[ry][rx]=-1;
    }
}
