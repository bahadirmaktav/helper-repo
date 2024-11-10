call cmake -G "MinGW Makefiles"  -S . -B ./build/Release -DCMAKE_BUILD_TYPE=Release -DINSTALL_ROOT_DIR="C:/Workspace/CppDev/InHouseSoftware" -DBUILD_TESTS=TRUE
call cmake --build ./build/Release
call cmake --install ./build/Release