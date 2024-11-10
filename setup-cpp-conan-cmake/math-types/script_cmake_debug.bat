call cmake -G "MinGW Makefiles"  -S . -B ./build/Debug -DCMAKE_BUILD_TYPE=Debug -DINSTALL_ROOT_DIR="C:/Workspace/CppDev/InHouseSoftware" -DBUILD_TESTS=TRUE
call cmake --build ./build/Debug
call cmake --install ./build/Debug