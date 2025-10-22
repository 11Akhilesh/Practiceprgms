#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> logs = {
        "[INFO] Scheduler started",
        "[WARN] Cache miss on region=us-east",
        "[ERROR] Failed to persist metrics",
        "[INFO] Shutdown complete"
    };

    std::regex filter(R"(\[(WARN|ERROR)\])");
    for (const auto &line : logs) {
        if (std::regex_search(line, filter)) {
            std::cout << line << '\n';
        }
    }
}
