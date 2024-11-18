call conan install . --build=missing --settings=build_type=Release --profile=mingw
call cmake --preset=conan-release
call cmake --build --preset=conan-release
call conan export-pkg . --settings=build_type=Release --profile=mingw