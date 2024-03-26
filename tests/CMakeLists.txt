# Add your test executable
add_executable(run_tests test_open.c)
target_link_libraries(run_tests logger)

# Enable testing with CTest
enable_testing()

# Add a test
add_test(NAME MyTest COMMAND run_tests)
