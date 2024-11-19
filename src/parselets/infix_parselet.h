#pragma once

namespace pp {
class Parser;
class Expression;
class Token;

struct InfixParselet
{
public:
    virtual ~InfixParselet() = default;

    virtual Expression* parse(Parser* parser, const Expression* left, const Token& token) = 0;

    virtual int getPrecedence() const = 0;

};
}  // namespace pp
