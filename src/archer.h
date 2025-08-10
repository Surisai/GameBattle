
/*Assignment 2
name: Preeya Surisai
StudentID: 180121238
Date: 14/02/2025
**************************
I declare that this submission is the result of my own work and I only copied the code 
that my professor provided to complete my assignments. This submitted piece of work 
has not been shared with any other student or 3rd party content provider.
*/

#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H

#include <iostream>
#include "characterTpl.h"
#include "health.h"

namespace seneca {

	template <typename Weapon_t>
	class Archer : public CharacterTpl<seneca::SuperHealth> {
		int m_baseAttack{};
		int m_baseDefense{};
		Weapon_t m_weapon{};

	public:
		Archer(const char* name, int healthMax, 
			int baseAttack, int baseDefense, Weapon_t weapon) 
			: CharacterTpl<seneca::SuperHealth>(name, healthMax),
			m_baseAttack(baseAttack), m_baseDefense(baseDefense), m_weapon(weapon) {}

		Archer(const Archer& other)
			: CharacterTpl<seneca::SuperHealth>(other),
			m_baseAttack(other.m_baseAttack),
			m_baseDefense(other.m_baseDefense),
			m_weapon(other.m_weapon) {}

		int getAttackAmnt() const {
			return static_cast<int>(m_baseAttack * 1.3);
		}

		int getDefenseAmnt() const {
			return static_cast<int>(m_baseDefense * 1.2);
		}

		Character* clone() const {
			return new Archer<Weapon_t>(*this);
		}

		void attack(Character* enemy) {
			std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
			int dmg = getAttackAmnt();
			std::cout << "    Archer deals " << dmg << " ranged damage!" << std::endl;
			enemy->takeDamage(dmg);
		}

		void takeDamage(int dmg) override {
			std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
			std::cout << "    Archer has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
			dmg -= getDefenseAmnt();
			if (dmg < 0) dmg = 0;
			CharacterTpl<seneca::SuperHealth>::takeDamage(dmg);
		}
	};
}

#endif
