/*Assignment 2
name: Preeya Surisai
StudentID: 180121238
Date: 16/02/2025
**************************
I declare that this submission is the result of my own work and I only copied the code 
that my professor provided to complete my assignments. This submitted piece of work 
has not been shared with any other student or 3rd party content provider.
*/

#ifndef CHARACTER_TPL_H
#define CHARACTER_TPL_H

#include <iostream>
#include "character.h"

namespace seneca {

	template<typename T>
	class CharacterTpl : public Character {
		int m_healthMax{};
		T m_health{};

	public:
		CharacterTpl(const std::string& name, int health)
			: Character(name.c_str()), 
			m_healthMax(health) {
			m_health = static_cast<int>(health);
		}

		void takeDamage(int dmg) override {
			m_health -= dmg;
			if (static_cast<int>(m_health) <= 0) {
				m_health = 0;
				std::cout << "    " << this->getName() << " has been defeated!" << std::endl;
			}
			else {
				std::cout << "    " << this->getName() << " took " << dmg << " damage, "
					<< static_cast<int>(m_health) << " health remaining."
					<< std::endl;
			}
		}

		int getHealth() const override {
			return static_cast<int>(m_health);
		}

		int getHealthMax() const override {
			return m_healthMax;
		}

		void setHealth(int health) override {
			m_health = health;
		}

		void setHealthMax(int health) override {
			m_healthMax = health;
			m_health = health;
		}
	};
}

#endif