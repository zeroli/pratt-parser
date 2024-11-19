#pragma once

#include "prefix_parselet.h"
#include "../expressions/name_expression.h"
#include "../parser.h"
#include "../token.h"

namespace pp {
struct NameParselet : PrefixParselet
{
public:
    virtual Expression* parse(Parser* parser, const Token& token) override
    {
        return new NameExpression(token.text());
    }
};
}  // namespace pp
