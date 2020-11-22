#pragma once
#include "IMSNPInterpreter.h"
class MSNPHandshake : public IMSNPInterpreter {
	public :
		MSNPHandshake();
		~MSNPHandshake();
		std::string interpretMessage(std::string message, MSNClient& client) const override;
};

