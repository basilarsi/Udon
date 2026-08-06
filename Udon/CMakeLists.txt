add_library(Udon SHARED src/Pch.cpp
    src/Graphics/Vertex.cpp
    src/Math/FPoint2D.cpp
    src/Math/FPoint3D.cpp
    src/Graphics/Color.cpp
    src/Math/FPoint4D.cpp
    src/Math/Point4D.cpp
    src/Math/Point3D.cpp
    src/Math/Point2D.cpp
    src/SDL.cpp
    src/Core/Window.cpp
    src/Core/Logger.cpp)

add_subdirectory(vendor/sdl)
add_subdirectory(vendor/spdlog)

target_include_directories(Udon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_precompile_headers(Udon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Udon/Pch.hpp)

target_compile_definitions(Udon PUBLIC UDON_BUILD)

find_package(Vulkan REQUIRED)

target_link_libraries(Udon PUBLIC Vulkan::Vulkan)
target_link_libraries(Udon PUBLIC SDL3::SDL3)
target_link_libraries(Udon PUBLIC spdlog::spdlog)