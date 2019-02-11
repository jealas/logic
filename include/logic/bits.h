#pragma once

#include <stddef.h>

#include <logic/bit_storage.h>
#include <logic/bit_count.h>


namespace logic {
    template <bit_count_t N, class Storage = bits_storage_t<N>>
    class bits {
    public:
        using storage_type = Storage;

        template <bit_count_t StartBit, bit_count_t EndBit>
        static constexpr storage_type bit_mask() noexcept {
            static_assert(StartBit < N, "The start bit index must be less than the number of available bits.");
            static_assert(EndBit <= N, "The end bit index must be less or equal to the number of available bits.");
            static_assert(StartBit < EndBit, "Please provide a non-empty ascending range.");

            storage_type mask = 0u;

            for (auto i = StartBit; i < EndBit; ++i) {
                mask |= (1 << i);
            }

            return mask;
        }

        static constexpr bit_count_t num_bits() noexcept { return N; }

    public:
        constexpr bits() : storage_{} {}

        constexpr bits(const storage_type storage) : storage_{storage} {}

        template <bit_count_t OtherN>
        constexpr bits(const bits<OtherN> &b) : storage_{static_cast<storage_type>(b.value())} {
            static_assert(OtherN <= N, "Cannot assign bits object that has more bits that destination type.");
        }

        template <bit_count_t OtherN>
        constexpr bits& operator=(const bits<OtherN> &b) const noexcept = delete;

        template <bit_count_t OtherN>
        constexpr bits& operator=(bits<OtherN> &&b) const noexcept = delete;

        constexpr bool operator==(const bits<N> &other) const noexcept { return value() == other.value(); }
        constexpr bool operator==(const storage_type &other) const noexcept { return value() == other; }

        constexpr storage_type value() const { return storage_; }

        template <bit_count_t I>
        constexpr bool bit() const noexcept {
            constexpr auto mask = bit_mask<I, I+1>();
            return storage_ bitand mask;
        }

        template <bit_count_t StartBit, bit_count_t EndBit>
        constexpr bits<EndBit-StartBit> bit_span() const noexcept {
            constexpr auto mask = bit_mask<StartBit, EndBit>();
            return (storage_ bitand mask) >> StartBit;
        }

        template <bit_count_t OtherN>
        constexpr bits<N + OtherN> cat(const bits<OtherN> other) const {
            return static_cast<typename bits<N + OtherN>::storage_type>(value()) | (other.value() << N);
        }

    private:
        storage_type storage_;
    };

    template <class Storage>
    class bits<1u, Storage> {
        static constexpr bit_count_t N  = 1;

    public:
        using storage_type = Storage;

        template <bit_count_t StartBit, bit_count_t EndBit>
        static constexpr storage_type bit_mask() noexcept {
            static_assert(StartBit < N, "The start bit index must be less than the number of available bits.");
            static_assert(EndBit <= N, "The end bit index must be less or equal to the number of available bits.");
            static_assert(StartBit < EndBit, "Please provide a non-empty ascending range.");

            storage_type mask = 0u;

            for (auto i = StartBit; i < EndBit; ++i) {
                mask |= (1 << i);
            }

            return mask;
        }

        static constexpr bit_count_t num_bits() noexcept { return N; }

    public:
        constexpr bits() : storage_{} {}

        constexpr bits(bool value) : storage_{static_cast<storage_type>(value ? 1u : 0u)} {}

        template <bit_count_t OtherN>
        constexpr bits(const bits<OtherN> &b) : storage_{static_cast<storage_type>(b.value())} {
            static_assert(OtherN <= N, "Cannot assign bits object that has more bits that destination type.");
        }

        template <bit_count_t OtherN>
        constexpr bits& operator=(const bits<OtherN> &b) const noexcept = delete;

        template <bit_count_t OtherN>
        constexpr bits& operator=(bits<OtherN> &&b) const noexcept = delete;

        constexpr bool operator==(const bits<N> &other) const noexcept { return value() == other.value(); }
        constexpr bool operator==(const storage_type &other) const noexcept { return value() == other; }

        constexpr storage_type value() const { return storage_; }

        constexpr explicit operator bool() const noexcept { return value(); }

        template <bit_count_t I>
        constexpr bool bit() const noexcept {
            constexpr auto mask = bit_mask<I, I+1>();
            return storage_ bitand mask;
        }

        template <bit_count_t StartBit, bit_count_t EndBit>
        constexpr bits<EndBit-StartBit> bit_span() const noexcept {
            constexpr auto mask = bit_mask<StartBit, EndBit>();
            return (storage_ bitand mask) >> StartBit;
        }

        template <bit_count_t OtherN>
        constexpr bits<N + OtherN> cat(const bits<OtherN> other) const {
            return static_cast<typename bits<N + OtherN>::storage_type>(value()) | (other.value() << N);
        }

    private:
        storage_type storage_;
    };
}
