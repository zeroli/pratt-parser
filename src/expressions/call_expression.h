#pragma once

#include "expression.h"
#include <vector>

namespace pp {
/**
 * A function call like "a(b, c, d)".
 */
struct CallExpression : Expression
{
    CallExpression(Expression* function, std::vector<Expression*>&& args)
        : function_(function), args_(std::move(args))
    {
    }

    void print(std::ostream& os) const {
        function_->print(os);
        os << "(";
        if (!args_.empty()) {
            args_[0]->print(os);
            for (auto i = 1; i < args_.size(); i++) {
                os << ", ";
                args_[i]->print(os);
            }
        }
        os << ")";
    }
private:
    Expression* function_;
    std::vector<Expression*> args_;
};
}  // namespace pp
