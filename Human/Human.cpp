#include "Human.h"
#include <iostream>

Human::Human()
    : age(0)
    , name()
{
}

Human::Human(int age, std::string name)
    : age(age)
    , name(name)
{
}

Human::~Human()
{
    std::cout << "I'm dying!" << std::endl;
}

Human::Human(const Human& other)
    : age(other.age)
    , name(other.name)
{
}

Human& Human::operator=(Human rhs)
{
    swap(*this, rhs);
    return *this;
}

void swap(Human& lhs, Human& rhs)
{
    using std::swap;
    swap(lhs.age, rhs.age);
    swap(lhs.name, rhs.name);
}

std::ostream& operator<<(std::ostream& os, const Human& h)
{
    return os << "Name: " << h.name << '\n'
              << "Age: "  << h.age << '\n';
}
