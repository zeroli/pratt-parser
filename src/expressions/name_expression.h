#pragma once

#include "expression.h"

#include <string>

namespace pp {
/**
 * A simple variable name expression like "abc".
 */
struct NameExpression : Expression
{
    NameExpression(const std::string& name)
        : name_(name)
    { }
    ~NameExpression() = default;

    void print(std::ostream& os) const override {
        os << name_;
    }

    const std::string& name() const {
        return name_;
    }

private:
    std::string name_;
};
}  // namespace pp
