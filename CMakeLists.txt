cmake_minimum_required(VERSION 2.6)
project(app)
add_executable(app main.c)

find_package(OpenGL REQUIRED)
if (NOT OpenGL_FOUND)
    message(ERROR "OPENGL NOT FOUND!")
endif(NOT OpenGL_FOUND)

find_package(GLUT REQUIRED)
if (NOT GLUT_FOUND)
    message(ERROR "GLUT NOT FOUND!")
endif(NOT GLUT_FOUND)

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )
target_link_libraries(app ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )