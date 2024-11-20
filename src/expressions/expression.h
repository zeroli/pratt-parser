#pragma once

#include <string>
#include <sstream>

namespace pp {
struct Expression
{
    virtual ~Expression() = default;

    virtual void print(std::ostream& os) const = 0;
};
}  // namespace pp
