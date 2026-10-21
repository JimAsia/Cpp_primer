#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    size_t last_capacity = v.capacity();
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
        if (v.capacity() != last_capacity) {
            std::cout << "size: " << v.size() 
                      << ", capacity: " << v.capacity() << std::endl;
            last_capacity = v.capacity();
        }
    }
    return 0;
}