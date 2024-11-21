#pragma once

#include "expression.h"

namespace pp {
/**
 * An assignment expression like "a = b".
 */
struct AssignExpression : Expression
{
    AssignExpression(const std::string& name, Expression* right)
        : name_(name), right_(right)
    {
    }
    ~AssignExpression() {
        delete right_;
    }

    void print(std::ostream& os) const override {
        os << "(" << name_ << " = ";
        right_->print(os);
        os << ")";
    }
private:
    std::string name_;
    Expression* right_;
};
}  // namespace pp
