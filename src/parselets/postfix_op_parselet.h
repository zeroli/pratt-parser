#pragma once

#include "infix_parselet.h"
#include "../token.h"
#include "../expressions/postfix_expression.h"

namespace pp {
struct PostfixOpParselet : public InfixParselet
{
public:
    PostfixOpParselet(int precedence)
        : precedence_(precedence)
    { }

    virtual ~PostfixParselet() = default;

    virtual Expression* parse(Parser* parser, const Expression* left, const Token& token) override
    {
        return new PostfixExpression(left, token.type());
    }

    virtual int getPrecedence() const {
        return precedence_;
    }
private:
    int precedence_;
};
}  // namespace pp
