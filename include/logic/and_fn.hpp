#pragma once

#include "logic/bit_count.h"
#include "logic/bits.h"

namespace logic {

template <bit_count_t NumInputBits>
constexpr bits<1u> and_fn(const bits<NumInputBits> input_bits) {
  return input_bits.all();
}

} // namespace logic
