#include "Header/Lexer.h"

// TODO: Implement AST
// TODO: Decide on compiling or transpiling

int main() {
    Lexer lexer(LexerMode::DEBUG, 4);
    lexer.SetText("+ ++ += - -- -=");
    lexer.Tokenize();
}