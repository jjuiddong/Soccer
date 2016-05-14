
#include "stdafx.h"
#include "teamkickoffaction.h"

using namespace soccer;
using namespace ai;


cTeamKickoffAction::cTeamKickoffAction(ai::iActorInterface<cTeam> *agent)
	: ai::cAction<cTeam>(agent, "TeamKickoffAction")
{
}

cTeamKickoffAction::~cTeamKickoffAction()
{
}


bool cTeamKickoffAction::ActionThrough(const float deltaSeconds)
{
	__super::ActionThrough(deltaSeconds);

	return true;
}


bool cTeamKickoffAction::ActionExecute(const float deltaSeconds)
{
	__super::ActionExecute(deltaSeconds);

	// 팀원들에게 킥오프 메세지를 보낸다.
	sMsg msg;
	msg.msg = PLAYER_AI_MSG::KICKOFF;
	m_agent->m_ptr->DispatchMessage(msg);

	return false; // end
}


bool cTeamKickoffAction::MessageProccess(const ai::sMsg &msg)
{
	__super::MessageProccess(msg);
	

	return true;
}

