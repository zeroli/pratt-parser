#include "parser.h"
#include "expressions/expression.h"
#include "parselets/infix_parselet.h"
#include "parselets/prefix_parselet.h"

#include <cassert>

namespace pp {
Expression* Parser::parseExpression(int precedence)
{
    Token token = consume();
    auto prefix = prefixParselets_[token.type()];
    assert(prefix);

    Expression* left = prefix->parse(this, token);

    while (precedence < getPrecedence()) {
        token = consume();

        auto infix = infixParselets_[token.type()];
        left = infix->parse(this, left, token);
    }
    return left;
}


bool Parser::match(TokenType expected)
{
    Token token = lookAhead(0);
    if (token.type() != expected) {
        return false;
    }
    consume();
    return true;
}

Token Parser::consume(TokenType expected)
{
    auto token = lookAhead(0);
    if (token.type() != expected) {
        assert(0 && "token type doesn't match");
    }
    return consume();
}

Token Parser::consume()
{
    lookAhead(0);
    auto token = reads_[0];
    reads_.pop_front();
    return token;
}

Token Parser::lookAhead(int distance)
{
    while (distance >= reads_.size()) {
        reads_.push_back(lexer_->next());
    }
    return reads_[distance];
}

int Parser::getPrecedence()
{
    auto parser = infixParselets_[lookAhead(0).type()];
    if (parser) {
        return parser->getPrecedence();
    }
    return 0;
}
}  // namespace pp
