# cmdline
include_directories(3rdparty/cmdline/include)

# bsp
include_directories(3rdparty/libaxcl/bsp)

# libaxcl
include_directories(3rdparty/libaxcl/include)
set (AXCL_LIB_DIR 3rdparty/libaxcl/lib)
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

# opencc
include_directories(3rdparty/opencc/include)
link_directories(3rdparty/opencc/lib)
list (APPEND OPENCC_LIBS
opencc
marisa)