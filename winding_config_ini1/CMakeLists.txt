#set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_C_FLAGS "-g -Wall  -I E:\\MinGW\\include -L E:\\MinGW\\lib")
 
set(CMAKE_CXX_COMPILER "g++")#设置C++编译器
set(CMAKE_CXX_FLAGS "-g -Wall  -I E:\\MinGW\\include -L E:\\MinGW\\lib")

#set(OpenCV_DIR "G:\\opencv\\build\\x64\\vc15\\lib")
set(OpenCV_DIR "G:\\opencv\\build_mingw\\install\\x86\\mingw\\lib")

# Define project name
project(opencv_example)

#set(OpenCV_DIR "G:/opencv/build/x64/vc15/lib" libopencv_core.so libopencv_highgui.so #libopencv_videoio.so libopencv_imgcodecs.so)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

MESSAGE(STATUS "OpenCV_DIR: ${OpenCV_DIR}")
MESSAGE(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")
MESSAGE(STATUS "OpenCV_VERSION: ${OpenCV_VERSION}")
MESSAGE(STATUS "OpenCV_INSTALL_PATH: ${OpenCV_INSTALL_PATH}")
MESSAGE(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")

#set(OPENCV_INCLUDE_DIRS "G:/opencv/build/include")

# cmake needs this line
cmake_minimum_required(VERSION 2.8)

# Declare the executable target built from your sources
add_executable(example example.cpp)

# Link your application with OpenCV libraries
target_link_libraries(example ${OpenCV_LIBS})



