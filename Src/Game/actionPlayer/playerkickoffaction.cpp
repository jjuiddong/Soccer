
#include "stdafx.h"
#include "playerkickoffaction.h"

using namespace ai;
using namespace soccer;


cPlayerKickoffAction::cPlayerKickoffAction(ai::iActorInterface<cPlayer> *agent)
	: ai::cAction<cPlayer>(agent, "PlayerKickoffAction")
{
	Vector2 dest = agent->m_ptr->m_data.location;

	ai::cMove<cPlayer> *p = new ai::cMove<cPlayer>(agent, Vector3(dest.x, 0, dest.y), 10.f);
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
	return false;
}


bool cPlayerKickoffAction::MessageProccess(const ai::sMsg &msg)
{
	return __super::MessageProccess(msg);
}
