cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(whisper)
set(CMAKE_CXX_STANDARD 17)

include(cmake/3rdparty.cmake)
include(cmake/options.cmake)

include_directories(${CMAKE_SOURCE_DIR}/src/)

aux_source_directory(${CMAKE_SOURCE_DIR}/src/middleware SRCS)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/utilities SRCS)

add_executable(${PROJECT_NAME} main.cpp ${SRCS})
target_link_libraries(${PROJECT_NAME} ${AXCL_LIBS} ${OPENCC_LIBS})

install(TARGETS ${PROJECT_NAME}
        RUNTIME
            DESTINATION ./)
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    INSTALL_RPATH "$ORIGIN/../${AXCL_LIB_DIR}"
) 