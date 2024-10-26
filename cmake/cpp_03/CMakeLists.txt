set( includeDir ${CMAKE_CURRENT_SOURCE_DIR}/../../include )

set( sourceDir ${CMAKE_CURRENT_SOURCE_DIR}/../../src )

list( APPEND headerFiles
    ${includeDir}/cpp_03.h
)

list( APPEND sourceFiles
    ${sourceDir}/cpp_03.cpp
)

set( currentProject "cpp_03" )

add_library( ${currentProject} )

target_sources( ${currentProject}
    PRIVATE ${sourceFiles}
    PUBLIC FILE_SET HEADERS
    BASE_DIRS ${includeDir}
    FILES ${headerFiles}
)

target_compile_features( ${currentProject}
    PUBLIC
        cxx_std_23
)

set_target_properties( ${currentProject}
    PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib/$<CONFIG>"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib/$<CONFIG>"
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

install( TARGETS ${currentProject}
    CONFIGURATIONS Debug
    RUNTIME DESTINATION bin/Debug
    LIBRARY DESTINATION lib/Debug
    ARCHIVE DESTINATION lib/Debug
)

install( TARGETS ${currentProject}
    CONFIGURATIONS Release
    RUNTIME DESTINATION bin/Release
    LIBRARY DESTINATION lib/Release
    ARCHIVE DESTINATION lib/Release
)

install( TARGETS ${currentProject}
    CONFIGURATIONS RelDebWithInfo
    RUNTIME DESTINATION bin/RelDebWithInfo
    LIBRARY DESTINATION lib/RelDebWithInfo
    ARCHIVE DESTINATION lib/RelDebWithInfo
)
