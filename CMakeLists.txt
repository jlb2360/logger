cmake_minimum_required(VERSION 3.0)
project(logger)

# Add your source files
add_subdirectory(src)

# Add your test directory
add_subdirectory(tests)


# Add a custom target to run tests after building
add_custom_target(test
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS run_tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
