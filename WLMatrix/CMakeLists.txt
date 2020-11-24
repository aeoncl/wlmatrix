set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY VCPKG_TARGET_TRIPLET x86-windows)

set(CONTROLLERS_DIR src/Controllers)
set(MODELS_DIR src/Models)
set(REPO_DIR src/Repositories)
set(SOCKETS_DIR src/Sockets)
set(UTILS_DIR src/Utils)
set(EXCEPTIONS_DIR src/Exceptions)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    ${CONTROLLERS_DIR}/MainController.cpp
    ${EXCEPTIONS_DIR}/SocketServerException.cpp
    ${MODELS_DIR}/MSNClient.cpp
    ${MODELS_DIR}/MSNPCommand.cpp
    ${MODELS_DIR}/MSNPCommandHandlerFactory.cpp
    ${MODELS_DIR}/MSNPCommandHandlers.cpp
    ${MODELS_DIR}/MSNSwitchboard.cpp
    ${REPO_DIR}/ClientInfoRepository.cpp
    ${SOCKETS_DIR}/TCPServer.cpp
    ${SOCKETS_DIR}/WinSockClientSocket.cpp
    ${SOCKETS_DIR}/WinSockSocket.cpp
    ${UTILS_DIR}/CryptoUtils.cpp
    ${UTILS_DIR}/StringUtils.cpp
    )

target_include_directories(${PROJECT_NAME} PUBLIC include/wlmatrix)
find_package(cpprestsdk REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE cpprestsdk::cpprest)
#source_group(TREE src PREFIX [FILES <src>...])
source_group("Header Files" FILES ${INCLUDE_DIRECTORIES})
set_directory_properties(PROPERTIES VS_STARTUP_PROJECT MSNeo)