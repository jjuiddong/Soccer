
#include "stdafx.h"
#include "teamkickoffaction.h"

using namespace soccer;
using namespace ai;

cTeamKickoffAction::cTeamKickoffAction()
	: ai::cAction(NULL, "TeamKickoffAction")
{
}

cTeamKickoffAction::~cTeamKickoffAction()
{
}


void cTeamKickoffAction::Start(ai::cAction *prevAction)
{
	__super::Start(prevAction);


	// 팀원들에게 킥오프 메세지를 보낸다.
	sMsg msg;
	msg.msg = PLAYER_AI_MSG::KICKOFF;
	m_actor->DispatchMessage(msg);

}


void cTeamKickoffAction::Resume(ai::cAction *prevAction)
{
	__super::Resume(prevAction);
}


void cTeamKickoffAction::End()
{
	__super::End();
}


bool cTeamKickoffAction::ActionThrough(const float deltaSeconds)
{
	__super::ActionThrough(deltaSeconds);

	return true;
}


bool cTeamKickoffAction::ActionExecute(const float deltaSeconds)
{
	__super::ActionExecute(deltaSeconds);

	return true;
}


bool cTeamKickoffAction::MessageProccess(const ai::sMsg &msg)
{
	__super::MessageProccess(msg);
	

	return true;
}

