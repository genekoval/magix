#pragma once

#include <magic.h>
#include <span>
#include <stdexcept>
#include <string>

namespace magix {
    class magic {
        magic_t cookie;

        void error();
    public:
        magic(int flags);
        ~magic();

        auto buffer(std::span<const std::byte> buffer) -> std::string;
        auto file(const std::string& filename) -> std::string;
    };

    struct magic_error : std::runtime_error {
        magic_error(const std::string& what_arg);
    };
}
