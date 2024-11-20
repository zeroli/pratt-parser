#pragma once

#include "infix_parselet.h"
#include "../token.h"
#include "../expressions/postfix_expression.h"

namespace pp {
/**
 * Generic infix parselet for an unary arithmetic operator. Parses postfix
 * unary "?" expressions.
 */

struct PostfixOpParselet : public InfixParselet
{
public:
    PostfixOpParselet(int precedence)
        : precedence_(precedence)
    { }

    virtual ~PostfixOpParselet() = default;

    virtual Expression* parse(Parser* parser, Expression* left, const Token& token) override
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
