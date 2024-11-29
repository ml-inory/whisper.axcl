cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(whisper)
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "-fvisibility=hidden -g -O0")
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

include(ExternalProject)
set(OPENCC_INSTALL_DIR ${CMAKE_SOURCE_DIR}/3rdparty/opencc/${CMAKE_SYSTEM_PROCESSOR})
ExternalProject_Add(opencc_local
    GIT_REPOSITORY "https://github.com/ml-inory/OpenCC.git"
    GIT_TAG "axera"
    SOURCE_DIR ${CMAKE_BINARY_DIR}/opencc-local
    BINARY_DIR ${CMAKE_BINARY_DIR}/opencc-build-local
    CMAKE_ARGS
        -DBUILD_DATA=ON
        -DBUILD_SHARED_LIBS=OFF
        -DCMAKE_INSTALL_PREFIX=${OPENCC_INSTALL_DIR}/../local
)

ExternalProject_Add(opencc
    GIT_REPOSITORY "https://github.com/ml-inory/OpenCC.git"
    GIT_TAG "axera"
    SOURCE_DIR ${CMAKE_BINARY_DIR}/opencc
    BINARY_DIR ${CMAKE_BINARY_DIR}/opencc-build-${CMAKE_SYSTEM_PROCESSOR}
    CMAKE_ARGS
        -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
        -DBUILD_SHARED_LIBS=OFF
        -DCMAKE_INSTALL_PREFIX=${OPENCC_INSTALL_DIR}
)

include_directories(${OPENCC_INSTALL_DIR}/include)

add_dependencies(${PROJECT_NAME} opencc_local)
add_dependencies(${PROJECT_NAME} opencc)
target_link_libraries(${PROJECT_NAME} ${OPENCC_INSTALL_DIR}/lib/libopencc.a)
target_link_libraries(${PROJECT_NAME} ${OPENCC_INSTALL_DIR}/lib/libmarisa.a)

add_custom_command(TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND "cp ${OPENCC_INSTALL_DIR}/../local/share/opencc/t2s.json ${CMAKE_SOURCE_DIR}/"
    COMMAND "cp ${OPENCC_INSTALL_DIR}/../local/share/opencc/TSPhrases.ocd2 ${CMAKE_SOURCE_DIR}/"
    COMMAND "cp ${OPENCC_INSTALL_DIR}/../local/share/opencc/TSCharacters.ocd2 ${CMAKE_SOURCE_DIR}/"
)

install(TARGETS ${PROJECT_NAME}
        RUNTIME
            DESTINATION ./)