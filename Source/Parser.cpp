#include "../Header/Parser.h"

#include <iostream>

Token Parser::Peek(const int steps) {
    if (this->index + steps >= this->Tokens.size()) {
        return {TokenType::EOF_TOKEN, " ", 0, 0};
    }
    return this->Tokens[this->index + steps];
}

void Parser::ParseTokens() {
    // TODO: Parse the tokens vector and populate the AST tokens vector
}
