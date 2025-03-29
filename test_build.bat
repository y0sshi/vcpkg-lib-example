@echo off

set VCPKG_TOOLCHAIN=%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake
set SOURCE_DIR=.
set BUILD_DIR=build
set CONFIG=Release
set BUILD_TESTING=ON

:: create build env
cmake -S %SOURCE_DIR% -B %BUILD_DIR% -D CMAKE_TOOLCHAIN_FILE=%VCPKG_TOOLCHAIN% -D BUILD_TESTING=%BUILD_TESTING%

:: build
cmake --build %BUILD_DIR% --config %CONFIG%

