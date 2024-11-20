#pragma once

#include "expression.h"
#include "../token_type.h"

namespace pp {
/**
 * A prefix unary arithmetic expression like "!a" or "-b".
 */
struct PrefixExpression : Expression
{
    PrefixExpression(TokenType op, Expression* right)
        : op_(op), right_(right)
    { }

    void print(std::ostream& os) const override {
        os << "(" << punctuator(op_);
        right_->print(os);
        os << ")";
    }
private:
    TokenType op_;
    Expression* right_;
};

}  // namespace pp
