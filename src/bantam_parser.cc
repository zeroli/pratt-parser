#include "bantam_parser.h"

#include "precedence.h"
#include "parselets/name_parselet.h"
#include "parselets/assign_parselet.h"
#include "parselets/conditional_parselet.h"
#include "parselets/group_parselet.h"
#include "parselets/call_parselet.h"

namespace pp {
BantamParser::BantamParser(std::unique_ptr<Lexer> lexer)
    : Parser(std::move(lexer))
{
    Register(TokenType::NAME,       std::make_shared<NameParselet>());
    Register(TokenType::ASSIGN,     std::make_shared<AssignParselet>());
    Register(TokenType::QUESTION,   std::make_shared<ConditionalParselet>());
    Register(TokenType::LEFT_PAREN, std::make_shared<GroupParselet>());
    Register(TokenType::LEFT_PAREN, std::make_shared<CallParselet>());

    prefix(TokenType::PLUS,     Precedence::PREFIX);
    prefix(TokenType::MINUS,    Precedence::PREFIX);
    prefix(TokenType::TILDE,    Precedence::PREFIX);
    prefix(TokenType::BANG,     Precedence::PREFIX);

    postfix(TokenType::BANG,    Precedence::POSTFIX);

    infixLeft(TokenType::PLUS,      Precedence::SUM);
    infixLeft(TokenType::MINUS,     Precedence::SUM);
    infixLeft(TokenType::ASTERISK,  Precedence::PRODUCT);
    infixLeft(TokenType::SLASH,     Precedence::PRODUCT);
    infixRight(TokenType::CARET,     Precedence::EXPONENT);
}
}  // namespace pp
