#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "token.h"

class Lexer {
public:
    explicit Lexer(const std::string& source);
    std::vector<SToken> tokenize();

private:
    std::string source;
    std::vector<SToken> tokens;
    size_t start = 0;
    size_t current = 0;
    size_t line = 1;
    std::unordered_map<std::string, ETokenType> KeyWords;

    void addToken(ETokenType type, const std::string& value);
    void scanToken();
    void number();
    void string();
    void identifier();
    char advance();
    char peek();
    char peekNext();
    ETokenType keyword(const std::string& text);
};


#endif // LEXER_H
