#pragma once
#include <string>
#include <vector>
#include "MatrixRoom.h"
#include "MatrixPresence.h"
#include "AccountData.h"
class SyncResponse {
    private : 
        std::string _nextBatch;
        AccountData _accountData;
        std::vector<MatrixRoom> _joinedRooms;
        std::vector<MatrixRoom> _invitedRooms;
        std::vector<MatrixRoom> _leftRooms;
        MatrixPresence _presence;
    public : 
        void setNextBatch(std::string nextBatch){
            _nextBatch = nextBatch;
        }
        void setAccountData(AccountData data){
            _accountData = data;
        }
        void setJoinedRooms();
        void setInvitedRooms();
        void setLeftRooms();
        void setPresence(MatrixPresence presence){
            _presence = presence;
        }
        static SyncResponse deserializeJson(std::string json);
};