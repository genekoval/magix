#include <magix/magix.h>

namespace magix {
    magic::magic(int flags) : cookie(magic_open(flags)) {
        if (magic_load(cookie, nullptr) != 0) error();
    }

    magic::~magic() { magic_close(cookie); }

    void magic::error() {
        const char* error_message = ::magic_error(cookie);
        if (error_message != nullptr) throw magic_error(error_message);
    }

    auto magic::buffer(std::span<const std::byte> buffer) -> std::string {
        const auto* description = magic_buffer(
            cookie,
            buffer.data(),
            buffer.size()
        );

        if (description == nullptr) error();
        return description;
    }

    auto magic::file(const std::string& filename) -> std::string {
        const char* description = magic_file(cookie, filename.c_str());
        if (description == nullptr) error();
        return description;
    }

    magic_error::magic_error(const std::string& what_arg) :
        std::runtime_error(what_arg)
    {}
}
