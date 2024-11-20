#pragma once

#include "infix_parselet.h"

#include "../parser.h"
#include "../token.h"
#include "../token_type.h"
#include "../precedence.h"
#include "../expressions/conditional_expression.h"

namespace pp {
class Expression;

/**
 * @brief parselet for the condition or "tenary" operator, like "a ? b : c"
 *
 */
struct ConditionalParselet : InfixParselet
{
public:
    virtual Expression* parse(Parser* parser, Expression* left, const Token& token)
    {
        Expression* thenArm = parser->parseExpression();
        parser->consume(TokenType::COLON);
        // right associative for else-part 'c' parsing
        Expression* elseArm = parser->parseExpression(Precedence::CONDITIONAL - 1);

        return new ConditionalExpression(left, thenArm, elseArm);
    }

    virtual int getPrecedence() const {
        return Precedence::CONDITIONAL;
    }
};
}  // namespace pp
