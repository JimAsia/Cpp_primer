#include "Sales_data.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

// 7.6

int main()
{

    // 1. 定义一个 Sales_data 对象 total，用于保存当前正在合并计算的销售记录总和。
    Sales_data total; 

    // 2. 尝试读取第一笔交易数据。如果读取成功（即有数据输入），则进入 if 块。
    if (read(cin, total)) { 
                
        // 3. 定义一个 Sales_data 对象 trans，用于读取下一条交易数据。
        Sales_data trans; 
        
        // 4. 循环读取接下来的每一条交易数据。
        while(read(cin, trans)) { 
            
            // 5. 检查当前读取的这条交易 (trans) 的 ISBN 是否和正在累加的总和 (total) 的 ISBN 相同。
            if (total.isbn() == trans.isbn())  
                
                // 6. 如果 ISBN 相同，说明是同一种书，将这条交易的数据合并（累加）到 total 中。
                total.combine(trans);      
            
            else {
                // 7. 如果 ISBN 不同，说明是新的一本书了。
                
                // 8. 先把前一种书累加好的总和 total 输出到屏幕。
                print(cout, total) << endl;   
                
                // 9. 然后，把 total 重置为当前这本新书的数据，开始新的一轮累加。
                total = trans;            
            }
        }
        
        // 10. 循环结束后，别忘了输出最后一种书的累加总和。
        print(cout, total) << endl;             
        
    } else {
        // 11. 如果一开始就没有读到任何数据，向错误流输出提示信息。
        cerr << "No data?!" << endl;   
    }
}