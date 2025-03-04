cmake_minimum_required(VERSION 3.7)
project(ecs)

# gen
add_executable(
    gen 
    gen.cpp
)

add_custom_command(
    COMMAND gen
    DEPENDS gen
    OUTPUT input_data.cpp input_data.hpp 
)

set_target_properties(
    gen
    PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

# input_data
add_library(
    input_data 
    OBJECT 
        input_data.cpp
        input_data.hpp
)

set_target_properties(
    input_data
    PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_include_directories(
    input_data
    PUBLIC
        ${CMAKE_BINARY_DIR}
)

# filter_function_select_gen
add_executable(
    filter_function_select_gen 
    main.cpp
)

target_link_libraries(
    filter_function_select_gen 
    input_data
)

set_target_properties(
    filter_function_select_gen
    PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

