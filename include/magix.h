#pragma once

#include <magic.h>
#include <stdexcept>
#include <string>

namespace magix {
    class magic {
        magic_t cookie;

        void error();
    public:
        magic(int flags);
        ~magic();

        std::string file(const std::string& filename);
    };

    struct magic_error : std::runtime_error {
        magic_error(const std::string& what_arg);
    };
}
