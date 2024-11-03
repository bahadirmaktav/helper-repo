:: 'conan install . --build=missing --settings=build_type=Release --profile=mingw' executing...
call conan install . --build=missing --settings=build_type=Release --profile=mingw
:: 'conan install . --build=missing --settings=build_type=Release --profile=mingw' done.

:: 'cmake --preset=conan-release' executing...
call cmake --preset=conan-release
:: 'cmake --preset=conan-release' done.

:: 'cmake --build --preset=conan-release' executing...
call cmake --build --preset=conan-release
:: 'cmake --build --preset=conan-release' done.

:: 'conan export-pkg . --profile=mingw' executing...
call conan export-pkg . --profile=mingw
:: 'conan export-pkg . --profile=mingw' done.