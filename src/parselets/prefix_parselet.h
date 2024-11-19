#pragma once

namespace pp {
class Parser;
class Expression;
class Token;

struct PrefixParselet
{
public:
    virtual ~PrefixParselet() = default;

    virtual Expression* parse(Parser* parser, const Token& token) = 0;
};
}  // namespace pp
