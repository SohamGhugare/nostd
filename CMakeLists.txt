cmake_minimum_required(VERSION 3.10)

project(nostd-dev C)

add_executable(nostd-dev 
    main.c

    # write call
    syscalls/write.c
    syscalls/exit.c
)

# nostd compilation
target_compile_options(nostd-dev PRIVATE -nostdlib -fno-builtin -Wall -Wextra)
target_link_options(nostd-dev PRIVATE -nostdlib -fno-builtin)
target_link_options(nostd-dev PRIVATE -e _start)

set_target_properties(nostd-dev PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
)