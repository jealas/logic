#pragma once

#include <stddef.h>


namespace logic {
    template <class BitStorage, size_t NumOutputs>
    class default_storage {
    public:
        using bit_storage_t = BitStorage;

        static constexpr size_t size() noexcept { return NumOutputs; }

        constexpr BitStorage &operator[](const size_t i) noexcept { return storage_[i]; }
        constexpr const BitStorage &operator[](const size_t i) const noexcept { return storage_[i]; }

        constexpr BitStorage const * begin() const noexcept { return &storage_; }
        constexpr BitStorage const * end() const noexcept { return &storage_[NumOutputs]; }

    private:
        BitStorage storage_[NumOutputs];
    };
}