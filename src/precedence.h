#pragma once

namespace pp {
struct Precedence {
    static constexpr const int ASSIGNMENT   = 1;
    static constexpr const int CONDITIONAL  = 2;
    static constexpr const int SUM          = 3;
    static constexpr const int PRODUCT      = 4;
    static constexpr const int EXPONENT     = 5;
    static constexpr const int PREFIX       = 6;
    static constexpr const int POSTFIX      = 7;
    static constexpr const int CALL         = 8;
};
}  // namespace pp
