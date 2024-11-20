#pragma once

#include "expression.h"
#include "../token_type.h"

namespace pp {
/**
 * A binary arithmetic expression like "a + b" or "c ^ d".
 */
struct OpExpression : Expression
{
    OpExpression(Expression* left, TokenType op, Expression* right)
        : left_(left), op_(op), right_(right)
    { }

    void print(std::ostream& os) const override {
        os << "(";
        left_->print(os);
        os << " " << punctuator(op_) << " ";
        right_->print(os);
        os << ")";
    }
private:
    Expression* left_;
    TokenType op_;
    Expression* right_;
};
}  // namespace pp
