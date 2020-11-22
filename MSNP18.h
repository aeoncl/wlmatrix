#pragma once
#include "IMSNPInterpreter.h"

class MSNP18 : public IMSNPInterpreter
{
	public :
		MSNP18();
		~MSNP18();
		std::string interpretMessage(std::string message, MSNClient& client) const override;
};

