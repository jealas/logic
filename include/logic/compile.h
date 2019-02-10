#pragma once

#include <logic/bits.h>
#include <logic/bit_count.h>


namespace logic {
    namespace detail {
        template <bit_count_t N>
        constexpr bit_count_t num_possible_outputs() {
            bit_count_t num_inputs = 1u;

            for (auto i = 0u; i < N; ++i) {
                num_inputs *= 2;
            }

            return num_inputs;
        }
    }

    template <bit_count_t OutputN, bit_count_t InputN>
    using logic_function = bits<OutputN>(*)(bits<InputN> input_bits);

    template <template <class, size_t> class OutputStorage, bit_count_t OutputN, bit_count_t InputN>
    constexpr auto compile(logic_function<OutputN, InputN> function) {
        constexpr auto NumPossibleOutputs = detail::num_possible_outputs<InputN>();

        OutputStorage<bits<OutputN>, NumPossibleOutputs> output_bits;

        for (auto i = 0u; i < NumPossibleOutputs; ++i) {
            output_bits[i] = function(i);
        }

        return output_bits;
    }
}
