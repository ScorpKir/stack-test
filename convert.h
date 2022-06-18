#include <string>
#include <codecvt>
#include <locale>

inline std::wstring convertToWstring(std::string str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}