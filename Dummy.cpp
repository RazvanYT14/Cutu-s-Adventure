#include "Dummy.hpp"
#include "data.hpp"

void getAttacked(sf::Sprite& dummy, sf::RectangleShape& weaponHitbox, bool& isAttacking, sf::Sprite& shuriken) {
    sf::FloatRect rect1 = weaponHitbox.getGlobalBounds();
    sf::FloatRect rect2 = dummy.getGlobalBounds();
    sf::FloatRect rect3 = shuriken.getGlobalBounds();

    static bool canHitWithWeapon = true;

    bool isHitByWeapon = rect1.findIntersection(rect2).has_value() && isAttacking;
    bool isHitByShuriken = rect3.findIntersection(rect2).has_value();

    if (isHitByWeapon || isHitByShuriken) {
        dummy.setColor(sf::Color(220, 20, 60, 200));

        if (isHitByWeapon && canHitWithWeapon) {
            float randomPitch = (minp + (rand() % (maxp - minp + 1))) / 100.0f;
            s.hit.setPitch(randomPitch);
            s.hit.play();
            canHitWithWeapon = false;
            for(int i = 0; i<melees.size(); i++) {
                if(melees[i].selected) { melees[i].dura--; }
            }
        }

        if (isHitByShuriken) {
            float randomPitch = (minp + (rand() % (maxp - minp + 1))) / 100.0f;
            s.hit.setPitch(randomPitch);
            s.hit.play();

            shuriken.setPosition({-1000.0f, -1000.0f});
        }
    }
    else {
        dummy.setColor(sf::Color::White);
    }

    if (!isAttacking) {
        canHitWithWeapon = true;
    }
}



