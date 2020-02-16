#include <magix.h>

#include <iostream>

int main(int argc, char** argv) {
    magix::magic magic(MAGIC_MIME_TYPE);

    if (argc == 1) return EXIT_SUCCESS;

    std::cout << magic.file(argv[1]) << std::endl;
}
