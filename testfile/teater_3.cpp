#include <iostream>
#include "barbarian.h"
#include "abilities.h"
#include "weapons.h"

using namespace seneca;

int main() {
    // Create sample weapons
    Sword sword(50);  // A sword with 50 base damage
    Axe axe(40);      // An axe with 40 base damage

    // Create a special ability (e.g., Fireball)
    Fireball fireball;

    // Create Barbarian with weapons and special ability
    Barbarian<int, Fireball, Sword> warrior("Conan", 200, 30, 10, sword, axe);
    
    // Display Barbarian's attack amount
    std::cout << warrior.getName() << "'s attack amount: " << warrior.getAttackAmnt() << std::endl;

    // Create an enemy Barbarian
    Barbarian<int, Fireball, Axe> enemy("Korg", 180, 25, 8, axe, axe);

    // Conan attacks Korg
    warrior.attack(&enemy);

    // Korg attacks back
    enemy.attack(&warrior);

    return 0;
}
