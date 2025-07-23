cmake_minimum_required(VERSION 3.20)
project(ultra_low_latency_trading_sim
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable testing
include(CTest)
enable_testing()

# Add source files (update as needed)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Only create library if we have source files
if(SOURCES)
    add_library(ullts_lib ${SOURCES})
    target_include_directories(ullts_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
    
    # Main executable (optional, add main.cpp if it exists)
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
        add_executable(ullts src/main.cpp)
        target_link_libraries(ullts PRIVATE ullts_lib)
    endif()
else()
    message(STATUS "No source files found in src/ directory. Skipping library creation.")
    # Create a placeholder library for now
    add_library(ullts_lib INTERFACE)
    target_include_directories(ullts_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)
endif()

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Unit tests
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS tests/*.cpp)
if(TEST_SOURCES)
    add_executable(ullts_tests ${TEST_SOURCES})
    target_link_libraries(ullts_tests PRIVATE ullts_lib gtest_main)
    add_test(NAME AllTests COMMAND ullts_tests)
else()
    message(STATUS "No test files found in tests/ directory. Skipping test creation.")
endif()

# Doxygen
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/docs)
    set(DOXYGEN_INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
    set(DOXYGEN_PROJECT_NAME "Ultra Low Latency Trading Simulator")
    set(DOXYGEN_PROJECT_VERSION ${PROJECT_VERSION})
    
    # Configure Doxygen settings
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_XML NO)
    set(DOXYGEN_RECURSIVE YES)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_CLASS_DIAGRAMS YES)
    set(DOXYGEN_HIDE_UNDOC_RELATIONS NO)
    set(DOXYGEN_HAVE_DOT NO)
    set(DOXYGEN_CLASS_GRAPH YES)
    set(DOXYGEN_COLLABORATION_GRAPH YES)
    set(DOXYGEN_UML_LOOK NO)
    set(DOXYGEN_UML_LIMIT_NUM_FIELDS 50)
    set(DOXYGEN_TEMPLATE_RELATIONS YES)
    set(DOXYGEN_DOT_GRAPH_MAX_NODES 100)
    set(DOXYGEN_MAX_DOT_GRAPH_DEPTH 0)
    set(DOXYGEN_DOT_TRANSPARENT NO)
    
    doxygen_add_docs(doc
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
    )
endif()