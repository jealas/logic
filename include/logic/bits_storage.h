#pragma once

#include <stddef.h>

#include <xtl/type_traits.h>


namespace logic {
    template <size_t N, class = void>
    struct bits_storage {
        static_assert(N > 0, "Cannot use bit storage with 0 bits inside.");
        static_assert(N <= 64, "Cannot use bit storage with > 64 bits.");
    };

    template <size_t N>
    struct bits_storage<N, xtl::enable_if_t<(N > 0 and N <= 8)>> {
        using type = uint8_t;
    };

    template <size_t N>
    struct bits_storage<N, xtl::enable_if_t<(N > 8 and N <= 16)>> {
        using type = uint16_t;
    };

    template <size_t N>
    struct bits_storage<N, xtl::enable_if_t<(N > 16 and N <= 32)>> {
        using type = uint32_t;
    };

    template <size_t N>
    struct bits_storage<N, xtl::enable_if_t<(N > 32 and N <= 64)>> {
        using type = uint64_t;
    };

    template <size_t N>
    using bits_storage_t = typename bits_storage<N>::type;
}