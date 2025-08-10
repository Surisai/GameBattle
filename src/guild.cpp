/*Assignment 2
name: Preeya Surisai
StudentID: 180121238
Date: 14/02/2025
**************************
I declare that this submission is the result of my own work and I only copied the code 
that my professor provided to complete my assignments. This submitted piece of work 
has not been shared with any other student or 3rd party content provider.
*/
#include "guild.h"

namespace seneca {

// Constructor with name parameter
Guild::Guild(const char* name) 
    : m_name(name), m_members(new Character*[2]), m_size(2), m_count(0) {}

// Destructor
Guild::~Guild() {
    for (size_t i = 0; i < m_count; ++i) {
        delete m_members[i];
    }
    delete[] m_members;
}

// Copy constructor
Guild::Guild(const Guild& other)
    : m_name(other.m_name), m_size(other.m_size), m_count(other.m_count) {
    m_members = new Character*[m_size];
    for (size_t i = 0; i < m_count; ++i) {
        m_members[i] = other.m_members[i]->clone();
    }
}

// Copy assignment operator
Guild& Guild::operator=(const Guild& other) {
    if (this == &other) return *this;
    
    // Cleanup existing resources
    for (size_t i = 0; i < m_count; ++i) {
        delete m_members[i];
    }
    delete[] m_members;

    // Copy new data
    m_name = other.m_name;
    m_size = other.m_size;
    m_count = other.m_count;

    m_members = new Character*[m_size];
    for (size_t i = 0; i < m_count; ++i) {
        m_members[i] = other.m_members[i]->clone();
    }

    return *this;
}

// Move constructor
Guild::Guild(Guild&& other) noexcept
    : m_name(std::move(other.m_name)), m_members(other.m_members), m_size(other.m_size), m_count(other.m_count) {
    other.m_members = nullptr;
    other.m_size = 0;
    other.m_count = 0;
}

// Move assignment operator
Guild& Guild::operator=(Guild&& other) noexcept {
    if (this == &other) return *this;

    // Cleanup existing resources
    for (size_t i = 0; i < m_count; ++i) {
        delete m_members[i];
    }
    delete[] m_members;

    // Transfer ownership
    m_name = std::move(other.m_name);
    m_members = other.m_members;
    m_size = other.m_size;
    m_count = other.m_count;

    // Nullify the source object
    other.m_members = nullptr;
    other.m_size = 0;
    other.m_count = 0;

    return *this;
}

// Add a new member
void Guild::addMember(Character* c) {
    for (size_t i = 0; i < m_count; ++i) {
        if (m_members[i]->getName() == c->getName()) {
            return; // Member already exists
        }
    }

    if (m_count == m_size) {
        m_size *= 2;
        Character** newMembers = new Character*[m_size];
        for (size_t i = 0; i < m_count; ++i) {
            newMembers[i] = m_members[i];
        }
        delete[] m_members;
        m_members = newMembers;
    }

    m_members[m_count++] = c->clone();
    c->setHealthMax(c->getHealthMax() + 300);
}

// Remove a member
void Guild::removeMember(const std::string& name) {
    for (size_t i = 0; i < m_count; ++i) {
        if (m_members[i]->getName() == name) {
            m_members[i]->setHealthMax(m_members[i]->getHealthMax() - 300);
            delete m_members[i];
            
            for (size_t j = i; j < m_count - 1; ++j) {
                m_members[j] = m_members[j + 1];
            }

            --m_count;
            return;
        }
    }
}

// Access member by index
Character* Guild::operator[](size_t idx) const {
    return (idx < m_count) ? m_members[idx] : nullptr;
}

// Display all members
void Guild::showMembers() const {
    if (m_count == 0) {
        std::cout << "No guild." << std::endl;
        return;
    }
    
    std::cout << "[Guild] " << m_name << std::endl;
    for (size_t i = 0; i < m_count; ++i) {
        std::cout << "    " << i + 1 << ": " << *m_members[i] << std::endl;
    }
}

} // namespace seneca
