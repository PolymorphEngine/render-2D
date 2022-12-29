cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH ../)

project(render-2D)
set(NAMESPACE polymorph)

if (${CMAKE_SOURCE_DIR} EQUAL ${PROJECT_NAME})
    set(LIBRARY_OUTPUT_PATH  ../)
elseif(POLYMORPH_ENGINE_PLUGINS_CONFIG_PATH)
    set(LIBRARY_OUTPUT_PATH  ${POLYMORPH_ENGINE_PLUGINS_CONFIG_PATH}/plugins/${PROJECT_NAME})
else()
    set(LIBRARY_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/plugins/${PROJECT_NAME})
endif()

#set(CMAKE_MODULE /usr/bin/clang)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize-memory-track-origins -fsanitize=memory -fsanitize-recover=all -fPIE -pie -fno-omit-frame-pointer  -fno-optimize-sibling-calls -O1")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

include(cmake/FindPolymorphEngine.cmake)
include(cmake/FindRenderModules.cmake)

file(GLOB_RECURSE SCRIPTS_SRC scripts/src/*.cpp)
file(GLOB_RECURSE SCRIPTS_ICL scripts/include/*.hpp)

file(GLOB_RECURSE FACTORY_SRC factory/src/*.cpp)
file(GLOB_RECURSE FACTORY_ICL factory/include/*.hpp)

file(GLOB_RECURSE CORE_SRC core/src/*.cpp)
file(GLOB_RECURSE CORE_ICL core/include/*.hpp)
file(GLOB_RECURSE EXPORTS includeExport/*.hpp)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

get_target_property(render-modules-icls render-modules INCLUDE_DIRECTORIES)

add_library(${PROJECT_NAME} SHARED ${SCRIPTS_SRC} ${SCRIPTS_ICL} ${FACTORY_SRC} ${FACTORY_ICL} ${CORE_SRC} ${CORE_ICL} ${EXPORTS})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")
target_include_directories(${PROJECT_NAME} PRIVATE
        scripts/include
        factory/include
        core/include
)
target_include_directories(${PROJECT_NAME} PUBLIC
        includeExport
        ${render-modules-icls}
)

target_link_libraries(${PROJECT_NAME} PolymorphEngine)
set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

if(WIN32)
    # MSVC
    target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /W2 /c /Zc:preprocessor /wd5105)
    # Set the DLLEXPORT variable to export symbols
    target_compile_definitions(${PROJECT_NAME} PRIVATE WIN_EXPORT)
endif()

include(cmake/CopyConfig.cmake)