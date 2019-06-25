#include <catch.hpp>

TEST_CASE("Bit storage is correctly sized", "[logic][bit_storage]") {
  SECTION("") {
    static_assert(sizeof(logic::bits_storage_t<1>) == 1);
    static_assert(sizeof(logic::bits_storage_t<2>) == 1);
    static_assert(sizeof(logic::bits_storage_t<3>) == 1);
    static_assert(sizeof(logic::bits_storage_t<4>) == 1);
    static_assert(sizeof(logic::bits_storage_t<5>) == 1);
    static_assert(sizeof(logic::bits_storage_t<6>) == 1);
    static_assert(sizeof(logic::bits_storage_t<7>) == 1);
    static_assert(sizeof(logic::bits_storage_t<8>) == 1);

    static_assert(sizeof(logic::bits_storage_t<9>) == 2);
    static_assert(sizeof(logic::bits_storage_t<10>) == 2);
    static_assert(sizeof(logic::bits_storage_t<11>) == 2);
    static_assert(sizeof(logic::bits_storage_t<12>) == 2);
    static_assert(sizeof(logic::bits_storage_t<13>) == 2);
    static_assert(sizeof(logic::bits_storage_t<14>) == 2);
    static_assert(sizeof(logic::bits_storage_t<15>) == 2);
    static_assert(sizeof(logic::bits_storage_t<16>) == 2);
  }
}