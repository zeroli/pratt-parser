#pragma once

#include "infix_parselet.h"
#include "../parser.h"
#include "../token.h"
#include "../expressions/op_expression.h"

namespace pp {
class Expression;

struct BinaryOpParselet : InfixParselet
{
public:
    BinaryOpParselet(int precedence, bool isRight)
        : precedence_(precedence), isRight_(isRight)
    { }

    virtual Expression* parse(Parser* parser, const Expression* left, const Token& token) override
    {
        Expression* right = parser->parseExpression(precedence_ - (isRight_ ? 1 : 0));
        return new OpExpression(left, token.type(), right);
    }

    virtual int getPrecedence() const
    {
        return precedence_;
    }
private:
    int precedence_;
    bool isRight_;
};
}  // namespace pp
