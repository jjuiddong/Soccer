
#include "stdafx.h"
#include "blankaction.h"

using namespace ai;
using namespace soccer;


cBlankAction::cBlankAction(ai::iActorInterface<cPlayer> *agent)
	: ai::cAction<cPlayer>(agent, "blankaction")
{
}

cBlankAction::~cBlankAction()
{
}


bool cBlankAction::ActionThrough(const float deltaSeconds)
{
	return true;
}


bool cBlankAction::ActionExecute(const float deltaSeconds)
{
	return true;
}


bool cBlankAction::MessageProccess(const ai::sMsg &msg)
{
	return __super::MessageProccess(msg);
}

