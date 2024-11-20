#pragma once

#include "infix_parselet.h"

#include "../parser.h"
#include "../token.h"
#include "../token_type.h"
#include "../precedence.h"
#include "../expressions/call_expression.h"

#include <vector>

namespace pp {
class Expression;

struct CallParselet : InfixParselet
{
public:
    virtual Expression* parse(Parser* parser, Expression* left, const Token& token) override
    {
        std::vector<Expression*> args;

        if (!parser->match(TokenType::RIGHT_PAREN)) {
            do {
                args.push_back(parser->parseExpression());
            } while (parser->match(TokenType::COMMA));
            parser->consume(TokenType::RIGHT_PAREN);
        }

        return new CallExpression(left, std::move(args));
    }

    virtual int getPrecedence() const {
        return Precedence::CALL;
    }
};
}  // namespace pp
