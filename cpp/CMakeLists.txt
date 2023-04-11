cmake_minimum_required(VERSION 3.20)

project(name)

include(shared/compile_options.cmake)
include(shared/compile_definitions.cmake)
include(shared/pch.cmake)

add_executable(name)

target_sources(name PRIVATE src/main.cpp)

target_compile_options(name PRIVATE ${COMPILE_OPTIONS})

target_compile_definitions(name PRIVATE ${COMPILE_DEFINITIONS})

target_precompile_headers(name PRIVATE ${PCH})

find_package(fmt CONFIG REQUIRED)

target_link_libraries(name PRIVATE fmt::fmt)

if(WIN32)
	set_target_properties(
		name
		PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
	)
endif()

if(NOT("${CMAKE_GENERATOR}" STRGREATER_EQUAL "Visual Studio"))
	add_custom_target(
		copy_compile_commands ALL
		${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/build
	)
endif()
