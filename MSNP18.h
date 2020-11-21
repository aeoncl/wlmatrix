#pragma once
#include "IMSNPInterpreter.h"
class MSNP18 : public IMSNPInterpreter
{
	public :
		std::string interpretMessage(std::string message) override;

};

