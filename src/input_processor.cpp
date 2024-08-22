#include "input_processor.h"
#include <iostream>
#include <sstream>

// TODO: includes для дальнейшей реализации
// #include "lexer.h"
// #include "parser.h"
// #include "interpreter.h"

void InputProcessor::run() {
    std::cout << "Micro-C Interpreter. Type your C code below. Type 'run' to execute.\n";
    processInput();

    std::ostringstream codeStream;
    for (const std::string& codeLine : codeLines) {
        codeStream << codeLine << "\n";
    }
    std::string code = codeStream.str();

    executeCode(code);
}

void InputProcessor::processInput() {
    std::string line;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);

        if (line == "run") {
            break;
        }

        codeLines.push_back(line);
    }
}

void InputProcessor::executeCode(const std::string& code) {
    //TODO: Закомментированный код для дальнейшей реализации
    /*
    try {
        Lexer lexer(code);
        std::vector<Token> tokens = lexer.tokenize();

        Parser parser(tokens);
        ASTNode* root = parser.parse();

        Interpreter interpreter(root);
        interpreter.execute();

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    */

    // Пока просто выводим код, который был введен
    std::cout << "Executing code:\n" << code << std::endl;
}
