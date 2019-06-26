#include <catch.hpp>

#include <logic/bit_storage.h>

SCENARIO("Bit storage is correctly sized", "[logic][bit_storage]") {
  WHEN("using between 1 and 8 bits") {
    THEN("the bit storage size is 1 byte") {
      REQUIRE(sizeof(logic::bits_storage_t<1>) == 1);
      REQUIRE(sizeof(logic::bits_storage_t<2>) == 1);
      REQUIRE(sizeof(logic::bits_storage_t<3>) == 1);
      REQUIRE(sizeof(logic::bits_storage_t<4>) == 1);
      REQUIRE(sizeof(logic::bits_storage_t<5>) == 1);
      REQUIRE(sizeof(logic::bits_storage_t<6>) == 1);
      REQUIRE(sizeof(logic::bits_storage_t<7>) == 1);
      REQUIRE(sizeof(logic::bits_storage_t<8>) == 1);
    }
  }

  WHEN("using between 9 and 16 bits") {
    THEN("the bit storage size is 2 bytes") {
      REQUIRE(sizeof(logic::bits_storage_t<9>) == 2);
      REQUIRE(sizeof(logic::bits_storage_t<10>) == 2);
      REQUIRE(sizeof(logic::bits_storage_t<11>) == 2);
      REQUIRE(sizeof(logic::bits_storage_t<12>) == 2);
      REQUIRE(sizeof(logic::bits_storage_t<13>) == 2);
      REQUIRE(sizeof(logic::bits_storage_t<14>) == 2);
      REQUIRE(sizeof(logic::bits_storage_t<15>) == 2);
      REQUIRE(sizeof(logic::bits_storage_t<16>) == 2);
    }
  }

  WHEN("using between 17 and 32 bits") {
    THEN("the bit storage size is 4 bytes") {
      REQUIRE(sizeof(logic::bits_storage_t<17>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<18>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<19>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<20>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<21>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<22>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<23>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<24>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<25>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<26>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<27>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<28>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<29>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<30>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<31>) == 4);
      REQUIRE(sizeof(logic::bits_storage_t<32>) == 4);
    }
  }

  SECTION("using between 33 and 64 bits") {
    THEN("the bit storage size is 8") {
      REQUIRE(sizeof(logic::bits_storage_t<33>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<34>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<35>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<36>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<37>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<38>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<39>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<40>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<41>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<42>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<43>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<44>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<45>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<46>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<47>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<48>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<49>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<50>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<51>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<52>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<53>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<54>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<55>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<56>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<57>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<58>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<59>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<60>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<61>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<62>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<63>) == 8);
      REQUIRE(sizeof(logic::bits_storage_t<64>) == 8);
    }
  }
}