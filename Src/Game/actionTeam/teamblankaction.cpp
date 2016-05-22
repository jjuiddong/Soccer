
#include "stdafx.h"
#include "teamblankaction.h"

using namespace soccer;
using namespace ai;


cTeamBlankAction::cTeamBlankAction(ai::iActorInterface<cTeam> *agent)
	: ai::cAction<cTeam>(agent, "TeamBlankAciton")
{
}

cTeamBlankAction::~cTeamBlankAction()
{
}


bool cTeamBlankAction::ActionThrough(const float deltaSeconds)
{
	__super::ActionThrough(deltaSeconds);
	return true;
}


bool cTeamBlankAction::ActionExecute(const float deltaSeconds)
{
	__super::ActionExecute(deltaSeconds);
	return true;
}


bool cTeamBlankAction::MessageProccess(const ai::sMsg &msg)
{
	return __super::MessageProccess(msg);
}
