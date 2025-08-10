/*Assignment 2
name: Preeya Surisai
StudentID: 180121238
Date: 14/02/2025
**************************
I declare that this submission is the result of my own work and I only copied the code 
that my professor provided to complete my assignments. This submitted piece of work 
has not been shared with any other student or 3rd party content provider.
*/
#include "team.h"

namespace seneca {

	Team::Team(const std::string& name = "")
		: m_name(name), m_members(nullptr), m_size(0) {}

	Team::~Team() {
		for (size_t i = 0; i < m_size; i++) {
			delete m_members[i];
		}
		delete[] m_members;
		m_members = nullptr;
		m_size = 0;
	}

	Team::Team(const Team& other) {
		*this = other;
	}

	Team& Team::operator=(const Team& other) {
		if (this != &other) {
			for (size_t i = 0; i < m_size; i++) {
				delete m_members[i];
			}
			delete[] m_members;
			m_members = nullptr;

			m_name = other.m_name;
			m_size = other.m_size;

			if (m_size > 0) {
				m_members = new Character * [m_size];
				for (size_t i = 0; i < m_size; i++) {
					m_members[i] = other.m_members[i]->clone();
				}
			}
			else {
				m_members = nullptr;
			}
		}
		return *this;
	}

	Team::Team(Team&& other) noexcept
		: m_name(std::move(other.m_name)), m_members(other.m_members), m_size(other.m_size) {
		other.m_members = nullptr;
		other.m_size = 0;
	}

	Team& Team::operator=(Team&& other) noexcept {
		if (this != &other) {
			for (size_t i = 0; i < m_size; i++) {
				delete m_members[i];
			}
			delete[] m_members;
			m_members = nullptr;

			m_name = std::move(other.m_name);
			m_members = other.m_members;
			m_size = other.m_size;

			other.m_members = nullptr;
			other.m_size = 0;
		}
		return *this;
	}

	void Team::addMember(const Character* c) {
		if (c == nullptr) return;
		for (size_t i = 0; i < m_size; i++) {
			if (m_members[i]->getName() == c->getName()) {
				return;
			}
		}
		Character** temp = new Character * [m_size + 1];
		for (size_t i = 0; i < m_size; i++) {
			temp[i] = m_members[i];
		}
		temp[m_size] = c->clone();
		delete[] m_members;
		m_members = temp;
		temp = nullptr;
		m_size++;
	}

	void Team::removeMember(const std::string& c) {
		size_t i = 0;
		bool found = false;
		Character** temp = new Character * [m_size - 1];

		for (; i < m_size && !found; i++) {
			if (m_members[i]->getName() == c) {
				delete m_members[i];
				m_members[i] = nullptr;
				found = true;
			}
			else temp[i] = m_members[i];
		}
		if (!found) {
			delete[] temp;
			return;
		}
		i--;
		for (; i < m_size - 1; i++) {
			temp[i] = m_members[i + 1];
		}
		delete[] m_members;
		m_members = temp;
		temp = nullptr;
		m_size--;
	}

	Character* Team::operator[](size_t idx) const {
		if (idx < m_size) {
			return m_members[idx];
		}
		return nullptr;
	}

	void Team::showMembers() const {
		if (m_size == 0) {
			std::cout << "No team." << std::endl;
		}
		else {
			std::cout << "[Team] " << m_name << std::endl;
			for (size_t i = 0; i < m_size; ++i) {
				std::cout << "    " << i + 1 << ": " << *m_members[i] << std::endl;
			}
		}
	}
}
 // namespace seneca
