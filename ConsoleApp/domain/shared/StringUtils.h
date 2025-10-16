#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>

using namespace std;

class StringUtils {
public:
    static wstring toUpperCase(const wstring &value);
    static wstring toLowerCase(const wstring &value);
    static wstring leftTrim(const wstring &value);
    static wstring rightTrim(const wstring &value);
    static wstring trim(const wstring &value);
    static bool ensureNotNullOrEmpty(const wstring &value);
    static bool ensureNotNullOrEmpty(const wstring &value, int minLength);
};

#endif //STRINGUTILS_H