set( includeDir ${CMAKE_CURRENT_SOURCE_DIR}/../../include )

set( sourceDir ${CMAKE_CURRENT_SOURCE_DIR}/../../src )

list( APPEND headerFiles
    ${includeDir}/cpp_00.h
)

set( currentProject "cpp_00" )

add_library( ${currentProject} INTERFACE )

target_sources( ${currentProject}
    INTERFACE FILE_SET HEADERS
    BASE_DIRS ${includeDir}
    FILES ${headerFiles}
)

target_compile_features( ${currentProject}
    INTERFACE
        cxx_std_23
)

set_target_properties( ${currentProject}
    PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

install( TARGETS ${currentProject}
    FILE_SET HEADERS
)
