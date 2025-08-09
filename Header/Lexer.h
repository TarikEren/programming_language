#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

#include "Token.h"

enum LexerMode {
    DEBUG,
    PROD
};

/**
 * @brief The tokenizer class
 * @details
 * Handles and contains various tokenizer related functions. Tokenizes its text field using the tokenize() function
 */
class Lexer {
    int index{},                /// Current char's index
        line = 1,               /// Current char's line
        col = 1,                /// Current char's column
        tabSize{},              /// Each tab's size in the file
        startCol{};             /// The starting position of a keyword or token
    size_t textSize{};          /// Size of the text to tokenize
    char current{};             /// Current character
    std::string buffer{},       /// Buffer to hold the words
                text{};         /// Text to tokenize
    LexerMode mode;             /// Defines how the lexer should run
    std::vector<Token> Tokens;  /// Vector for the tokens

    /**
     * @brief Prints out the buffer information (For debug purposes)
     * @returns None
     */
    void PrintBuffer() const;

    /**
     * @brief Increments the index by one and sets the new character as the current character.
     * @returns None
     */
    void StepForward();


    /**
     * @brief Append to the buffer, iterate one character forward, set the current character as the new character
     * @return None
     */
    void Consume();

    /**
     * @brief Skips the current character by incrementing the index by one
     * @return None
     */
    void SkipCharacter();

    /**
     * @brief Handles the whitespace characters
     * @details
     * The function handles spaces, new lines, tabs and carriage returns.
     * It increments the line count by one and resets the column count if the current character is a new line.
     * It increments the column count by the preset tabSize value if the current character is a tab.
     * It increments the column count by one and creates a token based on the state of the string buffer.
     * WIP as there are no tokens or token creation
     * @returns None
     */
    void HandleWhitespace();

    /**
     * Checks whether the current character is a digit
     * @return True if the current character is a digit
     */
    [[nodiscard]] bool IsDigit() const {
        return this->current <= '9' && this->current >= '0';
    }

    /**
     * Checks whether the current character is an alphabetical character
     * @return True if the current character is an alphabetical character
     */
    [[nodiscard]] bool IsAlpha() const {
        return (this->current >= 65 && this->current <= 90) ||
                (this->current >= 97 && this->current <= 122) ||
                    this->current == '_';
    }

    /**
     * Checks whether the index is at the end of the text to tokenize
     * @return True if the index is at the end of the text
     */
    [[nodiscard]] bool IsAtEnd() const {
        return this->index >= this->textSize;
    }

    [[nodiscard]] bool IsWhitespace() const {
        return this->current == ' ' || this->current == '\t' || this->current == '\n';
    }

    [[nodiscard]] char Peek() const {
        if (!IsAtEnd()) {
            return this->text[this->index+1];
        }
        return '\0';
    }

    void AppendToken(TokenType type);
    void AppendToken(TokenType type, const std::string &lexeme);

public:
    /**
     * @brief Constructor for the Lexer class.
     * @param mode The mode of the lexer (DEBUG for additional messages, PROD for the normal procedure)
     * @param tabSize Tab size for the text to parse
     */
    explicit Lexer(const LexerMode mode, const int tabSize) {
        this->mode = mode;
        this->tabSize = tabSize;
    }

    /**
     * @brief Sets the text field of the Lexer class
     * @param text String to tokenize
     * @returns None
     */
    void SetText(const std::string &text);

    /**
     * @brief Iterate through the text field and take action accordingly
     * @details
     * Starting from the first character of "text", iterates through
     * until it encounters a null terminator. Checks the current character and
     * executes functions based on said character.
     * @returns None
     */
    void Tokenize();

    std::vector<Token> GetTokens() {
        return this->Tokens;
    }
};

#endif
