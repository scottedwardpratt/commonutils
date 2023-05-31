cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(commonutils_test)
set(GITHOME_MSU $ENV{GITHOME_MSU})

add_custom_target(extern_msu_commonutils COMMAND make WORKING_DIRECTORY ${GITHOME_MSU}/commonutils/software)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -std=c++11")
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(GSL 1.15 REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(SYSTEM ${GSL_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR} ${GITHOME_MSU}/commonutils/software/include)

link_directories(${GITHOME_MSU}/commonutils/software/lib)

find_library(${GITHOME_MSU}/commonutils/software/lib msu_commonutils)

set(SOURCE_FILES ./testutils.cc)

add_executable(testutils ${SOURCE_FILES})

add_dependencies(testutils extern_msu_commonutils)

find_library(${GITHOME_MSU}/commonutils/software/lib msu_commonutils)

target_link_libraries(testutils msu_commonutils ${GSL_LIBRARY} ${GSL_CBLAS_LIBRARY} ${EIGEN3_LIBRARY})
