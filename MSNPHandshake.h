#pragma once
#include "IMSNPInterpreter.h"
class MSNPHandshake : public IMSNPInterpreter {
	public :
		std::string interpretMessage(std::string message) override;	
};

