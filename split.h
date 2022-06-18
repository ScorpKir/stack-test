#pragma once
#include <string>
#include <vector>

inline std::vector<std::wstring> split(const std::wstring &s, const std::wstring &delimeter) {
    size_t startPos = 0, pos = 0;
    std::wstring token;
    std::vector<std::wstring> result;
    while((pos = s.find(delimeter)) != std::string::npos) {
        token = s.substr(startPos, pos);
        result.push_back(token);
        startPos = pos + delimeter.length();
    }
    result.push_back(s.substr(0, s.length() - startPos));
    return result;
}