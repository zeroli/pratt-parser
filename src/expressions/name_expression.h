#pragma once

#include "expression.h"

#include <string>

namespace pp {
struct NameExpression : Expression
{
    NameExpression(const std::string& name)
        : name_(name)
    { }

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
