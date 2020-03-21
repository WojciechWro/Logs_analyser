cmake_minimum_required(VERSION 3.15...3.17)

if(${CMAKE_VERSION} VERSION_LESS 3.17)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(SOURCES 
	SourceTests.cpp SourceMocks.cpp
)

set(HEADERS 
	InterfaceMocks.hpp
)

add_executable(Logs_analyser_Test ${SOURCES} ${HEADERS})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/AccountsSummary_2020.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

target_link_libraries(Logs_analyser_Test PUBLIC
	gtest_main
	gmock_main
	analyserLib
)

add_test(
	NAME Logs_analyser_Test
	COMMAND Logs_analyser_Test
)