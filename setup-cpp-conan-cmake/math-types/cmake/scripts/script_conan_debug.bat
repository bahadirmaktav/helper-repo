call conan install . --build=missing --settings=build_type=Debug --profile=mingw
call cmake --preset=conan-debug
call cmake --build --preset=conan-debug
call conan export-pkg . --settings=build_type=Debug --profile=mingw