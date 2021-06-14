#pragma once
#include <string>
#include <vector>
#include "MatrixJoinedRoom.h"
#include "MatrixInvitedRoom.h"
#include "MatrixLeftRoom.h"

#include "MatrixPresence.h"
#include "MatrixAccountData.h"

class SyncResponse
{
private:
    std::string _nextBatch;
    MatrixAccountData _accountData;
    std::vector<MatrixJoinedRoom> _joinedRooms;
    std::vector<MatrixInvitedRoom> _invitedRooms;
    std::vector<MatrixLeftRoom> _leftRooms;
    MatrixPresence _presence;

public:
    void setNextBatch(std::string nextBatch);
    void setAccountData(MatrixAccountData data);

    void setPresence(MatrixPresence presence);

    void addJoinedRoom(MatrixJoinedRoom joinedRoom);
    void addInvitedRoom(MatrixInvitedRoom invitedRoom);

    void addInvitedRoom(MatrixLeftRoom leftRoom);

    std::vector<MatrixJoinedRoom> getJoinedRooms();

    std::unordered_map<std::string, std::any> getDirectList();

    bool isRoomDirect(std::string roomId);

    std::string getDirectBuddy(std::string roomId);

    static SyncResponse deserializeJson(std::string json);
};