#include "../Header/Lexer.h"
#include <iostream>

void Lexer::Tokenize() {
    while (!this->IsAtEnd()) {
        switch (this->current) {
            case '+':
                this->startCol = this->col;
                if (this->Peek() == '+') {
                    AppendToken(TokenType::INCREMENT, "++");
                    this->StepForward();
                    this->col++;
                } else if (this->Peek() == '=') {
                    AppendToken(TokenType::ADD_EQUAL, "+=");
                    this->StepForward();
                    this->col++;
                } else {
                    AppendToken(TokenType::PLUS, "+");
                }
                break;
            case '-':
                this->startCol = this->col;
                if (this->Peek() == '-') {
                    AppendToken(TokenType::DECREMENT, "--");
                    this->col++;
                    this->StepForward();
                } else if (this->Peek() == '=') {
                    AppendToken(TokenType::MIN_EQUAL, "-=");
                    this->col++;
                    this->StepForward();
                } else {
                    AppendToken(TokenType::MINUS, "-");
                }
            break;
            case '*':
                this->startCol = this->col;
                if (this->Peek() == '=') {
                    AppendToken(TokenType::MUL_EQUAL, "*=");
                    this->col++;
                    this->StepForward();
                } else {
                    AppendToken(TokenType::STAR, "*");
                }
            break;
            case '/':
                this->startCol = this->col;
                if (this->Peek() == '=') {
                    AppendToken(TokenType::DIV_EQUAL, "/=");
                    this->col++;
                    this->StepForward();
                } else if (this->Peek() == '/') {
                    while (this->current != '\n' && !this->IsAtEnd()) {
                        this->StepForward();
                    }
                } else {
                    AppendToken(TokenType::SLASH, "/");
                }
            break;
            case '%':
                this->startCol = this->col;
                AppendToken(TokenType::MODULO, "%");
            break;
            case '=':
                this->startCol = this->col;
                if (this->Peek() == '=') {
                    AppendToken(TokenType::IS, "==");
                    this->col++;
                    this->StepForward();
                } else {
                    AppendToken(TokenType::EQUAL, "=");
                }
            break;
            case '<':
                this->startCol = this->col;
                if (this->Peek() == '=') {
                    AppendToken(TokenType::LEQ, "<=");
                    this->col++;
                    this->StepForward();
                } else {
                    AppendToken(TokenType::L_ANGLE, "<");
                }
            break;
            case '>':
                this->startCol = this->col;
                if (this->Peek() == '=') {
                    AppendToken(TokenType::GEQ, ">=");
                    this->col++;
                    this->StepForward();
                } else {
                    AppendToken(TokenType::R_ANGLE, ">");
                }
            break;
            case '!':
                this->startCol = this->col;
                if (this->Peek() == '=') {
                    AppendToken(TokenType::NOT, "!=");
                    this->col++;
                    this->StepForward();
                } else {
                    AppendToken(TokenType::BANG, "!");
                }
            break;
            case '|':
                this->startCol = this->col;
                if (this->Peek() == '|') {
                    AppendToken(TokenType::OR, "||");
                    this->col++;
                    this->StepForward();
                } else {
                    AppendToken(TokenType::PIPE, "|");
                }
            break;
            case '&':
                this->startCol = this->col;
                if (this->Peek() == '&') {
                    AppendToken(TokenType::AND, "&&");
                    this->col++;
                    this->StepForward();
                } else {
                    AppendToken(TokenType::AMP, "&");
                }
            break;
            case ';':
                this->startCol = this->col;
                AppendToken(TokenType::SEMI, ";");
            break;
            case ':':
            this->startCol = this->col;
                AppendToken(TokenType::COLON, ":");
            break;
            case ',':
            this->startCol = this->col;
                AppendToken(TokenType::COMMA, ",");
            break;
            case '.':
            this->startCol = this->col;
                AppendToken(TokenType::DOT, ".");
            break;
            case '#':
            this->startCol = this->col;
                AppendToken(TokenType::HASH, "#");
            break;
            case '(':
                this->startCol = this->col;
            AppendToken(TokenType::LPAREN, "(");
            break;
            case ')':
                this->startCol = this->col;
            AppendToken(TokenType::RPAREN, ")");
            break;
            case '[':
                this->startCol = this->col;
            AppendToken(TokenType::LBRACK, "[");
            break;
            case ']':
                this->startCol = this->col;
            AppendToken(TokenType::RBRACK, "]");
            break;
            case '{':
                this->startCol = this->col;
            AppendToken(TokenType::LCURLY, "{");
            break;
            case '}':
                this->startCol = this->col;
            AppendToken(TokenType::RCURLY, "}");
            break;
            default:
                if (this->IsAlpha()) {
                    this->startCol = this->col;
                    while (this->IsAlpha() && !this->IsAtEnd() && !this->IsWhitespace()) {
                        this->Consume();
                        this->col++;
                    }
                    if (this->buffer == "int") {
                        AppendToken(TokenType::INT);
                    }
                    else if (this->buffer == "char") {
                        AppendToken(TokenType::CHAR);
                    }
                    else if (this->buffer == "string") {
                        AppendToken(TokenType::STRING);
                    }
                    else if (this->buffer == "float") {
                        AppendToken(TokenType::FLOAT);
                    }
                    else if (this->buffer == "if") {
                        AppendToken(TokenType::IF);
                    }
                    else if (this->buffer == "else") {
                        AppendToken(TokenType::ELSE);
                    }
                    else if (this->buffer == "for") {
                        AppendToken(TokenType::FOR);
                    }
                    else if (this->buffer == "while") {
                        AppendToken(TokenType::WHILE);
                    }
                    else if (this->buffer == "return") {
                        AppendToken(TokenType::RETURN);
                    }
                    else if (this->buffer == "struct") {
                        AppendToken(TokenType::STRUCT);
                    }
                    else if (this->buffer == "union") {
                        AppendToken(TokenType::UNION);
                    }
                    else if (this->buffer == "class") {
                        AppendToken(TokenType::CLASS);
                    }
                    else if (this->buffer == "type") {
                        AppendToken(TokenType::TYPE);
                    }
                    else if (this->buffer == "void") {
                        AppendToken(TokenType::VOID);
                    }
                    else if (this->buffer == "break") {
                        AppendToken(TokenType::BREAK);
                    }
                    else if (this->buffer == "continue") {
                        AppendToken(TokenType::CONTINUE);
                    }
                    else if (this->buffer == "true") {
                        AppendToken(TokenType::TRUE);
                    }
                    else if (this->buffer == "false") {
                        AppendToken(TokenType::FALSE);
                    }
                    else {
                        AppendToken(TokenType::IDENTIFIER);
                    }

                }
                else if (this->IsDigit()) {
                    this->startCol = this->col;
                    while (this->IsDigit()) {
                        this->Consume();
                        this->col++;
                    }
                    if (this->IsAlpha()) {
                        this->Consume();
                        this->col++;
                        while (this->IsDigit()) {
                            this->Consume();
                            this->col++;
                        }
                        std::cerr << "[Lexer] Invalid numerical literal: " << this->buffer << " at: (" <<  this->line << ", " << this->startCol << ")\n";
                        this->StepForward();
                        this->col++;
                        this->buffer.clear();
                    }
                    else {
                        AppendToken(TokenType::L_INT);
                    }
                }
                else if (this->IsWhitespace()) {
                    this->HandleWhitespace();
                }
                else {
                    printf("[Lexer] Unknown character '%c' (ASCII: %d) at (%d, %d)", this->current, this->current, this->line, this->col);
                    this->StepForward();
                    this->col++;
                }
        }
    }
    this->Tokens.push_back({TokenType::EOF_TOKEN, "0", this->line, this->col});
}

