cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)

set(This bomberman)
project(${This})

#
# Set compile vars + Irrlicht module
#

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules")
find_package(Irrlicht REQUIRED)
if (UNIX)
	find_package(SFML 2.5 COMPONENTS audio REQUIRED)
endif()

#
# Add compile options for windows and linux
#

if (MSVC)
	add_compile_options(/W4)
#else()
#	add_compile_options(-W)
endif()

#
# INCLUDES
#

INCLUDE_DIRECTORIES(
	"${PROJECT_SOURCE_DIR}/inc"
	${Irrlicht_INCLUDE_DIRS}
	${Sfml_INCLUDE_DIRS}
)

#
# SOURCES
#	src/Saver/Saver_load.cpp
#	src/Saver/Saver_save.cpp
#	src/Saver/Saver.cpp
#

set(Sources
	src/Bomberman/Bomberman_getset.cpp
	src/Bomberman/Bomberman_run.cpp
	src/Bomberman/Bomberman.cpp
	src/Game/Bomb_animation.cpp
	src/Game/Bomb.cpp
	src/Game/Game_EL.cpp
	src/Game/Game_getset.cpp
	src/Game/Game.cpp
	src/Game/Map_get.cpp
	src/Game/Map_interns1.cpp
	src/Game/Map_interns2.cpp
	src/Game/Map_set.cpp
	src/Game/Map.cpp
	src/Game/Player_get.cpp
	src/Game/Player_set.cpp
	src/Game/Player.cpp
	src/LibManager/LibManager_get.cpp
	src/LibManager/LibManager.cpp
	src/Menu/Menu_DoAction.cpp
	src/Menu/Menu_draw.cpp
	src/Menu/Menu_EL.cpp
	src/Menu/Menu.cpp
	src/EventListener.cpp
	src/Exception.cpp
	src/Settings.cpp
	src/main.cpp
)

#
# Add format make command
#

add_custom_target(
        format
        COMMAND /usr/bin/clang-format
        -style=file
        -i
        ${Sources}
)

#
# Create program
#

add_executable(bomberman ${Sources})

#
# Set Irrlicht lib to link
#

target_link_libraries(bomberman ${Irrlicht_LIBRARIES})
if (UNIX)
	target_link_libraries(bomberman sfml-audio)
endif()

#
# Set build properties (for vs)
#

set_target_properties(
	bomberman PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}
	RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}
)

#
# If under windows, copy Irllicht.dll to root on post build
#

if (MSVC)
	add_custom_command(TARGET bomberman POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/modules/Irrlicht.dll ${PROJECT_SOURCE_DIR}
	)
endif()