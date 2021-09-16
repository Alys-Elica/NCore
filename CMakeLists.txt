cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME NCore)

project(${PROJECT_NAME} LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED
  NCore/ncimage.cpp
  NCore/nclogs.cpp
  NCore/ncpoint.cpp
  NCore/ncrect.cpp
  NCore/ncrgb.cpp
  NCore/ncvector3d.cpp
  ncore.cpp

  NCore/nc2dmatrix.h
  NCore/ncimage.h
  NCore/nclogs.h
  NCore/ncpoint.h
  NCore/ncrect.h
  NCore/ncrgb.h
  NCore/ncvector3d.h
  ncore_global.h
  ncore.h
)

target_compile_definitions(${PROJECT_NAME} PRIVATE NCORE_LIBRARY)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
