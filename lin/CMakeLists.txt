cmake_minimum_required(VERSION 3.24)

project(HJ)

set(CMAKE_CXX_STANDARD 11)
set(OpenCV_DIR "D:\\OpenCV\\4.5.5\\mingw-build")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS}
                     ${PROJECT_SOURCE_DIR}/include)

FILE(GLOB SRCS "${PROJECT_SOURCE_DIR}/src/*.cpp")
FILE(GLOB INCLUDES "${PROJECT_SOURCE_DIR}/include/*.h")

add_executable(HJ main.cpp ${SRCS} ${INCLUDES})

target_link_libraries(HJ ${OpenCV_LIBS})

