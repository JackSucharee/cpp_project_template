cmake_minimum_required( VERSION 3.30 FATAL_ERROR )

project( cpp LANGUAGES C CXX )

enable_language( C CXX )

add_subdirectory( cpp_00 )
add_subdirectory( cpp_01 )
add_subdirectory( cpp_02 )
add_subdirectory( cpp_03 )
add_subdirectory( tests )

set( includeDir ${CMAKE_SOURCE_DIR}/../include )

set( sourceDir ${CMAKE_SOURCE_DIR}/../src )

add_executable( ${PROJECT_NAME} )

add_custom_command( TARGET ${PROJECT_NAME}
    POST_BUILD COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/../include
        ${CMAKE_BINARY_DIR}/../include
)

target_sources( ${PROJECT_NAME}
    PRIVATE ${sourceDir}/main.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS ${includeDir}
)

target_link_libraries( ${PROJECT_NAME}
    INTERFACE
        cpp_00
    PRIVATE
        cpp_01
        cpp_02
        cpp_03
)

target_compile_features( ${PROJECT_NAME}
    PRIVATE
        cxx_std_23
)

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin/$<CONFIG>"
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

install( TARGETS ${PROJECT_NAME}
    CONFIGURATIONS Debug
    RUNTIME DESTINATION bin/Debug
)

install( TARGETS ${PROJECT_NAME}
    CONFIGURATIONS Release
    RUNTIME DESTINATION bin/Release
)

install( TARGETS ${PROJECT_NAME}
    CONFIGURATIONS RelDebWithInfo
    RUNTIME DESTINATION bin/RelDebWithInfo
)

