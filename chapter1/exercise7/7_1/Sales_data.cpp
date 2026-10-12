#include "Sales_data.h"


std::string Sales_data::isbn()
{
    return bookNo;
}

std::istream &read(std::istream &in, Sales_data &s)
{
    in >> s.bookNo;
    return in;
}

std::ostream &print(std::ostream &os, Sales_data &s)
{
    os << "ISBN: ";
    os << s.bookNo;
    std::cout << std::endl;
    os << "Units_sold: ";
    os << s.units_sold;
    return os;
}

unsigned add(Sales_data &s1, Sales_data &s2)
{
    return s1.units_sold + s2.units_sold;
}

Sales_data Sales_data::combine(Sales_data &s)
{
    this->units_sold += s.units_sold;
    return *this;
}