#include "lexer.h"
#include <cctype>
#include <iostream>

CLexer::CLexer(const std::string& strSource) : m_strSource(strSource) {
    KeyWords = {
        {"int",    ETokenType::INT},
        {"char",   ETokenType::CHAR},
        {"bool",   ETokenType::BOOL},
        {"return", ETokenType::RETURN}
    };
}

std::vector<SToken> CLexer::tokenize() {
    while (m_szCurrent < m_strSource.length()) {
        m_szStart = m_szCurrent;
        scanToken();
    }
    return m_vecTokens;
}

void CLexer::addToken(ETokenType type, const std::string& value) {
    m_vecTokens.push_back(SToken(type, value));
}

void CLexer::scanToken() {
    char c = advance();
    switch (c) {
    case '(': addToken(LEFT_PAREN, "("); break;
    case ')': addToken(RIGHT_PAREN, ")"); break;
    case '{': addToken(LEFT_BRACE, "{"); break;
    case '}': addToken(RIGHT_BRACE, "}"); break;
    case ',': addToken(COMMA, ","); break;
    case ';': addToken(SEMICOLON, ";"); break;
    case '+': addToken(PLUS, "+"); break;
    case '-': addToken(MINUS, "-"); break;
    case '=': addToken(ASSIGN, "="); break;
    case '\"': string(); break;
    default:
        if (isalpha(c) || c == '_') {
            identifier();
        } else if (isdigit(c)) {
            number();
        } else if (isspace(c)) {
            // Skip whitespace
        } else {
            std::cerr << "Unexpected character: " << c << std::endl;
        }
        break;
    }
}

char CLexer::advance() {
    return m_strSource[m_szCurrent++];
}

void CLexer::identifier() {
    while (isalnum(peek()) || peek() == '_') advance();
    std::string text = m_strSource.substr(m_szStart, m_szCurrent - m_szStart);
    addToken(keyword(text), text);
}

char CLexer::peek() {
    if (m_szCurrent >= m_strSource.length()) return '\0';
    return m_strSource[m_szCurrent];
}

char CLexer::peekNext() {
    if (m_szCurrent + 1 >= m_strSource.length()) return '\0';
    return m_strSource[m_szCurrent + 1];
}

void CLexer::number() {
    while (isdigit(peek())) advance();
    addToken(NUMBER, m_strSource.substr(m_szStart, m_szCurrent - m_szStart));
}

void CLexer::string() {
    while (peek() != '\"' && m_szCurrent < m_strSource.length()) {
        advance();
    }
    if (m_szCurrent >= m_strSource.length()) {
        std::cerr << "Unterminated string." << std::endl;
        return;
    }
    advance(); // Consume the closing quote
    addToken(STRING, m_strSource.substr(m_szStart + 1, m_szCurrent - m_szStart - 2));
}

ETokenType CLexer::keyword(const std::string& text) {
    if (KeyWords.find(text) != KeyWords.end()) {
        return KeyWords[text];
    }
    return IDENTIFIER;
}