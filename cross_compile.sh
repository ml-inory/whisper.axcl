mkdir -p build_aarch64
cd build_aarch64
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain/aarch64-none-linux-gnu.toolchain.cmake -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_BUILD_TYPE=Release -DCROSS_COMPILE=ON ..
make -j8
make install