#include "catch.hpp"

#include <logic/compile.h>
#include <logic/default_storage.h>
#include <logic/function/decoder.h>


TEST_CASE("", "[logic][function][decoder]") {
    constexpr auto func = &logic::function::decoder<1u>;
    static constexpr auto decoder_1_to_2 = logic::compile<logic::default_storage>(func);

    REQUIRE(decoder_1_to_2[0b0] == 1);
    REQUIRE(decoder_1_to_2[0b1] == 2);
}