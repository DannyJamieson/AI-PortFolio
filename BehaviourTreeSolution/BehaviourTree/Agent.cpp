#include "Agent.h"

Agent::Agent()
{
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("kettleVolume", new BlackboardFloatType(0)));
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("kettleTemp", new BlackboardIntType(10)));
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("kettleOn", new BlackboardBoolType(false)));
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("gotCup", new BlackboardBoolType(false)));
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("gotMilk", new BlackboardBoolType(false)));
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("gotTBag", new BlackboardBoolType(false)));
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("TBagInCup", new BlackboardBoolType(false)));
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("cupWaterVolume", new BlackboardFloatType(0)));
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("cupSugar", new BlackboardIntType(10)));
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("cupMilkVolume", new BlackboardFloatType(0)));

}


void Agent::update() {

}


