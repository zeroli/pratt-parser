#pragma once

#include "expression.h"

namespace pp {
/**
 * A ternary conditional expression like "a ? b : c".
 */
struct ConditionalExpression : Expression
{
    ConditionalExpression(Expression* condition, Expression* thenArm, Expression* elseArm)
        : condition_(condition), thenArm_(thenArm), elseArm_(elseArm)
    {
    }

    ~ConditionalExpression() {
        delete condition_;
        delete thenArm_;
        delete elseArm_;
    }
    void print(std::ostream& os) const override {
        os << "(";
        condition_->print(os);
        os << " ? ";
        thenArm_->print(os);
        os << " : ";
        elseArm_->print(os);
        os << ")";
    }
private:
    Expression* condition_;
    Expression* thenArm_;
    Expression* elseArm_;
};
}  // namespace pp
