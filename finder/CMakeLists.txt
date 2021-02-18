include_directories(${CMAKE_SOURCE_DIR}/utils/include)
file(GLOB UTILS_SRC ${CMAKE_SOURCE_DIR}/utils/src/*.cpp)
add_library(utils SHARED ${UTILS_SRC})