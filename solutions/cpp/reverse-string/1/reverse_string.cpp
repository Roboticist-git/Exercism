#include "reverse_string.h"
#include <string>

namespace reverse_string {

std::string reverse_string(const std::string& str) {
    std::string result = str;
    int n = result.length();
    for (int i = 0; i < n/2; ++i) {
        std::swap(result[i], result[n-i-1]);
    }
    return result;
}
}  // namespace reverse_string
