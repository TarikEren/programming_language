#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "Global.h"
#include "Token.h"

class ASTToken {
    // Starting and ending positions
    Position start{}, end{};
};

class Parser {

    // Vector for all tokens to parse
    std::vector<Token> Tokens{};
    
    // Output tokens
    std::vector<ASTToken> OutputTokens{};

    // Index for the loop
    int index{};

    // Current token
    Token current{};

    // Peek the token which is "steps" amount of steps forward in the iteration
    Token Peek(int steps);

public:
    // Parser constructor
    explicit Parser(std::vector<Token> newTokens) {
        this->Tokens = std::move(newTokens);
        this->index = 0;
        this->current = this->Tokens[this->index];
    }

    // Parse the tokens
    void ParseTokens();
};

#endif
