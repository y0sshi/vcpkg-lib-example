cmake_minimum_required(VERSION 3.14)
set(TARGET vcpkg-lib-example)
project(${TARGET} VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()


add_library(${TARGET}
    src/example.cpp
    )

target_include_directories(${TARGET}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    )

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${TARGET} PUBLIC fmt::fmt)

# definition Windows DLL-Export Macto
if (BUILD_SHARED_LIBS)
    if (WIN32)
        add_definitions(-DVCPKG_LIB_EXAMPLE_EXPORTS)
    endif()
endif()

# version-info settings
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${TARGET}-config-version.cmake"
    VERSION       ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
    )

# create configure file
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/${TARGET}-config.cmake.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/${TARGET}-config.cmake"
    @ONLY
    )

# install settings
include(GNUInstallDirs)
install(
    TARGETS  ${TARGET}
    EXPORT   ${TARGET}-targets
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
install(
    DIRECTORY   include
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${TARGET}-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${TARGET}-config-version.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${TARGET}
    )


# ==================================================
# Test settings
# ==================================================
option(BUILD_TESTING "Build tests" OFF)
if (BUILD_TESTING)
    add_subdirectory(tests)
endif()

