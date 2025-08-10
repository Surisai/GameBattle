#include <iostream>
#include "characterTpl.h"

using namespace seneca;

int main() {
    std::cout << "===== Testing CharacterTpl<int> =====" << std::endl;
    CharacterTpl<int> warrior("Thor", 100);  // Max health 100

    warrior.takeDamage(30);  // Expected: Thor took 30 damage, 70 health remaining.
    warrior.takeDamage(50);  // Expected: Thor took 50 damage, 20 health remaining.
    warrior.takeDamage(20);  // Expected: Thor has been defeated!

    std::cout << "===== Testing CharacterTpl<double> =====" << std::endl;
    CharacterTpl<double> mage("Merlin", 75.5);  // Max health 75.5

    mage.takeDamage(25.5);  // Expected: Merlin took 25.5 damage, 50 health remaining.
    mage.takeDamage(50);    // Expected: Merlin has been defeated!

    std::cout << "===== Health Manipulation Tests =====" << std::endl;
    warrior.setHealth(100);
    std::cout << warrior.getName() << " reset to " << warrior.getHealth() << " health." << std::endl;
    warrior.setHealthMax(200);
    std::cout << warrior.getName() << " max health is now " << warrior.getHealthMax() << "." << std::endl;

    return 0;
}
