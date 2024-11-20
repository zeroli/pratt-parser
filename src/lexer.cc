#include "lexer.h"

namespace pp {
void Lexer::initAllTokens()
{
    for (int t = TokenType::TOKEN_BEGIN; t < TokenType::TOKEN_END; t++)
    {
        auto c = punctuator(TokenType(t));
        if (c != '\0') {
            punctuators_[c] = TokenType(t);
        }
    }
}

Token Lexer::next()
{
    while (index_ < text_.length()) {
        char c = text_[index_++];
        if (punctuators_.count(c) > 0) {
            return Token(punctuators_[c], std::string(1, c));
        } else if (std::isalpha(c)) {  // name
            int start = index_ - 1;
            while (index_ < text_.length()) {
                if (!std::isalnum(text_[index_]) && text_[index_] != '_') {
                    break;
                }
                index_++;
            }
            auto name = text_.substr(start, index_ - start);
            return Token(TokenType::NAME, name);
        } else {
            /// ignore all whitespaces, etc
        }
    }
    return Token(TokenType::EOT, "");
}
}  // namespace pp
