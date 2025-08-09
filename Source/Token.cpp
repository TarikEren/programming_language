#include "../Header/Token.h"

std::string Token::TokenToString() const {
    switch (this->type) {
        case INT:
            return "int";
        case CHAR:
            return "char";
        case STRING:
            return "string";
        case FLOAT:
            return "float";
        case IF:
            return "if";
        case ELSE:
            return "else";
        case FOR:
            return "for";
        case WHILE:
            return "while";
        case RETURN:
            return "return";
        case STRUCT:
            return "struct";
        case UNION:
            return "union";
        case CLASS:
            return "class";
        case TYPE:
            return "type";
        case L_INT:
            return std::string("L_INT, (").append(this->lexeme).append(")");
        case L_CHAR:
            return std::string("L_CHAR, (").append(this->lexeme).append(")");
        case L_STRING:
            return std::string("L_STRING, (").append(this->lexeme).append(")");
        case L_BOOLEAN:
            return std::string("L_BOOLEAN, (").append(this->lexeme).append(")");
        case L_NULL:
            return "L_NULL";
        case PLUS:
            return "+";
        case MINUS:
            return "-";
        case STAR:
            return "*";
        case SLASH:
            return "/";
        case MODULO:
            return "%";
        case INCREMENT:
            return "++";
        case DECREMENT:
            return "--";
        case EQUAL:
            return "=";
        case L_ANGLE:
            return "<";
        case R_ANGLE:
            return ">";
        case ADD_EQUAL:
            return "+=";
        case MIN_EQUAL:
            return "-=";
        case MUL_EQUAL:
            return "*=";
        case DIV_EQUAL:
            return "/=";
        case IS:
            return "==";
        case NOT:
            return "!=";
        case GEQ:
            return ">=";
        case LEQ:
            return "<=";
        case AND:
            return "&&";
        case OR:
            return "||";
        case BANG:
            return "!";
        case PIPE:
            return "|";
        case AMP:
            return "&";
        case SEMI:
            return ";";
        case COLON:
            return ":";
        case COMMA:
            return ",";
        case DOT:
            return ".";
        case HASH:
            return "#";
        case COMMENT:
            return "COMMENT";
        case IDENTIFIER:
            return std::string("IDENT, (").append(this->lexeme).append(")");
        case EOF_TOKEN:
            return "EOF";
        default:
            return "UNKNOWN";
    }
}
