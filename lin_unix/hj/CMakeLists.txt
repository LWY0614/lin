cmake_minimum_required(VERSION 3.10)
project(hj_v)

set(CMAKE_CXX_STANDARD 11)
if(UNIX)
   set(CAM_LIB /lib/libMVSDK.so)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
   set(OpenCV_DIR /home/lin/opencv/build)
elseif(WIN32)
    set(CAM_LIB E:/MindVision/SDK/X64/MVCAMSDK_X64.lib)
    set(OpenCV_DIR E:/opencv-4.5.4/opencv/build/x64/vc16/install/x64/vc16/lib)
endif()


find_package(OpenCV 4.5 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(X11 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/include)

FILE(GLOB SRCS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(hj_v main.cpp ${SRCS})
add_subdirectory(fmt EXCLUDE_FROM_ALL)
add_definitions(-std=c++11)


target_link_libraries(hj_v ${OpenCV_LIBS} ${CAM_LIB} ${fmt_LIB} ${X11_LIBRARIES})
target_link_libraries(hj_v fmt-header-only)


message(STATUS "camera_libs:${CAM_LIB}")
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
#message(STATUS "    libraries: ${OpenCV_DIR}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

message(STATUS "Eigen3 library status:")
message(STATUS "    version: ${Eigen3_VERSION}")
#message(STATUS "    libraries: ${Eigen3_DIR}")
message(STATUS "    include path: ${EIGEN3_INCLUDE_DIRS}")


