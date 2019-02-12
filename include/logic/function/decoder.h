#pragma once

#include <logic/bit_count.h>
#include <logic/bits.h>

namespace logic {
    namespace function {
        namespace detail {
            constexpr bit_count_t calculate_output_bits(bit_count_t input_bits) noexcept { return 1u << input_bits; }
        }

        template <bit_count_t InputN>
        constexpr bits<detail::calculate_output_bits(InputN)> decoder(bits<InputN> input_bits) noexcept {
            return 1u << input_bits.value();
        }
    }
}