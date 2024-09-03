#include "token.h"

SToken::SToken(ETokenType type, const std::string& value) 
    : m_eType(type)
    , m_strValue(value) 
{}

std::string tokenTypeToStr(ETokenType type)
{
    switch (type) {
        // Identifiers:
        case IDENTIFIER: return "IDENTIFIER";

        //SpecialSymbols:
        case LEFT_PAREN:  return "LEFT_PAREN";
        case RIGHT_PAREN: return "RIGHT_PAREN";
        case LEFT_BRACE:  return "LEFT_BRACE";
        case RIGHT_BRACE: return "RIGHT_BRACE";
        case COMMA:       return "COMMA";
        case SEMICOLON:   return "SEMICOLON";

        // Operators:
        case MINUS:  return "MINUS";
        case PLUS:   return "PLUS";
        case ASSIGN: return "ASSIGN";

        //Literals:
        case NUMBER: return "NUMBER";
        case STRING: return "STRING";

        // Keywords:
        case INT:    return "INT";
        case CHAR:   return "CHAR";
        case BOOL:   return "BOOL";
        case RETURN: return "RETURN";

        default: return "UNKNOWN";
    }
}
