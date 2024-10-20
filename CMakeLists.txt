cmake_minimum_required(VERSION 3.26)

include(cmake/modules.cmake)
include(GitVersion)

project(magix
    VERSION ${GIT_VERSION_ABBREV}
    DESCRIPTION "C++ wrapper for libmagic"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)

include(packages.cmake)

add_library(magix "")
add_library(magix::magix ALIAS magix)

target_sources(magix PUBLIC FILE_SET HEADERS BASE_DIRS include)
target_include_directories(magix PUBLIC ${MAGIC_INCLUDE_DIRS})
target_link_libraries(magix PRIVATE ${MAGIC_LIBRARIES})

add_subdirectory(include)
add_subdirectory(src)

include(Sanitizers)
enable_asan()

include(EasyInstall)
easy_install(TARGETS magix)

if(PROJECT_IS_TOP_LEVEL)
    add_custom_target(docker
        docker build --progress=plain --no-cache .
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
        USES_TERMINAL
    )
endif()
