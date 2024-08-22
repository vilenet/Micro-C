#pragma once
#include <string>
#include <vector>

class InputProcessor {
public:
    void run();

private:
    std::vector<std::string> codeLines;

    void processInput();
    void executeCode(const std::string& code);
};
