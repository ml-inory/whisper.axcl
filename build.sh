mkdir -p build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain/aarch64-none-linux-gnu.toolchain.cmake ..
make -j8
make install