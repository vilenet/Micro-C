#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum ETokenType {
    // Identifiers:
    IDENTIFIER,  // This would cover all identifiers including 'main', 'printf', variable names, etc.

    // Special Symbols:
    LEFT_PAREN,   // (
    RIGHT_PAREN,  // )
    LEFT_BRACE,   // {
    RIGHT_BRACE,  // }
    COMMA,        // ,
    SEMICOLON,    // ;

    // Operators:
    MINUS, 
    PLUS, 
    ASSIGN,

    //Literals:
    NUMBER,
    STRING,

    // Keywords:
    INT, 
    CHAR,
    BOOL,
    RETURN,
    // Add other standard C keywords as needed like 'if', 'for', 'while', 'switch', 'case', etc.

    // Default:
    UNKNOWN // Covering any unrecognized tokens
};

struct SToken {
    ETokenType m_eType;
    std::string m_strValue;

    SToken(ETokenType type, const std::string& value);
};

std::string tokenTypeToStr(ETokenType type);

#endif // TOKEN_H