void Lexer::SetText(const std::string &text) {
    this->text = text;
    this->textSize = this->text.length();
    this->index = 0;
    this->current = this->text[this->index];
}

void Lexer::HandleWhitespace() {
    // If the current character is a whitespace
    if (this->current == '\n' || this->current == '\t' || this->current == '\r') {
        // If the current character is a new line, increment the line counter by one and reset the column counter.
        if (this->current == '\n') {
            if (this->mode == DEBUG && !this->buffer.empty()) {
                this->PrintBuffer();
            }
            this->line++;
            this->col = 1;
        }
        else if (this->current == '\t') {
            // If the current character is a tab, increment the column counter by tabSize.
            this->col += this->tabSize;
        }
        this->StepForward();
    }
    else if (this->current == ' ') {
        if (this->mode == DEBUG && !this->buffer.empty()) {
            this->PrintBuffer();
        }
        this->col++;
        this->StepForward();
    }
}

void Lexer::SkipCharacter() {
    if (!this->IsAtEnd())
        this->index++;
}

void Lexer::StepForward() {
    if (!this->IsAtEnd()) {
        this->index++;
        this->current = this->text[this->index];
    }
}

void Lexer::Consume() {
    this->buffer.push_back(this->current);
    this->StepForward();
}

void Lexer::PrintBuffer() const {
    std::cout << "---Buffer info---\n";
    std::cout << "Line: " << this->line << ", col: " << this->col - 1<< '\n';
    std::cout << "Buffer content: \"" << this->buffer << "\"\n";
}

void Lexer::AppendToken(const TokenType type) {
    this->Tokens.push_back({type, this->buffer, this->line, this->startCol});
    this->buffer.clear();
    // this->StepForward();
    // this->col++;
}

void Lexer::AppendToken(const TokenType type, const std::string &lexeme) {
    this->Tokens.push_back({type, lexeme, {this->line, this->startCol}});
    this->buffer.clear();
    this->StepForward();
    this->col++;
}

