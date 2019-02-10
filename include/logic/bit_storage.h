#pragma once

#include <xtl/type_traits.h>

#include <logic/bit_count.h>

namespace logic {
    template <bit_count_t N, class = void>
    struct bit_storage {
        static_assert(N > 0, "Cannot use bit storage with 0 bits inside.");
        static_assert(N <= 64, "Cannot use bit storage with > 64 bits.");
    };

    template <bit_count_t N>
    struct bit_storage<N, xtl::enable_if_t<(N > 0 and N <= 8)>> {
        using type = uint8_t;
    };

    template <bit_count_t N>
    struct bit_storage<N, xtl::enable_if_t<(N > 8 and N <= 16)>> {
        using type = uint16_t;
    };

    template <bit_count_t N>
    struct bit_storage<N, xtl::enable_if_t<(N > 16 and N <= 32)>> {
        using type = uint32_t;
    };

    template <bit_count_t N>
    struct bit_storage<N, xtl::enable_if_t<(N > 32 and N <= 64)>> {
        using type = uint64_t;
    };

    template <bit_count_t N>
    using bits_storage_t = typename bit_storage<N>::type;
}