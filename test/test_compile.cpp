#include <catch.hpp>

#include <logic/compile.h>
#include <logic/default_storage.h>

#include <logic/and_fn.hpp>
#include <logic/nand_fn.hpp>
#include <logic/nor_fn.hpp>
#include <logic/or_fn.hpp>
#include <logic/popcount_fn.hpp>

constexpr logic::bits<1> and_function(const logic::bits<2> bits) {
  return bits.bit<0>() and bits.bit<1>();
}

constexpr logic::bits<1> or_function(const logic::bits<2> bits) {
  return bits.bit<0>() or bits.bit<1>();
}

constexpr logic::bits<1> xor_function(const logic::bits<2> bits) {
  return bits.bit<0>() xor bits.bit<1>();
}

constexpr logic::bits<1> nand_function(const logic::bits<2> bits) {
  return not(bits.bit<0>() and bits.bit<1>());
}

constexpr logic::bits<1> nor_function(const logic::bits<2> bits) {
  return not(bits.bit<0>() or bits.bit<1>());
}

constexpr logic::bits<1> xnor_function(const logic::bits<2> bits) {
  return not(bits.bit<0>() xor bits.bit<1>());
}

constexpr logic::bits<1> not_function(const logic::bits<1> bit) {
  return not bit;
}

TEST_CASE("Can compile simple logic gates", "[logic][compile]") {
  SECTION("and function") {
    static constexpr auto compiled_and_function =
        logic::compile<logic::default_storage>(&and_function);

    REQUIRE(compiled_and_function.size() == 4);

    REQUIRE(compiled_and_function[0b00] == 0);
    REQUIRE(compiled_and_function[0b01] == 0);
    REQUIRE(compiled_and_function[0b10] == 0);
    REQUIRE(compiled_and_function[0b11] == 1);
  }

  SECTION("or function") {
    static constexpr auto compiled_or_function =
        logic::compile<logic::default_storage>(&or_function);

    REQUIRE(compiled_or_function.size() == 4);

    REQUIRE(compiled_or_function[0b00] == 0);
    REQUIRE(compiled_or_function[0b01] == 1);
    REQUIRE(compiled_or_function[0b10] == 1);
    REQUIRE(compiled_or_function[0b11] == 1);
  }

  SECTION("xor function") {
    static constexpr auto compiled_xor_function =
        logic::compile<logic::default_storage>(&xor_function);

    REQUIRE(compiled_xor_function.size() == 4);

    REQUIRE(compiled_xor_function[0b00] == 0);
    REQUIRE(compiled_xor_function[0b01] == 1);
    REQUIRE(compiled_xor_function[0b10] == 1);
    REQUIRE(compiled_xor_function[0b11] == 0);
  }

  SECTION("nand function") {
    static constexpr auto compiled_nand_function =
        logic::compile<logic::default_storage>(&nand_function);

    REQUIRE(compiled_nand_function.size() == 4);

    REQUIRE(compiled_nand_function[0b00] == 1);
    REQUIRE(compiled_nand_function[0b01] == 1);
    REQUIRE(compiled_nand_function[0b10] == 1);
    REQUIRE(compiled_nand_function[0b11] == 0);
  }

  SECTION("nor function") {
    static constexpr auto compiled_nor_function =
        logic::compile<logic::default_storage>(&nor_function);

    REQUIRE(compiled_nor_function.size() == 4);

    REQUIRE(compiled_nor_function[0b00] == 1);
    REQUIRE(compiled_nor_function[0b01] == 0);
    REQUIRE(compiled_nor_function[0b10] == 0);
    REQUIRE(compiled_nor_function[0b11] == 0);
  }

  SECTION("xnor function") {
    static constexpr auto compiled_xnor_function =
        logic::compile<logic::default_storage>(&xnor_function);

    REQUIRE(compiled_xnor_function.size() == 4);

    REQUIRE(compiled_xnor_function[0b00] == 1);
    REQUIRE(compiled_xnor_function[0b01] == 0);
    REQUIRE(compiled_xnor_function[0b10] == 0);
    REQUIRE(compiled_xnor_function[0b11] == 1);
  }

  SECTION("not function") {
    static constexpr auto compiled_not_function =
        logic::compile<logic::default_storage>(&not_function);

    REQUIRE(compiled_not_function.size() == 2);

    REQUIRE(compiled_not_function[0] == 1);
    REQUIRE(compiled_not_function[1] == 0);
  }
}

constexpr logic::bits<1> and_function_multi(const logic::bits<1> a,
                                            const logic::bits<1> b) {
  return a and b;
}

constexpr logic::bits<1> or_function_multi(const logic::bits<1> a,
                                           const logic::bits<1> b) {
  return a or b;
}

constexpr logic::bits<1> xor_function_multi(const logic::bits<1> a,
                                            const logic::bits<1> b) {
  return (a or b) and not(a and b);
}

constexpr logic::bits<1> nand_function_multi(const logic::bits<1> a,
                                             const logic::bits<1> b) {
  return not(a and b);
}

constexpr logic::bits<1> nor_function_multi(const logic::bits<1> a,
                                            const logic::bits<1> b) {
  return not(a or b);
}

constexpr logic::bits<1> xnor_function_multi(const logic::bits<1> a,
                                             const logic::bits<1> b) {
  return not((a or b) and not(a and b));
}

