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

std::istream &read(std::istream &in, Person &p)
{
    in >> p.name >> p.adress;
    return in;
}

std::ostream &print(std::ostream &out, Person &p)
{
    out << "Name: " << p.getName() << std::endl;
    out << "Address: " << p.getAdress() << std::endl;
    return out;
}