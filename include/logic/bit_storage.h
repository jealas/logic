#pragma once

#include <xtl/type_traits.h>

#include <logic/bit_count.h>

namespace logic {

template <bit_count_t N, class = void> struct bit_storage {
  static_assert(N > 0, "Cannot use bit storage with 0 bits inside.");
  static_assert(N <= 64, "Cannot use bit storage with > 64 bits.");
};

template <bit_count_t N>
struct bit_storage<N, xtl::enable_if_t<(N > 0u and N <= 8u)>> {
  using type = uint8_t;
  static constexpr bit_count_t size_bits() { return N; };
  static constexpr bit_count_t capacity_bits() { return sizeof(type) * 8u; }
};

template <bit_count_t N>
struct bit_storage<N, xtl::enable_if_t<(N > 8u and N <= 16u)>> {
  using type = uint16_t;
  static constexpr bit_count_t size_bits() { return N; };
  static constexpr bit_count_t capacity_bits() { return sizeof(type) * 8u; }
};

template <bit_count_t N>
struct bit_storage<N, xtl::enable_if_t<(N > 16u and N <= 32u)>> {
  using type = uint32_t;
  static constexpr bit_count_t size_bits() { return N; };
  static constexpr bit_count_t capacity_bits() { return sizeof(type) * 8u; }
};

template <bit_count_t N>
struct bit_storage<N, xtl::enable_if_t<(N > 32u and N <= 64u)>> {
  using type = uint64_t;
  static constexpr bit_count_t size_bits() { return N; };
  static constexpr bit_count_t capacity_bits() { return sizeof(type) * 8u; }
};

template <bit_count_t N> using bits_storage_t = typename bit_storage<N>::type;

} // namespace logic
