
#include "stdafx.h"
#include "playerformationmoveaction.h"

using namespace ai;
using namespace soccer;


cPlayerFormationMoveAction::cPlayerFormationMoveAction(ai::iActorInterface<cPlayer> *agent)
	: ai::cAction<cPlayer>(agent, "PlayerFormationMoveAction")
{
}

cPlayerFormationMoveAction::~cPlayerFormationMoveAction()
{
}


bool cPlayerFormationMoveAction::ActionThrough(const float deltaSeconds)
{
	return true;
}


bool cPlayerFormationMoveAction::ActionExecute(const float deltaSeconds)
{
	return true;
}


bool cPlayerFormationMoveAction::MessageProccess(const ai::sMsg &msg)
{
	return __super::MessageProccess(msg);
}
