#ifndef TOKEN_H
#define TOKEN_H
#include <string>

#include "Global.h"

enum TokenType {
    // ===== KEYWORDS =====
    INT,
    CHAR,
    STRING,
    FLOAT,
    IF,
    ELSE,
    FOR,
    WHILE,
    RETURN,
    STRUCT,
    UNION,
    CLASS,
    TYPE,
    VOID,
    BREAK,
    CONTINUE,
    TRUE,
    FALSE,

    // ===== LITERALS =====
    L_INT,
    L_CHAR,
    L_STRING,
    L_NULL,

    // ===== ARITHMETIC =====
    PLUS,
    MINUS,
    STAR,
    SLASH,
    MODULO,
    INCREMENT,
    DECREMENT,
    EQUAL,
    L_ANGLE,
    R_ANGLE,
    ADD_EQUAL,
    MIN_EQUAL,
    MUL_EQUAL,
    DIV_EQUAL,

    // ===== LOGIC =====
    IS,
    NOT,
    GEQ,
    LEQ,
    AND,
    OR,

    // ===== PUNCTUATION =====
    BANG,
    PIPE,
    AMP,
    SEMI,
    COLON,
    COMMA,
    DOT,
    HASH,
    LPAREN,
    RPAREN,
    LBRACK,
    RBRACK,
    LCURLY,
    RCURLY,

    // ===== OTHER =====
    IDENTIFIER,     // Generic identifier
    EOF_TOKEN       // End of file
};

struct Token {
    TokenType type;
    std::string lexeme;
    Position pos;
    [[nodiscard]] std::string TokenToString() const;
};

#endif
