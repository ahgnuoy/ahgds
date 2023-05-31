cmake_minimum_required(VERSION 3.0.0)
project(dspg VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB SOURCE_FILES "src/*.c" "src/*.h" "src/pages/*.c" "src/pages/*.h")

add_executable(dspg ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
