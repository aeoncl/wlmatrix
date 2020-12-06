#pragma once
#include <string>
#include <vector>
#include "MatrixJoinedRoom.h"
#include "MatrixInvitedRoom.h"
#include "MatrixLeftRoom.h"

#include "MatrixPresence.h"
#include "MatrixAccountData.h"

class SyncResponse {
    private : 
        std::string _nextBatch;
        MatrixAccountData _accountData;
        std::vector<MatrixJoinedRoom> _joinedRooms;
        std::vector<MatrixInvitedRoom> _invitedRooms;
        std::vector<MatrixLeftRoom> _leftRooms;
        MatrixPresence _presence;
    public : 
        void setNextBatch(std::string nextBatch){
            _nextBatch = nextBatch;
        }
        void setAccountData(MatrixAccountData data){
            _accountData = data;
        }
        void setJoinedRooms();
        void setInvitedRooms();
        void setLeftRooms();
        void setPresence(MatrixPresence presence){
            _presence = presence;
        }

        void addJoinedRoom(MatrixJoinedRoom joinedRoom){
            _joinedRooms.push_back(joinedRoom);
        }

        void addInvitedRoom(MatrixInvitedRoom invitedRoom){
            _invitedRooms.push_back(invitedRoom);
        }

        void addInvitedRoom(MatrixLeftRoom leftRoom){
            _leftRooms.push_back(leftRoom);
        }

        std::vector<MatrixJoinedRoom> getJoinedRooms(){
            return _joinedRooms;
        }

        std::unordered_map<std::string, std::any> getDirectList();

        bool isRoomDirect(std::string roomId);
        
        static SyncResponse deserializeJson(std::string json);
};