#pragma once

#include <logic/bit_count.h>
#include <logic/bits.h>

namespace logic::function {

template <bit_count_t NumBits>
constexpr bit_count_t num_possible_outputs() noexcept {
  static_assert(
      NumBits > 0 and NumBits <= 6,
      "Decoders only support 2-64 output bits, so only 1-6 input bits.");

  return static_cast<bit_count_t>(1u) << NumBits;
}

template <bit_count_t NumInputBits>
constexpr bits<(1u << NumInputBits)>
decoder(bits<NumInputBits> input_bits) {
  return 1u << input_bits.value();
}

} // namespace logic::function
