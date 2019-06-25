#include <iostream>

#include <logic/bit_storage.h>
#include <logic/bits.h>

int main() {
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

  logic::bits<1> bit_true{1};
  logic::bits<1> bit_off{0};

  std::cout << "Hello, World!" << std::endl;
  return 0;
}