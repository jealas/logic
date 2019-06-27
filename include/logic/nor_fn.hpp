#pragma once

#include "logic/bit_count.h"
#include "logic/bits.h"
#include "logic/or_fn.hpp"

namespace logic {

template <bit_count_t NumInputBits>
constexpr bits<1u> nor_fn(const bits<NumInputBits> input_bits) {
  return not or_fn<NumInputBits>(input_bits);
}

} // namespace logic
