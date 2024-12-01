# cmdline
include_directories(3rdparty/cmdline/include)

# bsp
include_directories(3rdparty/libaxcl/bsp)

# libaxcl
if (CROSS_COMPILE)
    include_directories(${CMAKE_SOURCE_DIR}/3rdparty/libaxcl/include)
    set (AXCL_LIB_DIR ${CMAKE_SOURCE_DIR}/3rdparty/libaxcl/lib)
else()
    include_directories(/usr/include/axcl)
    set (AXCL_LIB_DIR /usr/lib/axcl)
endif()
link_directories (${AXCL_LIB_DIR})
list (APPEND AXCL_LIBS 
axcl_rt
axcl_pkg
axcl_comm
axcl_npu
spdlog
axcl_token
axcl_pcie_msg
axcl_pcie_dma)

# audiofile
include_directories(3rdparty/audiofile)

# librosa
include_directories(3rdparty/librosa)
