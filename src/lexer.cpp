#include "lexer.h"
#include <cctype>
#include <iostream>

Lexer::Lexer(const std::string& src) : source(src) {
    KeyWords = {
        {"int",    ETokenType::INT},
        {"char",   ETokenType::CHAR},
        {"bool",   ETokenType::BOOL},
        {"return", ETokenType::RETURN}
    };
}

std::vector<SToken> Lexer::tokenize() {
    while (current < source.length()) {
        start = current;
        scanToken();
    }
    return tokens;
}

void Lexer::addToken(ETokenType type, const std::string& value) {
    tokens.push_back(SToken(type, value));
}

void Lexer::scanToken() {
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

char Lexer::advance() {
    return source[current++];
}

void Lexer::identifier() {
    while (isalnum(peek()) || peek() == '_') advance();
    std::string text = source.substr(start, current - start);
    addToken(keyword(text), text);
}

char Lexer::peek() {
    if (current >= source.length()) return '\0';
    return source[current];
}

char Lexer::peekNext() {
    if (current + 1 >= source.length()) return '\0';
    return source[current + 1];
}

void Lexer::number() {
    while (isdigit(peek())) advance();
    addToken(NUMBER, source.substr(start, current - start));
}

void Lexer::string() {
    while (peek() != '\"' && current < source.length()) {
        advance();
    }
    if (current >= source.length()) {
        std::cerr << "Unterminated string." << std::endl;
        return;
    }
    advance(); // Consume the closing quote
    addToken(STRING, source.substr(start + 1, current - start - 2));
}

ETokenType Lexer::keyword(const std::string& text) {
    if (KeyWords.find(text) != KeyWords.end()) {
        return KeyWords[text];
    }
    return IDENTIFIER;
}