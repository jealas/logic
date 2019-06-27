#pragma once

#include "logic/bit_count.h"
#include "logic/bits.h"

namespace logic {

namespace detail {
template <bit_count_t NumInputBits>
constexpr bit_count_t num_popcount_output_bits() noexcept {
  bit_count_t msb_index = 0u;

  bit_count_t current_index = 0u;

  while (current_index < NumInputBits) {
    if (NumInputBits bitand (1u << current_index)) {
      msb_index = current_index;
    }

    ++current_index;
  }

  return msb_index + 1u;
}

} // namespace detail

template <bit_count_t NumInputBits>
constexpr bits<detail::num_popcount_output_bits<NumInputBits>()>
popcount_fn(const bits<NumInputBits> input_bits) noexcept {
  static_assert(NumInputBits > 0);

  return input_bits.count();
}

}