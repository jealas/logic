#include <catch.hpp>

TEST_CASE("Bit storage is correctly sized", "[logic][bit_storage]") {
  SECTION("when using between 1 and 8 bits") {
    REQUIRE(sizeof(logic::bits_storage_t<1>) == 1);
    REQUIRE(sizeof(logic::bits_storage_t<2>) == 1);
    REQUIRE(sizeof(logic::bits_storage_t<3>) == 1);
    REQUIRE(sizeof(logic::bits_storage_t<4>) == 1);
    REQUIRE(sizeof(logic::bits_storage_t<5>) == 1);
    REQUIRE(sizeof(logic::bits_storage_t<6>) == 1);
    REQUIRE(sizeof(logic::bits_storage_t<7>) == 1);
    REQUIRE(sizeof(logic::bits_storage_t<8>) == 1);
  }

  SECTION("when using between 9 and 16 bits") {
    REQUIRE(sizeof(logic::bits_storage_t<9>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<10>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<11>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<12>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<13>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<14>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<15>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<16>) == 2);
  }

  SECTION("when using between 17 and 32 bits") {
    REQUIRE(sizeof(logic::bits_storage_t<17>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<18>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<19>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<20>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<21>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<22>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<23>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<24>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<25>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<26>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<27>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<28>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<29>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<30>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<31>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<32>) == 2);
  }

  SECTION("when using between 33 and 64 bits") {
    REQUIRE(sizeof(logic::bits_storage_t<33>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<34>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<35>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<36>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<37>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<38>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<39>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<40>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<41>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<42>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<43>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<44>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<45>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<46>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<47>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<48>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<49>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<50>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<51>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<52>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<53>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<54>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<55>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<56>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<57>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<58>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<59>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<60>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<61>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<62>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<63>) == 2);
    REQUIRE(sizeof(logic::bits_storage_t<64>) == 2);
  }
}