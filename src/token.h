#pragma once

#include "token_type.h"
#include <string>

namespace pp {
struct Token {
    Token(TokenType type, const std::string& text)
        : type_(type), text_(text)
    { }

    TokenType type() const { return type_; }
    const std::string& text() const { return text_; }

    std::string toString() const {
        return text_;
    }
private:
    TokenType type_;
    std::string text_;
};
}  // namespace pp
