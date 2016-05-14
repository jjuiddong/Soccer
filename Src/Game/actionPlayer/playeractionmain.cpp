
#include "stdafx.h"
#include "playeractionmain.h"
#include "playerkickoffaction.h"

using namespace ai;
using namespace soccer;


cPlayerActionMain::cPlayerActionMain(ai::iActorInterface<cPlayer> *agent)
	: ai::cAction<cPlayer>(agent, "PlayerActionMain")
{
}

cPlayerActionMain::~cPlayerActionMain()
{
}


bool cPlayerActionMain::ActionThrough(const float deltaSeconds)
{
	return true;
}


bool cPlayerActionMain::ActionExecute(const float deltaSeconds)
{
	
	return true;
}


bool cPlayerActionMain::MessageProccess(const ai::sMsg &msg)
{
	switch (msg.msg)
	{
	case PLAYER_AI_MSG::KICKOFF:
	{
 		cPlayerKickoffAction *p = new cPlayerKickoffAction(m_agent);
 		PushAction(p);
	}
	break;

	default:
		break;
	}

	return __super::MessageProccess(msg);
}
