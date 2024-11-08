cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(commonutils_test)
set(GITHOME_MSU_PRATT $ENV{GITHOME_MSU_PRATT})

add_custom_target(extern_msu_commonutils COMMAND make WORKING_DIRECTORY ${GITHOME_MSU_PRATT}/commonutils/software)

set(CMAKE_CXX_FLAGS "-W -Wall -march=native -std=c++17 -O2")
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(GSL REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(SYSTEM ${GSL_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR} ${GITHOME_MSU_PRATT}/commonutils/software/include)

link_directories(${GITHOME_MSU_PRATT}/commonutils/software/lib)

find_library(${GITHOME_MSU_PRATT}/commonutils/software/lib msu_commonutils)

set(SOURCE_FILES ./testutils.cc)

add_executable(testutils ${SOURCE_FILES})

add_dependencies(testutils extern_msu_commonutils)

find_library(${GITHOME_MSU_PRATT}/commonutils/software/lib msu_commonutils)

target_link_libraries(testutils msu_commonutils ${GITHOME_MSU_PRATT}/commonutils/software/lib/libmsu_commonutils.a ${GSL_LIBRARY} ${GSL_CBLAS_LIBRARY} ${EIGEN3_LIBRARY})
