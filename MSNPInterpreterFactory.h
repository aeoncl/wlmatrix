#pragma once
#include <unordered_map>
#include "IMSNPInterpreter.h"
#include "MSNPHandshake.h"
#include "MSNP18.h"
class MSNPInterpreterFactory {
	private :
		std::unordered_map<int, IMSNPInterpreter> _interpreters{};
	public : 
		MSNPInterpreterFactory() {
			this->_interpreters.insert({ -1, MSNPHandshake() });
			this->_interpreters.insert({ 18, MSNP18() });
		};
		
		MSNPInterpreterFactory(const MSNPInterpreterFactory& obj) {
			this->_interpreters = obj._interpreters;
		}

		IMSNPInterpreter getInterpreter(int versionNumber) {
			return this->_interpreters.at(versionNumber);
		};
};

