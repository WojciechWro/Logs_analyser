cmake_minimum_required(VERSION 3.15...3.17)

if(${CMAKE_VERSION} VERSION_LESS 3.17)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Logs_analyser VERSION 3.0
		              DESCRIPTION "analyze incomminng data" LANGUAGES CXX)

enable_testing()
add_subdirectory(googletest-master)

add_subdirectory(tests)

set(HEADERS
	include/Observer.hpp include/Publisher.hpp
)

set(SOURCES
	sources/Observer.cpp sources/Publisher.cpp 
)

add_library(analyserLib ${HEADERS} ${SOURCES})
add_library(interfLib INTERFACE)

target_sources(interfLib INTERFACE ${PROJECT_SOURCE_DIR}/interface)

target_include_directories(analyserLib INTERFACE interfaces/)
target_include_directories(analyserLib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(program Main.cpp)

target_link_libraries(program PUBLIC analyserLib)
