#include "math_utils.h"

#include <numeric>
#include <stdexcept>

namespace demo {

int add(int a, int b) {
    return a + b;
}

long long factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("factorial: n must not be negative");
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double average(const std::vector<int>& values) {
    if (values.empty()) {
        return 0.0;
    }
    const long long sum = std::accumulate(values.begin(), values.end(), 0LL);
    return static_cast<double>(sum) / static_cast<double>(values.size());
}

}  // namespace demo
