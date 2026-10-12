#include <iostream>


int main(int argc, char *argv[]) // *argv[]相当于**argv
{
    std::cout << "参数个数(argc): " << argc << std::endl;
    
    // 遍历 argv，直到遇到空指针（0）
    for (int i = 0; argv[i] != 0; ++i) {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }
    
    return 0;

}