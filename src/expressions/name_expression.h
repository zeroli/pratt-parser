#pragma once

#include "expression.h"

#include <string>

namespace pp {
struct NameExpression : Expression
{
public:
    const std::string& name() const {
        return name_;
    }

private:
    std::string name_;
};
}  // namespace pp
