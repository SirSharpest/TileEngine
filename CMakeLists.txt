
cmake_minimum_required(VERSION 2.6)
project(SFML2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14  -Wall -Wextra -Werror -Wpedantic")


include_directories("${PROJECT_BINARY_DIR} src/headers")
include_directories("${YOUR_DIRECTORY} src")



# Define sources and executable
set(EXECUTABLE_NAME "SFML")

file(GLOB SRC
    "src/headers/*.hpp"
    "src/*.cpp"
)


add_executable(${EXECUTABLE_NAME} ${SRC})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
