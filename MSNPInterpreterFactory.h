#pragma once
#include <unordered_map>
#include "IMSNPInterpreter.h"
#include "MSNPHandshake.h"
#include "MSNP18.h"
class MSNPInterpreterFactory {
	private :
		const static std::unordered_map<int, const IMSNPInterpreter*> _interpreters;
	public : 
		const static IMSNPInterpreter* getInterpreter(int MSNPVersion);
};

