#pragma once
#include <string>
#include <vector>
#include <regex>

inline std::vector<std::wstring> split(const std::wstring &s, const std::wstring &delimeter) {
    size_t start = 0, end = s.find(delimeter);
    std::vector<std::wstring> result;
    while (end != std::string::npos) {
        result.push_back(s.substr(start, end - start));
        start = end + delimeter.length();
        end = s.find(delimeter, start);
    }
    result.push_back(s.substr(start, end));
    return result;
}