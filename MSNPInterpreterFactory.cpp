#include "MSNPInterpreterFactory.h"

const IMSNPInterpreter* MSNPInterpreterFactory::getInterpreter(int MSNPVersion){
	auto test = _interpreters.at(MSNPVersion);
	return test;
}

const std::unordered_map<int, const IMSNPInterpreter*> MSNPInterpreterFactory::_interpreters = {
  { -1, new MSNPHandshake() },
  { 18, new MSNP18() }
};
