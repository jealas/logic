include_directories(
        "${CMAKE_SOURCE_DIR}/libs/Catch2/single_include/catch2"
)

add_executable(test_logic
        test_logic_main.cpp
        test_bit_storage.cpp
        test_bits.cpp
        test_compile.cpp
        test_decoder.cpp
)
