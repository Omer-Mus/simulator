cmake_minimum_required(VERSION 3.21)
project(simulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(simulation main.cpp mass.cpp mass.h spring.cpp spring.h simulation.h)

set(GLEW_H /usr/local/Cellar/glew/2.1.0/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.2.1/include/GLFW)
include_directories(${GLEW_H} ${GLFW_H})

# Add target link
set(GLEW_LINK /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

# Execute compilation command
#set(SOURCE_FILES main.cpp cmake-build-debug/simulation.h)
#add_executable(helloworld ${SOURCE_FILES})
