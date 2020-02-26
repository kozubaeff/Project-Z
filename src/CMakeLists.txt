cmake_minimum_required( VERSION 2.8 )

## Required software
#find_package( <<<name>>> REQUIRED )

## Sources and headers
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

## Find all source files to be compiled into object files
file( GLOB SOURCES *.cc *.cpp )

## C++ compiler options
set( CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++17" )
set( CMAKE_CXX_FLAGS_DEBUG "-g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3" )

## Source files to be linked into the library
set( MAIN_SOURCES  )
## Specify a name for the generated executable file
set( MAIN_LIB_NAME TheGame )


## 1. Compile...
add_library( ${MAIN_LIB_NAME} ${MAIN_SOURCES}
                                 ${SOURCES}
              )

## 2. Link...
target_link_libraries( ${MAIN_LIB_NAME} )

