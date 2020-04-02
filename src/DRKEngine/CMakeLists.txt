set(CMAKE_CXX_STANDARD 20)

set(LIBRARY_OUTPUT_PATH ${PROJECT_NAME})
add_library(${LIBRARY_OUTPUT_PATH} SHARED
        DRKEngine.h
        window.cpp window.h
        render_loop.cpp render_loop.h objects/primitives.h shader.cpp shader.h filesystem.cpp filesystem.h objects/primitives.cpp)
set_target_properties(${LIBRARY_OUTPUT_PATH} PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION})
target_link_libraries(${LIBRARY_OUTPUT_PATH} GL glfw GLEW)
