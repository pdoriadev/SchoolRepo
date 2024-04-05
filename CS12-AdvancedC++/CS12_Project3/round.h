#ifndef ROUND_H
#define ROUND_H


#include <string>
#include <cassert>

void roundToLeastSignificantOrHundredth(std::string* str)
{
    size_t s = str->length();
    assert(("Passed in empty string", s > 0 ));
    size_t posPeriod = str->find('.');
    size_t pos = str->find_last_not_of('0') + 1;
    if (pos != std::string::npos) {
        if (pos - posPeriod > 2) {
            str->erase(pos, str->length() - pos);
        }
        else {
            str->erase(posPeriod + 3, str->length() - posPeriod + 3);
        }
    }
}

#endif // ROUND_H
