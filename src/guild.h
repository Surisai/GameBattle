
/*Assignment 2
name: Preeya Surisai
StudentID: 180121238
Date: 14/02/2025
**************************
I declare that this submission is the result of my own work and I only copied the code 
that my professor provided to complete my assignments. This submitted piece of work 
has not been shared with any other student or 3rd party content provider.
*/


#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H

#include "character.h"
#include <iostream>
#include <string>

namespace seneca {

class Guild {
    std::string m_name;
    Character** m_members;
    size_t m_size;
    size_t m_count;

public:
    // Default constructor
    Guild();
    
    // Constructor
    Guild(const char* name);

    // Rule of 5
    ~Guild();
    Guild(const Guild& other);
    Guild& operator=(const Guild& other);
    Guild(Guild&& other) noexcept;
    Guild& operator=(Guild&& other) noexcept;

    // Member functions
    void addMember(Character* c);
    void removeMember(const std::string& name);
    Character* operator[](size_t idx) const;
    void showMembers() const;
};

} // namespace seneca

#endif // SENECA_GUILD_H
