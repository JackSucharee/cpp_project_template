include( FetchContent )

# ============================================================
# External: google/googletest -> Unit Test framework
# ============================================================
FetchContent_Declare( googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG b514bdc # v1.15.2 : 2024-07-31
    EXCLUDE_FROM_ALL
    SYSTEM
)
set( gtest_force_shared_crt_ ON CACHE BOOL "" FORCE )
FetchContent_MakeAvailable( googletest )

enable_testing()
include( GoogleTest )

# ============================================================
# External: google/benchmark -> Benchmark framework
# ============================================================
set( BENCHMARK_ENABLE_TESTING OFF )
set( BENCHMARK_ENABLE_INSTALL OFF )
set( BENCHMARK_INSTALL_DOCS OFF )
FetchContent_Declare( benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG 12235e2 # v1.9.0 : 2024-08-16
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable( benchmark )

# ============================================================
# External: CLIUtils/CLI11 -> Argument Parser library
# ============================================================
FetchContent_Declare( cli11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG 6c7b07a # v2.4.2 : 2024-05-04
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable( cli11 )

# ============================================================
# cpp Tests -> ProjectTemplate Test 
# ============================================================
set( includeDir ${CMAKE_CURRENT_SOURCE_DIR}/../../include )

set( sourceDir ${CMAKE_CURRENT_SOURCE_DIR}/../../tests )

list( APPEND sourceFiles
    ${sourceDir}/test_cpp_01.cpp
)

set( currentProject "cpp_tests" )

add_executable( ${currentProject} )

target_sources( ${currentProject}
    PRIVATE ${sourceFiles}
    PUBLIC FILE_SET HEADERS
    BASE_DIRS ${includeDir}
)

target_link_libraries( ${currentProject}
    INTERFACE
        cpp_00
    PRIVATE
        GTest::gtest
        GTest::gtest_main
        benchmark::benchmark
        CLI11::CLI11
        cpp_01
        cpp_02
        cpp_03
)

target_compile_features( ${currentProject}
    PUBLIC
        cxx_std_23
)

set_target_properties( ${currentProject}
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin/$<CONFIG>"
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

install( TARGETS ${currentProject}
    CONFIGURATIONS Debug
    RUNTIME DESTINATION tests/Debug
)

install( TARGETS ${currentProject}
    CONFIGURATIONS Release
    RUNTIME DESTINATION tests/Release
)

install( TARGETS ${currentProject}
    CONFIGURATIONS RelDebWithInfo
    RUNTIME DESTINATION tests/RelDebWithInfo
)
