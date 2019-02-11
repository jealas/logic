#pragma once

#include <xtl/array.h>

#include <logic/bits.h>
#include <logic/bit_count.h>


namespace logic {
    template <bit_count_t OutputN, bit_count_t... InputNs>
    using logic_function = bits<OutputN>(*)(bits<InputNs>...input_bits);

    namespace detail {
        template <bit_count_t... Ns>
        constexpr bit_count_t sum() {
            bit_count_t sizes[] = {Ns...};

            bit_count_t sum = 0;

            for (const auto s : sizes) {
                sum += s;
            }

            return sum;
        }

        constexpr bit_count_t num_possible_outputs(const bit_count_t num_inputs) { return (1u << num_inputs); }

        template <bit_count_t... InputNs>
        constexpr auto compute_bit_offsets() noexcept {
            xtl::array<bit_count_t, sizeof...(InputNs)>offsets{} ;
            xtl::array<bit_count_t, offsets.size()>bit_counts{InputNs...} ;

            for (auto i = 0u; i < sizeof...(InputNs)-1; ++i) {
                offsets[1u + i] = offsets[i] + bit_counts[i];
            }

            return offsets;
        }

        template <bit_count_t OutputN, bit_count_t... InputNs, size_t... Indexes>
        constexpr auto invoke_function(logic_function<OutputN, InputNs...> function, const bits<detail::sum<InputNs...>()> input_bits, xtl::index_sequence<Indexes...>) {
            constexpr auto bit_start_offsets = detail::compute_bit_offsets<InputNs...>();
            constexpr xtl::array<bit_count_t, bit_start_offsets.size()> bit_lengths{InputNs...};

            return function(input_bits.template bit_span<xtl::get<Indexes>(bit_start_offsets), xtl::get<Indexes>(bit_start_offsets) + xtl::get<Indexes>(bit_lengths)>()...);

        }
    }

    template <template <class, size_t> class OutputStorage, bit_count_t OutputN, bit_count_t... InputNs>
    constexpr auto compile(logic_function<OutputN, InputNs...> function) {
        constexpr auto NumInputs = detail::sum<InputNs...>();
        constexpr auto NumPossibleOutputs = detail::num_possible_outputs(NumInputs);

        OutputStorage<bits<OutputN>, NumPossibleOutputs> output_bits;

        for (auto i = 0u; i < NumPossibleOutputs; ++i) {
            output_bits[i] = detail::invoke_function(function, i, xtl::make_index_sequence<sizeof...(InputNs)>());
        }

        return output_bits;
    }
}
