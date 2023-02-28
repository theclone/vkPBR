# CMakeList.txt : CMake project for vkPBR, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("vkPBR")

find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)
find_package(Vulkan REQUIRED)

# Add source to this project's executable.
add_executable (vkPBR "vkPBR.cpp" "vkPBR.h" "WindowManager.cpp" "WindowManager.h")

include_directories(vkPBR ${SDL_INCLUDE_DIRS})
include_directories(vkPBR ${GLM_INCLUDE_DIRS})
include_directories(vkPBR ${Vulkan_INCLUDE_DIRS})

target_link_libraries(vkPBR ${SDL2_LIBRARIES})

# TODO: Add tests and install targets if needed.
