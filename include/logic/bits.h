#pragma once

#include <stddef.h>

#include <logic/bit_count.h>
#include <logic/bit_storage.h>

namespace logic {

template <bit_count_t> class bits;

template <> class bits<1u> {
  static constexpr bit_count_t N = 1u;

public:
  using storage_type = bits_storage_t<N>;

  template <bit_count_t StartBit, bit_count_t EndBit>
  static constexpr storage_type bit_mask() noexcept {
    static_assert(
        StartBit < N,
        "The start bit index must be less than the number of available bits.");
    static_assert(EndBit <= N, "The end bit index must be less or equal to the "
                               "number of available bits.");
    static_assert(StartBit < EndBit,
                  "Please provide a non-empty ascending range.");

    storage_type mask = 0u;

    for (auto i = StartBit; i < EndBit; ++i) {
      mask |= (1u << i);
    }

    return mask;
  }

  static constexpr bit_count_t num_bits() noexcept { return N; }

public:
  constexpr bits() : storage_{} {}
  constexpr bits(bool value)
      : storage_{static_cast<storage_type>(value ? 1u : 0u)} {}

  constexpr bits(const bits &b) : storage_{b.value()} {}

  constexpr bits &operator=(const bits &) noexcept = default;
  constexpr bits &operator=(bits &&) noexcept = default;

  constexpr bool operator==(const bits &other) const noexcept {
    return value() == other.value();
  }
  constexpr bool operator==(const storage_type &other) const noexcept {
    return value() == other;
  }

  constexpr bool operator!=(const bits &other) const noexcept {
    return !(*this == other);
  }
  constexpr bool operator!=(const storage_type &other) const noexcept {
    return !(*this == other);
  }

  constexpr storage_type value() const { return storage_; }
  constexpr explicit operator bool() const noexcept { return value(); }

  template <bit_count_t OtherN> constexpr bits<OtherN> as() {
    static_assert(
        OtherN <= N,
        "Cannot assign bits object that has more bits that destination type.");

    return {static_cast<typename bits<OtherN>::storage_type>(storage_)};
  }

  template <bit_count_t I> constexpr bool bit() const noexcept {
    constexpr auto mask = bit_mask<I, I + 1u>();
    return storage_ bitand mask;
  }

  template <bit_count_t StartBit, bit_count_t EndBit>
  constexpr bits<EndBit - StartBit> span() const noexcept {
    constexpr auto mask = bit_mask<StartBit, EndBit>();
    return (storage_ bitand mask) >> StartBit;
  }

  template <bit_count_t OtherN>
  constexpr bits<N + OtherN> cat(const bits<OtherN> other) const {
    return static_cast<typename bits<N + OtherN>::storage_type>(value()) |
           (other.value() << N);
  }

  constexpr bit_count_t count() const noexcept { return storage_ ? 1u : 0u; }
  constexpr bool test() const noexcept { return storage_; }

  constexpr bool none() const noexcept { return storage_ == 0u; }
  constexpr bool any() const noexcept { return not none(); }

  constexpr bool all() const noexcept { return storage_ == 1u; }

  constexpr bits operator xor(const bits &rhs) const noexcept {
    return storage_ xor rhs.storage_;
  }

  constexpr bits operator bitor(const bits &rhs) const noexcept {
    return *this or rhs;
  }

  constexpr bits operator bitand(const bits &rhs) const noexcept {
    return *this and rhs;
  }

  constexpr bits operator~() const noexcept { return not(*this); }

private:
  storage_type storage_;
};

template <bit_count_t N> class bits {
public:
  using storage_type = bits_storage_t<N>;

  template <bit_count_t StartBit, bit_count_t EndBit>
  static constexpr storage_type bit_mask() noexcept {
    static_assert(
        StartBit < N,
        "The start bit index must be less than the number of available bits.");
    static_assert(EndBit <= N, "The end bit index must be less or equal to the "
                               "number of available bits.");
    static_assert(StartBit < EndBit,
                  "Please provide a non-empty ascending range.");

    storage_type mask = 0u;

    for (auto i = StartBit; i < EndBit; ++i) {
      mask |= (1u << i);
    }

    return mask;
  }

  // Bitmask spanning the entire length of the bits (i.e. 10 bits has a bitmask
  // with 10 1-bits in it starting from the LSB).
  static constexpr storage_type storage_bitmask = bit_mask<0u, N>();
  static constexpr bit_count_t num_bits() noexcept { return N; }

public:
  constexpr bits() : storage_{} {}
  constexpr bits(const storage_type storage)
      : storage_{static_cast<storage_type>(storage & storage_bitmask)} {}

  constexpr bits(const bits &b) : storage_{b.value()} {}

  constexpr bits &operator=(const bits &b) noexcept = default;
  constexpr bits &operator=(bits &&b) noexcept = default;

  constexpr bool operator==(const bits &other) const noexcept {
    return value() == other.value();
  }
  constexpr bool operator==(const storage_type &other) const noexcept {
    return value() == other;
  }

  constexpr storage_type value() const noexcept { return storage_; }

  template <bit_count_t OtherN> constexpr bits<OtherN> as() {
    static_assert(
        OtherN <= N,
        "Cannot assign bits object that has more bits that destination type.");

    return {static_cast<typename bits<OtherN>::storage_type>(storage_)};
  }

  template <bit_count_t I> constexpr bits<1u> bit() const noexcept {
    return span<I, I + 1u>();
  }

  template <bit_count_t StartBit, bit_count_t EndBit>
  constexpr bits<EndBit - StartBit> span() const noexcept {
    constexpr auto mask = bit_mask<StartBit, EndBit>();
    return (storage_ bitand mask) >> StartBit;
  }

  template <bit_count_t OtherN>
  constexpr bits<N + OtherN> cat(const bits<OtherN> other) const {
    return static_cast<typename bits<N + OtherN>::storage_type>(value()) |
           (other.value() << N);
  }

  constexpr bit_count_t count() const noexcept {
    bit_count_t total = 0u;

    storage_type storage = storage_;

    while (storage) {
      if (storage & 1u) {
        ++total;
      }

      storage >>= 1u;
    }

    return total;
  }

  template <bit_count_t BitIndex> constexpr bool test() const noexcept {
    return bit<BitIndex>();
  }

  constexpr bool none() const noexcept { return storage_ == 0u; }
  constexpr bool any() const noexcept { return not none(); }

  constexpr bool all() const noexcept {
    return storage_ == (~storage_type{0u} & storage_bitmask);
  }

  constexpr bits operator xor(const bits &rhs) const noexcept {
    return storage_ xor rhs.storage_;
  }

  constexpr bits operator bitor(const bits &rhs) const noexcept {
    return storage_ bitor rhs.storage_;
  }

  constexpr bits operator bitand(const bits &rhs) const noexcept {
    return storage_ bitand rhs.storage_;
  }

  constexpr bits operator~() const noexcept { return ~storage_; }

private:
  storage_type storage_;
};

} // namespace logic
