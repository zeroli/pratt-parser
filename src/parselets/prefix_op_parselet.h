#pragma once

#include "prefix_parselet.h"
#include "../parser.h"
#include "../token.h"
#include "../expressions/prefix_expression.h"

namespace pp {
struct PrefixOpParselet : PrefixParselet
{
public:
    PrefixOpParselet(int precedence)
        : precedence_(precedence)
    { }

    virtual Expression* parse(Parser* parser, const Token& token) {
        Expression* right = parser->parseExpression(precedence_);
        return new PrefixExpression(token.type(), right);
    }

    virtual int getPrecedence() const {
        return precedence_;
    }
private:
    int precedence_;
};

}  // namespace pp
