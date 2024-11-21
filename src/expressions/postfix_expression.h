#pragma once

#include "expression.h"
#include "../token_type.h"

namespace pp {
/**
 * A postfix unary arithmetic expression like "a!".
 */
struct PostfixExpression : Expression
{
    PostfixExpression(Expression* left, TokenType op)
        : left_(left), op_(op)
    { }
    ~PostfixExpression() {
        delete left_;
    }

    void print(std::ostream& os) const override {
        os << "(";
        left_->print(os);
        os << punctuator(op_)
           << ")";
    }
private:
    Expression* left_;
    TokenType op_;
};
}  // namespace pp
