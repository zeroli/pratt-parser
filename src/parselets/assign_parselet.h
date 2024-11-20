#pragma once

#include "infix_parselet.h"
#include "../precedence.h"
#include "../parser.h"
#include "../token.h"
#include "../expressions/name_expression.h"
#include "../expressions/assign_expression.h"

#include <cassert>

namespace pp {
class Expression;
class NameExpression;

/**
 * @brief parse assignment expression like: a = b
 * the left side of an assignment expression must be a simple name like 'a',
 * and expression are right-associative. In other words, a = b = c
 * is parsed as 'a = (b = c)'
 *
 */
struct AssignParselet : InfixParselet
{
public:
    virtual Expression* parse(Parser* parser, Expression* left, const Token& token)
    {
        Expression* right = parser->parseExpression(Precedence::ASSIGNMENT - 1);
        assert(dynamic_cast<const NameExpression*>(left) != nullptr);

        auto leftp = dynamic_cast<const NameExpression*>(left);
        auto name = leftp->name();
        return new AssignExpression(name, right);
    }

    virtual int getPrecedence() const {
        return Precedence::ASSIGNMENT;
    }
};
}  // namespace pp
