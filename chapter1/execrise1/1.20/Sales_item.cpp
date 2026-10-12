#include "Sales_item.h"
Sales_item::Sales_item(string book_name, double book_price, int num): name(book_name), price(book_price), number(num), sum_price(num * book_price){
    aver_price = (num != 0) ? (sum_price / num) : 0;
}

string Sales_item::isbn() {
    return name;
}
Sales_item operator+(const Sales_item& s, const Sales_item& b) {
    Sales_item c = s;
    c.number = s.number + b.number;
    c.sum_price = s.sum_price + b.sum_price;
    // 别忘了更新均价
    c.aver_price = (c.number != 0) ? (c.sum_price / c.number) : 0;
    return c;
}

Sales_item Sales_item::operator=(const Sales_item& s) {
    if (this != &s) {
        this->aver_price = s.aver_price;
        this->name = s.name;
        this->number = s.number;
        this->sum_price = s.sum_price;
        this->price = s.price;
    }

    return *this;
}

Sales_item Sales_item::operator+=(const Sales_item& s) {
    this->number += s.number;
    this->sum_price += s.sum_price;
    // 别忘了更新均价
    this->aver_price = (this->number != 0) ? (this->sum_price / this->number) : 0;
    return *this;
}


ostream& operator<<(ostream& out, const Sales_item& s) {
    out << s.name << " " << s.number  << " " << s.sum_price << " " << s.aver_price;
    return out;
}
istream& operator>>(istream& in, Sales_item& s) {
    in >> s.name >> s.number >> s.price;
     // 输入后也应更新总价和均价
    s.sum_price = s.number * s.price;
    s.aver_price = (s.number != 0) ? (s.sum_price / s.number) : 0;
    return in;
}