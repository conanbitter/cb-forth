cmake_minimum_required(VERSION 3.16)

project(cbforth VERSION 0.1 LANGUAGES C)

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

set(INCLUDE_FILES
    common.h
    core.h
    io.h
)

set(SRC_FILES
    main.c
    core.c
    dict.c
    io.c
)

list(TRANSFORM INCLUDE_FILES PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/include/)
list(TRANSFORM SRC_FILES PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/src/)

add_executable(cbforth ${INCLUDE_FILES} ${SRC_FILES})
target_include_directories(cbforth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
