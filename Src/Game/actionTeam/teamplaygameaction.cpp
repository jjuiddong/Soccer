
#include "stdafx.h"
#include "teamplaygameaction.h"

using namespace soccer;
using namespace ai;


cTeamPlayGameAction::cTeamPlayGameAction(ai::iActorInterface<cTeam> *agent)
	: ai::cAction<cTeam>(agent, "TeamPlayGameAction")
{
}

cTeamPlayGameAction::~cTeamPlayGameAction()
{
}


bool cTeamPlayGameAction::ActionThrough(const float deltaSeconds)
{
	__super::ActionThrough(deltaSeconds);
	return true;
}


bool cTeamPlayGameAction::ActionExecute(const float deltaSeconds)
{
	__super::ActionExecute(deltaSeconds);

	// 팀원들에게 게임 시작을 알린다.
 	sMsg msg;
 	msg.msg = PLAYER_AI_MSG::PLAYGAME;
 	m_agent->m_ptr->DispatchMessage(msg);
	return false; // end
}


bool cTeamPlayGameAction::MessageProccess(const ai::sMsg &msg)
{
	__super::MessageProccess(msg);
	return true;
}
