#ifndef SALES_DATA_H_
#define SALES_DATA_H_

#include <string>
#include <iostream>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 1;  // 默认每笔交易数据只卖出1本，如要修改可以设置函数进行修改
    std::string isbn();
    Sales_data combine(Sales_data &);
    
};
unsigned add(Sales_data &, Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, Sales_data &);


#endif