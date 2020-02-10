cmake_minimum_required(VERSION "3.16.2")

project("Atomics_example")

file(GLOB SOURCE "*.cpp")

add_executable("${PROJECT_NAME}" ${SOURCE})

install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #${CMAKE_INSTALL_PREFIX}/bin
install(FILES "Source.cpp" DESTINATION src)        #${CMAKE_INSTALL_PREFIX}/src