TEST_CASE("Can compile simple logic gates with multiple input bits",
          "[logic][compile]") {
  SECTION("and function") {
    static constexpr auto compiled_and_function =
        logic::compile<logic::default_storage>(&and_function_multi);

    REQUIRE(compiled_and_function.size() == 4);

    REQUIRE(compiled_and_function[0b00] == 0);
    REQUIRE(compiled_and_function[0b01] == 0);
    REQUIRE(compiled_and_function[0b10] == 0);
    REQUIRE(compiled_and_function[0b11] == 1);
  }

  SECTION("or function") {
    static constexpr auto compiled_or_function =
        logic::compile<logic::default_storage>(&or_function_multi);

    REQUIRE(compiled_or_function.size() == 4);

    REQUIRE(compiled_or_function[0b00] == 0);
    REQUIRE(compiled_or_function[0b01] == 1);
    REQUIRE(compiled_or_function[0b10] == 1);
    REQUIRE(compiled_or_function[0b11] == 1);
  }

  SECTION("xor function") {
    static constexpr auto compiled_xor_function =
        logic::compile<logic::default_storage>(&xor_function_multi);

    REQUIRE(compiled_xor_function.size() == 4);

    REQUIRE(compiled_xor_function[0b00] == 0);
    REQUIRE(compiled_xor_function[0b01] == 1);
    REQUIRE(compiled_xor_function[0b10] == 1);
    REQUIRE(compiled_xor_function[0b11] == 0);
  }

  SECTION("nand function") {
    static constexpr auto compiled_nand_function =
        logic::compile<logic::default_storage>(&nand_function_multi);

    REQUIRE(compiled_nand_function.size() == 4);

    REQUIRE(compiled_nand_function[0b00] == 1);
    REQUIRE(compiled_nand_function[0b01] == 1);
    REQUIRE(compiled_nand_function[0b10] == 1);
    REQUIRE(compiled_nand_function[0b11] == 0);
  }

  SECTION("nor function") {
    static constexpr auto compiled_nor_function =
        logic::compile<logic::default_storage>(&nor_function_multi);

    REQUIRE(compiled_nor_function.size() == 4);

    REQUIRE(compiled_nor_function[0b00] == 1);
    REQUIRE(compiled_nor_function[0b01] == 0);
    REQUIRE(compiled_nor_function[0b10] == 0);
    REQUIRE(compiled_nor_function[0b11] == 0);
  }

  SECTION("xnor function") {
    static constexpr auto compiled_xnor_function =
        logic::compile<logic::default_storage>(&xnor_function_multi);

    REQUIRE(compiled_xnor_function.size() == 4);

    REQUIRE(compiled_xnor_function[0b00] == 1);
    REQUIRE(compiled_xnor_function[0b01] == 0);
    REQUIRE(compiled_xnor_function[0b10] == 0);
    REQUIRE(compiled_xnor_function[0b11] == 1);
  }
}

SCENARIO("and_fn can be used to generate n-way and gates") {
  WHEN("using a 2-bit and_fn") {
    auto compiled_and_fn =
        logic::compile<logic::default_storage>(&logic::and_fn<2u>);

    REQUIRE(compiled_and_fn.size() == 4);

    REQUIRE(compiled_and_fn[0b00] == false);
    REQUIRE(compiled_and_fn[0b01] == false);
    REQUIRE(compiled_and_fn[0b10] == false);
    REQUIRE(compiled_and_fn[0b11] == true);
  }

  WHEN("using a 2-bit nand_fn") {
    auto compiled_nand_fn =
        logic::compile<logic::default_storage>(&logic::nand_fn<2u>);

    REQUIRE(compiled_nand_fn.size() == 4);

    REQUIRE(compiled_nand_fn[0b00] == true);
    REQUIRE(compiled_nand_fn[0b01] == true);
    REQUIRE(compiled_nand_fn[0b10] == true);
    REQUIRE(compiled_nand_fn[0b11] == false);
  }

  WHEN("using a 2-bit or_fn") {
    auto compiled_or_fn =
        logic::compile<logic::default_storage>(&logic::or_fn<2u>);

    REQUIRE(compiled_or_fn.size() == 4);

    REQUIRE(compiled_or_fn[0b00] == false);
    REQUIRE(compiled_or_fn[0b01] == true);
    REQUIRE(compiled_or_fn[0b10] == true);
    REQUIRE(compiled_or_fn[0b11] == true);
  }

  WHEN("using a 2-bit nor_fn") {
    auto compiled_nor_fn =
        logic::compile<logic::default_storage>(&logic::nor_fn<2u>);

    REQUIRE(compiled_nor_fn.size() == 4);

    REQUIRE(compiled_nor_fn[0b00] == true);
    REQUIRE(compiled_nor_fn[0b01] == false);
    REQUIRE(compiled_nor_fn[0b10] == false);
    REQUIRE(compiled_nor_fn[0b11] == false);
  }

  WHEN("using a 2-bit popcount_fn") {
    auto compiled_popcount_fn =
        logic::compile<logic::default_storage>(&logic::popcount_fn<2u>);

    REQUIRE(compiled_popcount_fn.size() == 4);

    REQUIRE(compiled_popcount_fn[0b00] == 0u);
    REQUIRE(compiled_popcount_fn[0b01] == 1u);
    REQUIRE(compiled_popcount_fn[0b10] == 1u);
    REQUIRE(compiled_popcount_fn[0b11] == 2u);
  }
}
