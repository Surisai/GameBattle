/*Assignment 2
name: Preeya Surisai
StudentID: 180121238
Date: 14/02/2025
**************************
I declare that this submission is the result of my own work and I only copied the code 
that my professor provided to complete my assignments. This submitted piece of work 
has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H

#include "characterTpl.h"
#include "weapons.h"
#include <iostream>

namespace seneca {

template <typename T, typename FirstAbility_t, typename SecondAbility_t>
class Rogue : public CharacterTpl<T> {
    int m_baseAttack;
    int m_baseDefense;
    FirstAbility_t m_firstAbility;
    SecondAbility_t m_secondAbility;
    seneca::Dagger m_weapon;  // Rogue always uses a Dagger

public:
    // Constructor: Initialize all member variables
    Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
        : CharacterTpl<T>(name, healthMax),
          m_baseAttack(baseAttack),
          m_baseDefense(baseDefense),
          m_firstAbility(),  // Ensure ability is initialized
          m_secondAbility(),
          m_weapon() {}  // Ensure dagger is initialized

    // Calculate total attack power
    int getAttackAmnt() const override {
        return m_baseAttack + 2 * static_cast<int>(static_cast<double>(m_weapon));  // Doubles weapon damage

    }
    

    // Returns defense value
    int getDefenseAmnt() const override {
        return m_baseDefense;
    }

    // Clone function for creating copies
    Character* clone() const {
        return new Rogue<T, FirstAbility_t, SecondAbility_t>(*this);
    }


    // Rogue attacks: uses two abilities and a dagger
    void attack(Character* enemy) {
        std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;

        m_firstAbility.useAbility(this);
        m_secondAbility.useAbility(this);

        int dmg = getAttackAmnt();

        m_firstAbility.transformDamageDealt(dmg);
        m_secondAbility.transformDamageDealt(dmg);
        std::cout << "    Rogue deals " << dmg << " melee damage!" << std::endl;
        enemy->takeDamage(dmg);
    }

    // Rogue takes damage: reduces damage using defense and abilities
    void takeDamage(int dmg) override {
        std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
        std::cout << "    Rogue has a defense of " << m_baseDefense << ". Reducing damage received." << std::endl;

        // Reduce damage by base defense
        dmg -= m_baseDefense;
        if (dmg < 0) dmg = 0;

        // Apply abilities to reduce damage further
        m_firstAbility.transformDamageReceived(dmg);
        m_secondAbility.transformDamageReceived(dmg);

        // Apply final damage to health
        CharacterTpl<T>::takeDamage(dmg);
    }
};

} // namespace seneca

#endif // SENECA_ROGUE_H
