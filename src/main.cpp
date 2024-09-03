#include <iostream>
#include "lexer.h"

int main() 
{
    std::string source = "int main(){ int var = 10; printf(\"variable var is: %d\", var); }";
    CLexer lexer(source);
    std::vector<SToken> tokens = lexer.tokenize();

    for (const auto& token : tokens) {
        std::cout << tokenTypeToStr(token.m_eType) << " - " << token.m_strValue << std::endl;
    }

    return 0;
}
