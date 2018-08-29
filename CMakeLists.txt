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
	"Engine.class.Base.cpp"
	"Engine.class.CheckWin.cpp"
	"AI.class.Base.cpp"
	"main.cpp")
PREPEND(MAIN_SOURCES_REL ${MAIN_SDIR} ${MAIN_SOURCES})
set(SOURCES ${SOURCES} ${MAIN_SOURCES_REL})


set(VIEW_SDIR "Views")
set(VIEW_SOURCES
	"GameView.class.cpp"
	"StartMenuView.class.cpp"
	"GameMenuView.class.cpp"
	"ChangeOutputModeView.class.cpp"
	"GameOverView.class.cpp")
PREPEND(VIEW_SOURCES_REL ${VIEW_SDIR} ${VIEW_SOURCES})
set(SOURCES ${SOURCES} ${VIEW_SOURCES_REL})


set(CONSOLE_IO_SDIR "IO/ConsoleIO")
set(CONSOLE_IO_SOURCES
	"ConsoleIO.class.Coplien.cpp"
	"ConsoleIO.class.Base.cpp"
	"ConsoleIO.class.Display.cpp")
PREPEND(CONSOLE_IO_SOURCES_REL ${CONSOLE_IO_SDIR} ${CONSOLE_IO_SOURCES})
set(SOURCES ${SOURCES} ${CONSOLE_IO_SOURCES_REL})


set(NCURSES_IO_SDIR "IO/ncursesIO")
set(NCURSES_IO_SOURCES
	"ncursesIO.class.Coplien.cpp"
	"ncursesIO.class.Base.cpp"
	"ncursesIO.class.Display.cpp")
PREPEND(NCURSES_IO_SOURCES_REL ${NCURSES_IO_SDIR} ${NCURSES_IO_SOURCES})
set(SOURCES ${SOURCES} ${NCURSES_IO_SOURCES_REL})


set(AIO_FACTORY_SDIR "IO/AIOFactory")
set(AIO_FACTORY_SOURCES
	"AIOFactory.class.Coplien.cpp"
	"AIOFactory.class.cpp")
PREPEND(AIO_FACTORY_SOURCES_REL ${AIO_FACTORY_SDIR} ${AIO_FACTORY_SOURCES})
set(SOURCES ${SOURCES} ${AIO_FACTORY_SOURCES_REL})


PREPEND(SOURCES_REL ${SDIR} ${SOURCES})


set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Werror -Wextra")
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")


include_directories(${CMAKE_SOURCE_DIR}/Includes)
add_executable(${NAME} ${SOURCES_REL})


find_package(Curses REQUIRED)
target_link_libraries(${NAME} ${CURSES_LIBRARIES})
