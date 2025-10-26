#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

std::map<std::string, std::string> parse_headers(const std::string &raw) {
    std::map<std::string, std::string> headers;
    std::istringstream stream(raw);
    std::string line;
    while (std::getline(stream, line)) {
        auto colon = line.find(':');
        if (colon == std::string::npos) {
            continue;
        }
        std::string key = line.substr(0, colon);
        std::string value = line.substr(colon + 1);
        value.erase(value.begin(), std::find_if(value.begin(), value.end(), [](unsigned char ch) { return !std::isspace(ch); }));
        value.erase(std::find_if(value.rbegin(), value.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), value.end());
        headers[key] = value;
    }
    return headers;
}

int main() {
    std::string raw = "Host: api.example.com\nAuthorization: Bearer token123\nContent-Type: application/json\n";
    auto headers = parse_headers(raw);
    for (const auto &[key, value] : headers) {
        std::cout << key << " => " << value << '\n';
    }
}
