#include "person.h"

Person::Person(std::string s1 = "noName", std::string s2 = "noAdress"): name(s1), adress(s2)
{

}

std::string Person::getName() const
{
    return name;
}

std::string Person::getAdress() const
{
    return adress;
}