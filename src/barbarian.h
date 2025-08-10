/*Assignment 2
name: Preeya Surisai
StudentID: 180121238
Date: 16/02/2025
**************************
I declare that this submission is the result of my own work and I only copied the code 
that my professor provided to complete my assignments. This submitted piece of work 
has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include <iostream>
#include "characterTpl.h"
#include "abilities.h" 

namespace seneca {

	template <typename T, typename Ability_t, typename Weapon_t>
	class Barbarian : public CharacterTpl<T> {
		int m_baseAttack{};
		int m_baseDefense{};
		Ability_t m_ability{};
		Weapon_t m_weapon[2]{};

	public:
		Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense,
			Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
			: CharacterTpl<T>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense) {
			m_weapon[0] = primaryWeapon;
			m_weapon[1] = secondaryWeapon;
		}

		Barbarian(const Barbarian& other)
			: CharacterTpl<T>(other),
			m_baseAttack(other.m_baseAttack),
			m_baseDefense(other.m_baseDefense),
			m_ability(other.m_ability), 
			m_weapon{ other.m_weapon[0], other.m_weapon[1] } {
		}

		int getAttackAmnt() const {
			return static_cast<int>(m_baseAttack + m_weapon[0].m_damage / 2 + m_weapon[1].m_damage / 2);
		}

		int getDefenseAmnt() const {
			return m_baseDefense;
		}

		Character* clone() const {
			return new Barbarian<T, Ability_t, Weapon_t>(*this);
		}

		void attack(Character* enemy) {
			std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
			m_ability.useAbility(this);

			int dmg = getAttackAmnt();

			m_ability.transformDamageDealt(dmg);
			std::cout << "    Barbarian deals " << dmg << " melee damage!" << std::endl;
			enemy->takeDamage(dmg);
		}

		void takeDamage(int dmg) override {
			std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
			std::cout << "    Barbarian has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
			
            dmg -= getDefenseAmnt();
			
            if (dmg < 0) dmg = 0;
			m_ability.transformDamageReceived(dmg);
			CharacterTpl<T>::takeDamage(dmg);
		}
	};
}

#endif