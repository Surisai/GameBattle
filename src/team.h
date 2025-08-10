
/*Assignment 2
name: Preeya Surisai
StudentID: 180121238
Date: 16/02/2025
**************************
I declare that this submission is the result of my own work and I only copied the code 
that my professor provided to complete my assignments. This submitted piece of work 
has not been shared with any other student or 3rd party content provider.
*/

#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include "character.h"
#include <iostream>
#include <string>

namespace seneca {

class Team {
    std::string m_name;
    Character** m_members;
    size_t m_size;

public:
    Team() = default;
    ~Team();
    Team(const std::string& name);
    Team(const Team& other);
    Team& operator=(const Team& other);
    Team(Team&& other) noexcept;
    Team& operator=(Team&& other) noexcept;

    // Member functions
    void addMember(const Character* c);
    void removeMember(const std::string& name);
    Character* operator[](size_t idx) const;
    void showMembers() const;
};

} // namespace seneca

#endif // SENECA_TEAM_H
