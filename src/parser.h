#pragma once

#include "lexer.h"
#include "token_type.h"
#include "token.h"

#include <map>
#include <memory>
#include <deque>

namespace pp {
class Lexer;
class Expression;

class PrefixParselet;
class InfixParselet;

using PrefixParseletPtr_t = std::shared_ptr<PrefixParselet>;
using InfixParseletPtr_t = std::shared_ptr<InfixParselet>;

struct Parser {
public:
    explicit Parser(std::unique_ptr<Lexer> lexer)
        : lexer_(std::move(lexer))
    { }

    virtual ~Parser() = default;

    void Register(TokenType token, PrefixParseletPtr_t parselet) {
        prefixParselets_[token] = std::move(parselet);
    }
    void Register(TokenType token, InfixParseletPtr_t parselet) {
        infixParselets_[token] = std::move(parselet);
    }

    Expression* parseExpression(int precedence);

    Expression* parseExpression() {
        return parseExpression(0);
    }

    bool match(TokenType expected);

    Token consume(TokenType expected);
    Token consume();

private:
    Token lookAhead(int distance);

    int getPrecedence();
private:
    std::unique_ptr<Lexer> lexer_;
    std::deque<Token> reads_;

    std::map<TokenType, PrefixParseletPtr_t> prefixParselets_;
    std::map<TokenType, InfixParseletPtr_t> infixParselets_;

};
}  // namespace pp
