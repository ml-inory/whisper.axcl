cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(whisper)
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "-fvisibility=hidden -g -O0")
    add_definitions(-D__AX_SKEL_DEBUG__)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_CXX_FLAGS "-fvisibility=hidden -O2 -fdata-sections -ffunction-sections")
endif()

include(cmake/3rdparty.cmake)
include(cmake/options.cmake)

include_directories(${CMAKE_SOURCE_DIR}/src/)

aux_source_directory(${CMAKE_SOURCE_DIR}/src/middleware SRCS)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/utilities SRCS)

add_executable(${PROJECT_NAME} main.cpp ${SRCS})
target_link_libraries(${PROJECT_NAME} ${AXCL_LIBS} ${OPENCC_LIBS})

file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/opencc/share/opencc/t2s.json DESTINATION ${CMAKE_INSTALL_PREFIX})
file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/opencc/share/opencc/TSPhrases.ocd2 DESTINATION ${CMAKE_INSTALL_PREFIX})
file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/opencc/share/opencc/TSCharacters.ocd2 DESTINATION ${CMAKE_INSTALL_PREFIX})

install(TARGETS ${PROJECT_NAME}
        RUNTIME
            DESTINATION ./)
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    INSTALL_RPATH "$ORIGIN/../${AXCL_LIB_DIR}"
) 