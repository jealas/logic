#pragma once

#include "logic/bit_count.h"
#include "logic/bits.h"

namespace logic {

template <bit_count_t NumInputBits>
constexpr bits<1u> or_fn(const bits<NumInputBits> input_bits) {
  return input_bits.any();
}

} // namespace logic
