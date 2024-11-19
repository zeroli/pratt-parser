#pragma once

#include "parser.h"

#include <memory>

namespace pp {
class Lexer;

struct BantamParser : Parser {
public:
    explicit BantamParser(std::unique_ptr<Lexer> lexer);

private:
    void postfix(TokenType token, int precedence) {
        Register(token, std::make_unique<PostfixOpParselet>(precedence));
    }

    void prefix(TokenType token, int precedence) {
        Register(token, std::make_unique<PrefixOpParselet>(precedence));
    }

    void infixLeft(TokenType token, int precedence) {
        Register(token, std::make_unique<BinaryOpParselet>(precedence, false));
    }

    void infixRight(TokenType token, int precedence) {
        Register(token, std::make_unique<BinaryOpParselet>(precedence, true));
    }
};
}  // namespace pp
