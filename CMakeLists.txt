cmake_minimum_required(VERSION 3.9)
FUNCTION(PREPEND var prefix)
   SET(listVar "")
   FOREACH(f ${ARGN})
      LIST(APPEND listVar "${prefix}/${f}")
   ENDFOREACH(f)
   SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(NAME "Tic-tac-toe")

set(SDIR "Sources")
set(SOURCES)

set(MAIN_SDIR "Main")
set(MAIN_SOURCES
	"Engine.class.Coplien.cpp"
	"main.cpp")
PREPEND(MAIN_SOURCES_REL ${MAIN_SDIR} ${MAIN_SOURCES})
set(SOURCES ${SOURCES} ${MAIN_SOURCES_REL})

PREPEND(SOURCES_REL ${SDIR} ${SOURCES})

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Werror -Wextra")
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")

include_directories(${CMAKE_SOURCE_DIR}/Includes)
add_executable(${NAME} ${SOURCES_REL})