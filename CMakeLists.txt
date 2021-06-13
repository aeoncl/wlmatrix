cmake_minimum_required(VERSION 3.19)

project("WLMatrix")
set(CMAKE_CXX_STANDARD 20)
add_subdirectory(${PROJECT_NAME})
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_NAME}"\\bin")