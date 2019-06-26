#include <catch.hpp>

#include <logic/compile.h>
#include <logic/default_storage.h>

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
