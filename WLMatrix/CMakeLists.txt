set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY VCPKG_TARGET_TRIPLET x86-windows)

set(LIBMATRIX_DIR src/libmatrix)
set(WLMATRIX_DIR src/wlmatrix)

add_subdirectory(data)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    ${WLMATRIX_DIR}/api/soap/AbstractMSNSoapService.cpp
    ${WLMATRIX_DIR}/api/soap/MSNSoapServer.cpp
    ${WLMATRIX_DIR}/api/soap/SoapEndpointHandlerFactory.cpp
    ${WLMATRIX_DIR}/api/soap/SoapEndpointHandlers.cpp
    ${WLMATRIX_DIR}/api/soap/SoapResponse.cpp

    ${WLMATRIX_DIR}/controllers/MainController.cpp

    ${WLMATRIX_DIR}/exceptions/SocketServerException.cpp

    ${WLMATRIX_DIR}/models/ClientInfo.cpp
    ${WLMATRIX_DIR}/models/WLMatrixLogin.cpp


    ${WLMATRIX_DIR}/models/commands/MSNPCommandHandlerFactory.cpp
    ${WLMATRIX_DIR}/models/commands/MSNPCommandHandlers.cpp
    ${WLMATRIX_DIR}/models/commands/MSNPCommandParser.cpp

    ${WLMATRIX_DIR}/models/soap/MSNCircle.cpp
    ${WLMATRIX_DIR}/models/soap/MSNContact.cpp
    ${WLMATRIX_DIR}/models/soap/MSNContactType.cpp
    ${WLMATRIX_DIR}/models/soap/MSNMember.cpp
    ${WLMATRIX_DIR}/models/soap/MSNMembershipList.cpp
    ${WLMATRIX_DIR}/models/soap/MSNMembershipListType.cpp
    ${WLMATRIX_DIR}/models/soap/MSNMembershipState.cpp

    ${WLMATRIX_DIR}/repositories/ClientInfoRepository.cpp

    ${WLMATRIX_DIR}/sockets/MSNClient.cpp
    ${WLMATRIX_DIR}/sockets/MSNSwitchboard.cpp
    ${WLMATRIX_DIR}/sockets/TCPServer.cpp
    ${WLMATRIX_DIR}/sockets/WinSockClientSocket.cpp
    ${WLMATRIX_DIR}/sockets/WinSockSocket.cpp

    ${WLMATRIX_DIR}/utils/CryptoUtils.cpp
    ${WLMATRIX_DIR}/utils/DateUtils.cpp
    ${WLMATRIX_DIR}/utils/MSNUtils.cpp
    ${WLMATRIX_DIR}/utils/StringUtils.cpp
    ${WLMATRIX_DIR}/utils/MacAddressUtils.cpp


    ${WLMATRIX_DIR}/utils/soap/MatrixToMSNSoap.cpp
    ${WLMATRIX_DIR}/utils/soap/MSNSoapMessages.cpp
    ${WLMATRIX_DIR}/utils/soap/MSNSoapToMatrix.cpp

    ${WLMATRIX_DIR}/utils/xml/pugixml.cpp

    ${LIBMATRIX_DIR}/api/rest/AuthResponse.cpp
    ${LIBMATRIX_DIR}/api/rest/MatrixBackend.cpp
    ${LIBMATRIX_DIR}/api/rest/MatrixErrorResponse.cpp
    ${LIBMATRIX_DIR}/api/rest/SyncResponse.cpp
    ${LIBMATRIX_DIR}/api/rest/WhoAmIResponse.cpp

    ${LIBMATRIX_DIR}/exceptions/MatrixRestServiceException.cpp

    ${LIBMATRIX_DIR}/models/MatrixAccountData.cpp
    ${LIBMATRIX_DIR}/models/MatrixCredentials.cpp
    ${LIBMATRIX_DIR}/models/MatrixInvitedRoom.cpp
    ${LIBMATRIX_DIR}/models/MatrixJoinedRoom.cpp
    ${LIBMATRIX_DIR}/models/MatrixLeftRoom.cpp
    ${LIBMATRIX_DIR}/models/MatrixPresence.cpp

    ${LIBMATRIX_DIR}/models/events/MatrixEvent.cpp
    )

    
MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    FILE(GLOB_RECURSE new_list2 *.hpp)
    LIST (APPEND new_list ${new_list2})
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(testHeaderFolders)

target_include_directories(${PROJECT_NAME} PUBLIC ${testHeaderFolders})

#target_include_directories(${PROJECT_NAME} PUBLIC include/boost)
#target_include_directories(${PROJECT_NAME} PUBLIC include/libmatrix)
#target_include_directories(${PROJECT_NAME} PUBLIC include)
#target_include_directories(${PROJECT_NAME} PUBLIC include/wlmatrix)

find_package(cpprestsdk REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE cpprestsdk::cpprest)

find_package(tinyxml2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE tinyxml2::tinyxml2)

find_package(magic_enum CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE magic_enum::magic_enum)

#Boost static libs
add_compile_definitions(BOOST_UUID_RANDOM_PROVIDER_FORCE_WINCRYPT)
set(Boost_INCLUDE_DIR ${_VCPKG_INSTALLED_DIR}/x86-windows-static/include) 
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS date_time)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif ()
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})

#source_group(TREE 