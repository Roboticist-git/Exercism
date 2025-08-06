#include "raindrops.h"
#include <string>
namespace raindrops {
std::string convert(const int& n) {
    constexpr const char* t3[] = {"", "Pling"};
    constexpr const char* t5[] = {"", "Plang"};
    constexpr const char* t7[] = {"", "Plong"};
    std::string result = std::string(t3[n % 3 == 0]) + std::string(t5[n % 5 == 0]) + std::string(t7[n % 7 == 0]);
    result.empty() && (result = std::to_string(n), false);
    return result;
}
}
