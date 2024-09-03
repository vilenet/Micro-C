#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <unordered_map>
#include "token.h"

class CLexer {
private:
    std::string m_strSource;
    std::vector<SToken> m_vecTokens;
    size_t m_szStart = 0;
    size_t m_szCurrent = 0;
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

public:
    explicit CLexer(const std::string& source);
    std::vector<SToken> tokenize();

};


#endif // LEXER_H
