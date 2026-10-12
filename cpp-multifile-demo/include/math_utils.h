#pragma once

#include <vector>

namespace demo {

// 两数相加
int add(int a, int b);

// 阶乘；n < 0 时抛出 std::invalid_argument
long long factorial(int n);

// 求平均值；空容器返回 0.0
double average(const std::vector<int>& values);

}  // namespace demo
