# Add all source files in the src directory
file(GLOB SOURCES "*.c")

# Create a library target
add_library(logger STATIC ${SOURCES})

# Include the headers in the include directory
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
