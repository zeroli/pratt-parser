#pragma once

#include "../parser.h"
#include "../token.h"
#include "../token_type.h"
#include "prefix_parselet.h"

namespace pp {
class Expression;

struct GroupParselet : PrefixParselet
{
public:
    virtual Expression* parse(Parser* parser, const Token& token) override
    {
        Expression* expression = parser->parseExpression();
        parser->consume(TokenType::RIGHT_PAREN);
        return expression;
    }
};
}  // namespace pp
