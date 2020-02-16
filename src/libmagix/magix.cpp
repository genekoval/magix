#include <magix.h>

namespace magix {
    magic::magic(int flags) : cookie(magic_open(flags)) {
        if (magic_load(cookie, NULL) != 0) error();
    }

    magic::~magic() { magic_close(cookie); }

    void magic::error() {
        const char* error_message = ::magic_error(cookie);
        if (error_message != NULL) throw magic_error(error_message);
    }

    std::string magic::file(const std::string& filename) {
        const char* description = magic_file(cookie, filename.c_str());
        if (description == NULL) error();
        return description;
    }

    magic_error::magic_error(const std::string& what_arg) :
        std::runtime_error(what_arg)
    {}
}
