set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY VCPKG_TARGET_TRIPLET x86-windows)

set(CONTROLLERS_DIR src/Controllers)
set(MODELS_DIR src/Models)
set(MATRIX_DIR ${MODELS_DIR}/Matrix)
set(MSN_DIR ${MODELS_DIR}/MSN)
set(REPO_DIR src/Repositories)
set(SOCKETS_DIR src/Sockets)
set(UTILS_DIR src/Utils)
set(EXCEPTIONS_DIR src/Exceptions)
set(XML_DIR src/XML)


add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    ${CONTROLLERS_DIR}/MainController.cpp
    ${EXCEPTIONS_DIR}/SocketServerException.cpp
    ${MODELS_DIR}/ClientInfo.cpp
    ${MSN_DIR}/MSNClient.cpp
    ${MSN_DIR}/MSNPCommand.cpp
    ${MSN_DIR}/MSNPCommandHandlerFactory.cpp
    ${MSN_DIR}/MSNPCommandHandlers.cpp
    ${MSN_DIR}/MSNSoapServer.cpp
    ${MSN_DIR}/MSNSwitchboard.cpp
    ${MSN_DIR}/MSNPCommandParser.cpp
    ${MATRIX_DIR}/MatrixBackend.cpp
    ${MATRIX_DIR}/MatrixCredentials.cpp
    ${MATRIX_DIR}/AuthResponse.cpp
    ${REPO_DIR}/ClientInfoRepository.cpp
    ${SOCKETS_DIR}/TCPServer.cpp
    ${SOCKETS_DIR}/WinSockClientSocket.cpp
    ${SOCKETS_DIR}/WinSockSocket.cpp
    ${UTILS_DIR}/CryptoUtils.cpp
    ${UTILS_DIR}/StringUtils.cpp
    ${XML_DIR}/pugixml.cpp
    )

target_include_directories(${PROJECT_NAME} PUBLIC include/wlmatrix)
target_include_directories(${PROJECT_NAME} PUBLIC include/libmatrix)
target_include_directories(${PROJECT_NAME} PUBLIC include)


find_package(cpprestsdk REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE cpprestsdk::cpprest)
#source_group(TREE src PREFIX [FILES <src>...])
source_group("Header Files" FILES ${INCLUDE_DIRECTORIES})
set_directory_properties(PROPERTIES VS_STARTUP_PROJECT MSNeo)