#pragma once

#include "token_type.h"
#include "token.h"

#include <string>
#include <map>

namespace pp {
struct Lexer {
public:
    Lexer(const std::string& text)
        : index_(0), text_(text)
    {
        initAllTokens();
    }

    bool hasNext() {
        return true;
    }

    Token next();
private:
    void initAllTokens();
private:
    size_t index_;
    std::string text_;
    std::map<char, TokenType> punctuators_;
};
}  // namespace pp
