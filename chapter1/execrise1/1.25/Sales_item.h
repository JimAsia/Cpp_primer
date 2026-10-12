#ifndef SALES_ITEM_h
#define SALES_ITEM_H

#include <iostream>
#include <string>
using namespace std;
class Sales_item {
private:
    string name;
    double price;
    int number;
    double aver_price;
    double sum_price;
public:
    Sales_item(string book_name= "No name", double book_price = 0, int num = 0);
    string isbn();
    friend Sales_item operator+(const Sales_item& s, const Sales_item& b);
    Sales_item operator=(const Sales_item& s);
    Sales_item operator+=(const Sales_item& s);
    friend ostream& operator<<(ostream& out, const Sales_item& s);
    friend istream& operator>>(istream& in, Sales_item& s);

};


#endif