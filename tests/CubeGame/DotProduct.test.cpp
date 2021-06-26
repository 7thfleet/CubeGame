#include "CubeGame/DotProduct.hpp"

#include <doctest/doctest.h>

#include <vector>

using namespace CubeGame;

TEST_CASE("DotProduct | Length Validation"){
    std::vector<int> lenThree = {1, 2, 3};
    std::vector<int> lenTwo   = {4, 5};
    
    SUBCASE("Incorrect calls"){
        CHECK_THROWS(DotProduct(lenThree, lenTwo));
        CHECK_THROWS(DotProduct(lenTwo, lenThree));
        CHECK_THROWS(DotProduct({}, lenTwo));
        CHECK_THROWS(DotProduct({}, lenThree));
    }

    SUBCASE("Correct calls"){
        CHECK_NOTHROW(DotProduct(lenTwo, lenTwo));
        CHECK_NOTHROW(DotProduct(lenThree, lenThree));
        CHECK_NOTHROW(DotProduct({}, {}));
    }
}

TEST_CASE("DotProduct | Correct Values"){
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};

    CHECK(DotProduct(a, b) == 32);

    CHECK(DotProduct({}, {}) == 0);

    CHECK(true == true);
}
