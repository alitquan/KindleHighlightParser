#include "kUtil.h"

std::string rmDayFromDate(const std::string& str) {
    const char* current = str.data();
    std::string copy = str;

    while (*current != ' ') {
        current++;
    }

    return copy.erase(0, current - str.data() + 1);
}
