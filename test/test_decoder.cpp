#include "catch.hpp"

#include <logic/compile.h>
#include <logic/default_storage.h>
#include <logic/function/decoder.h>

SCENARIO("Basic decoder generates the correct outputs",
         "[logic][function][decoder]") {
  WHEN("using a 1-bit decoder") {
    static constexpr auto compiled_decoder_func =
        logic::compile<logic::default_storage>(&logic::function::decoder<1u>);

    REQUIRE(compiled_decoder_func[0b0] == 0b01);
    REQUIRE(compiled_decoder_func[0b1] == 0b10);
  }

  WHEN("using a 2-bit decoder") {
    static constexpr auto compiled_decoder_func =
        logic::compile<logic::default_storage>(&logic::function::decoder<2u>);

    REQUIRE(compiled_decoder_func[0b00] == 0b0001);
    REQUIRE(compiled_decoder_func[0b01] == 0b0010);
    REQUIRE(compiled_decoder_func[0b10] == 0b0100);
    REQUIRE(compiled_decoder_func[0b11] == 0b1000);
  }

  WHEN("using a 3-bit decoder") {
    static constexpr auto compiled_decoder_func =
        logic::compile<logic::default_storage>(&logic::function::decoder<3u>);

    REQUIRE(compiled_decoder_func[0b000] == 0b00000001);
    REQUIRE(compiled_decoder_func[0b001] == 0b00000010);
    REQUIRE(compiled_decoder_func[0b010] == 0b00000100);
    REQUIRE(compiled_decoder_func[0b011] == 0b00001000);
    REQUIRE(compiled_decoder_func[0b100] == 0b00010000);
    REQUIRE(compiled_decoder_func[0b101] == 0b00100000);
    REQUIRE(compiled_decoder_func[0b110] == 0b01000000);
    REQUIRE(compiled_decoder_func[0b111] == 0b10000000);
  }
}