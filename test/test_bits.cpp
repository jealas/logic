#include "catch.hpp"

#include <logic/bits.h>

TEST_CASE("bit function gets the correct bit value", "[logic][bits]") {
    SECTION("1 bit") {
        SECTION("default initialization") {
            logic::bits<1> bit_off{};
            REQUIRE(bit_off.bit<0>() == 0);
        }

        SECTION("value initialized") {
            logic::bits<1> bit_on{1};
            REQUIRE(bit_on.bit<0>() == 1);

            logic::bits<1> bit_off{0};
            REQUIRE(bit_off.bit<0>() == 0);
        }
    }

    SECTION("multiple bits") {
        SECTION("default initialization") {
            logic::bits<2> two_bits{0};
            REQUIRE(two_bits.bit<0>() == 0);
            REQUIRE(two_bits.bit<1>() == 0);

            REQUIRE(two_bits.bit_span<0, 2>() == 0);
        }

        SECTION("value initialized") {
            logic::bits<2> bit_zero{0};
            REQUIRE(bit_zero.bit<0>() == 0);

            logic::bits<2> bit_one{1};
            REQUIRE(bit_one.bit<0>() == 1);
            REQUIRE(bit_one.bit<1>() == 0);

            REQUIRE(bit_one.bit_span<0, 2>() == 1);

            logic::bits<2> bit_two{2};
            REQUIRE(bit_two.bit<0>() == 0);
            REQUIRE(bit_two.bit<1>() == 1);

            REQUIRE(bit_two.bit_span<0, 2>() == 2);

            logic::bits<2> bit_three{3};
            REQUIRE(bit_three.bit<0>() == 1);
            REQUIRE(bit_three.bit<1>() == 1);

            REQUIRE(bit_three.bit_span<0, 2>() == 3);
        }

        SECTION("value initialized compared to bits") {
            logic::bits<2> bit_zero{0};
            REQUIRE(bit_zero.bit<0>() == 0);

            logic::bits<2> bit_one{1};
            REQUIRE(bit_one.bit<0>() == 1);
            REQUIRE(bit_one.bit<1>() == 0);

            REQUIRE(bit_one.bit_span<0, 2>() == 1);
            REQUIRE(bit_one.bit_span<0, 2>() == logic::bits<2>{1});

            logic::bits<2> bit_two{2};
            REQUIRE(bit_two.bit<0>() == 0);
            REQUIRE(bit_two.bit<1>() == 1);

            REQUIRE(bit_two.bit_span<0, 2>() == logic::bits<2>{2});

            logic::bits<2> bit_three{3};
            REQUIRE(bit_three.bit<0>() == 1);
            REQUIRE(bit_three.bit<1>() == 1);

            REQUIRE(bit_three.bit_span<0, 2>() == logic::bits<2>{3});
        }
    }
}

TEST_CASE("Bits concatenation", "[xtl][bits]") {
    SECTION("number of bits after concatenation is the sum of both numbers of bits") {
        const logic::bits<1> part1{};
        const logic::bits<1> part2{};

        const auto result = part1.cat(part2);
        REQUIRE(part1.num_bits() + part2.num_bits() == result.num_bits());
        REQUIRE(result.value() == 0);
    }

    SECTION("bits are concatenated correctly") {
        const logic::bits<2> part1{0b01};
        const logic::bits<2> part2{0b10};

        const auto result = part1.cat(part2);
        REQUIRE(result.value() == 0b1001);
        REQUIRE(result.bit_span<0, 2>() == 0b01);
        REQUIRE(result.bit_span<2, 4>() == 0b10);
    }
}