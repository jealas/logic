#pragma once

#include "logic/and_fn.hpp"
#include "logic/bit_count.h"
#include "logic/bits.h"

namespace logic {

template <bit_count_t NumInputBits>
constexpr bits<1u> nand_fn(const bits<NumInputBits> input_bits) {
  return not and_fn<NumInputBits>(input_bits);
}

} // namespace logic
