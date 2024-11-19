#pragma once

#include <cassert>

namespace pp {
enum TokenType {
    TOKEN_BEGIN = 0,
    LEFT_PAREN = TOKEN_BEGIN,   // (
    RIGHT_PAREN,  // )
    COMMA,        // ,
    ASSIGN,       // =
    PLUS,         // +
    MINUS,        // -
    ASTERISK,     // *
    SLASH,        // /
    CARET,        // ^
    TILDE,        // ~
    BANG,         // #
    QUESTION,     // ?
    COLON,        // :
    NAME,
    EOT,
    TOKEN_END,
};

inline char punctuator(TokenType token_type)
{
    switch (token_type) {
        case TokenType::LEFT_PAREN:     return '(';
        case TokenType::RIGHT_PAREN:    return ')';
        case TokenType::COMMA:          return ',';
        case TokenType::ASSIGN:         return '=';
        case TokenType::PLUS:           return '+';
        case TokenType::MINUS:          return '-';
        case TokenType::ASTERISK:       return '*';
        case TokenType::SLASH:          return '/';
        case TokenType::CARET:          return '^';
        case TokenType::TILDE:          return '~';
        case TokenType::BANG:           return '!';
        case TokenType::QUESTION:       return '?';
        case TokenType::COLON:          return ':';
        default:                        break;
    }
    return '\0';
}
}
