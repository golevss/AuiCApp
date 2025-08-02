# Standard routine
cmake_minimum_required(VERSION 3.24)
project(example_app
        VERSION 0.0.10 # CI_PROJECT_VERSION
)

option(BUILD_SHARED_LIBS "Build shared libs" OFF)
option(AUIB_FORCE_PRECOMPILED "AUI.Boot: force precompiled dependencies" OFF)

set(AUI_VERSION v7.0.1)

# Use AUI.Boot
file(
        DOWNLOAD
        https://raw.githubusercontent.com/aui-framework/aui/${AUI_VERSION}/aui.boot.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/aui.boot.cmake)
include(${CMAKE_CURRENT_BINARY_DIR}/aui.boot.cmake)

# import AUI
auib_import(aui https://github.com/aui-framework/aui
        COMPONENTS core views curl json crypt updater
        VERSION ${AUI_VERSION})


# Create the executable. This function automatically links all sources from the src/ folder,
# creates CMake target and places the resulting executable to bin/ folder.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
aui_executable(${PROJECT_NAME})
target_compile_definitions(example_app PRIVATE GLM_ENABLE_EXPERIMENTAL)

# Link required libs
aui_link(${PROJECT_NAME} PRIVATE aui::core aui::views aui::updater)

# Compile assets
aui_compile_assets(${PROJECT_NAME})

# Enable testing
aui_enable_tests(${PROJECT_NAME})

# Setup icon, display name, etc
aui_app(TARGET ${PROJECT_NAME}
        NAME "AUI App Example"
        VENDOR "AUI Project"
        ICON "assets/img/icon.svg"
)