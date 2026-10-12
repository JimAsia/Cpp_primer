#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

struct Person
{
    Person(std::string s1, std::string s2);
    std::string name;
    std::string adress;
    std::string getName() const;
    std::string getAdress() const;
};
// 7.6
std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, Person &);

#endif
