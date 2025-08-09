#include "Header/Lexer.h"
#include "Header/Parser.h"

// TODO: Implement AST
// TODO: Decide on compiling or transpiling
// TODO: Implement AST tokens and token types
// TODO: Implement AST token vector and a get function for sending it out of the class
// TODO: Implement the parser

int main() {
    Lexer lexer(LexerMode::DEBUG, 4);
    lexer.SetText("int a = 5;");
    lexer.Tokenize();
    Parser parser(lexer.GetTokens());
    parser.ParseTokens();
}