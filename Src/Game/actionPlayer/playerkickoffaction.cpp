
#include "stdafx.h"
#include "playerkickoffaction.h"

using namespace ai;
using namespace soccer;


cPlayerKickoffAction::cPlayerKickoffAction(ai::iActorInterface<cPlayer> *agent)
	: ai::cAction<cPlayer>(agent, "playerkickoffaction")
{
	agent->m_ptr->m_data;

	ai::cMove<cPlayer> *p = new ai::cMove<cPlayer>(agent, Vector3(50, 0, 50), 5.f);
	PushAction(p);
}

cPlayerKickoffAction::~cPlayerKickoffAction()
{
}


bool cPlayerKickoffAction::ActionThrough(const float deltaSeconds)
{
	return true;
}


bool cPlayerKickoffAction::ActionExecute(const float deltaSeconds)
{
	return true;
}


bool cPlayerKickoffAction::MessageProccess(const ai::sMsg &msg)
{
	return __super::MessageProccess(msg);
}
