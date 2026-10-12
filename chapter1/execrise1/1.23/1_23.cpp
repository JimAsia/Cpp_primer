#include "Sales_item.h"

int main()
{
    Sales_item curritem, item;
    int temp = 0;
    if (cin >> curritem)
    {
        temp = curritem.Getnumber();
        while (cin >> item) {
            if (curritem.isbn() == item.isbn()) {
                temp += item.Getnumber();
            }
            else {
                cout << curritem.isbn() << " sales " << temp << endl;
                temp = item.Getnumber();
                curritem = item;
            }
        }
        cout << curritem.isbn() << " sales " << temp << endl;
    }
    return 0;
}