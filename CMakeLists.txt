cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
project(mcmc)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/config)

find_package(BoostSrc)

enable_testing()
include(CTest)
include(add_diff_test)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${Boost_ROOT_DIR})

add_subdirectory(integration)
