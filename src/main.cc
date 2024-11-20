#include "bantam_parser.h"
#include "token.h"
#include "token_type.h"
#include "precedence.h"
#include "lexer.h"
#include "expressions/expression.h"

#include <memory>
#include <iostream>
#include <sstream>

using namespace pp;

bool test(const std::string& code, const std::string& expected)
{
    auto lexer = std::make_unique<Lexer>(code);
    BantamParser parser(std::move(lexer));

    Expression* result = parser.parseExpression();

    std::ostringstream os;
    result->print(os);

    auto actual = os.str();
    if (expected == actual) {
        std::cerr << "[PASS]: " << code << "\n";
        return true;
    }
    std::cerr << "[FAIL]:     " << code     << "\n";
    std::cerr << "  Expected: " << expected << "\n";
    std::cerr << "  Actual:   " << actual   << "\n";
    return false;
}

int main()
{
    test("a()", "a()");
    test("a(b)", "a(b)");
    test("a(b,c)", "a(b, c)");
    test("a(b)(c)", "a(b)(c)");
    test("a(b) + c(d)", "(a(b) + c(d))");
    test("a(b ? c : d, e + f)", "a((b ? c : d), (e + f))");

    // unary precedence
    test("~!-+a", "(~(!(-(+a))))");
    test("a!!!", "(((a!)!)!)");

    // unary and binary precedence
    test("-a * b", "((-a) * b)");
    test("!a + b", "((!a) + b)");
    test("~a ^ b", "((~a) ^ b)");
    test("-a!", "(-(a!))");
    test("!a!", "(!(a!))");

    // binary precedence
    test("a = b + c * d ^ e - f / g", "(a = ((b + (c * (d ^ e))) - (f / g)))");

    // binary associativity
    test("a = b = c", "(a = (b = c))");
    test("a + b - c", "((a + b) - c)");
    test("a * b / c", "((a * b) / c)");
    test("a ^ b ^ c", "(a ^ (b ^ c))");

    // conditional operator
    test("a ? b : c ? d : e", "(a ? b : (c ? d : e))");
    test("a ? b ? c : d : e", "(a ? (b ? c : d) : e)");
    test("a + b ? c * d : e / f", "((a + b) ? (c * d) : (e / f))");

    // grouping
    test("a + (b + c) + d", "((a + (b + c)) + d)");
    test("a ^ (b + c)", "(a ^ (b + c))");
    test("(!a)!", "((!a)!)");
}
