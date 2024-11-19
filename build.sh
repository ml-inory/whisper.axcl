mkdir -p build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain/aarch64-none-linux-gnu.toolchain.cmake -DCMAKE_INSTALL_PREFIX=../install ..
make -j8
make install