
#include "stdafx.h"
#include "teamoffenseaction.h"

using namespace soccer;
using namespace ai;


cTeamOffenseAction::cTeamOffenseAction(ai::iActorInterface<cTeam> *agent)
	: ai::cAction<cTeam>(agent, "TeamOffenseAction")
{
}

cTeamOffenseAction::~cTeamOffenseAction()
{
}


bool cTeamOffenseAction::ActionThrough(const float deltaSeconds)
{
	__super::ActionThrough(deltaSeconds);
	return true;
}


bool cTeamOffenseAction::ActionExecute(const float deltaSeconds)
{
	__super::ActionExecute(deltaSeconds);
	return true;
}


bool cTeamOffenseAction::MessageProccess(const ai::sMsg &msg)
{
	return __super::MessageProccess(msg);
}
