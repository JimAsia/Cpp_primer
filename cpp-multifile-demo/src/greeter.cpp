#include "greeter.h"

namespace demo {

std::string greeting(const std::string& name) {
    return "Hello, " + (name.empty() ? std::string("world") : name) + "!";
}

}  // namespace demo
