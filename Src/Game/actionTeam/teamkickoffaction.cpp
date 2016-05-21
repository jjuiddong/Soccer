
#include "stdafx.h"
#include "teamkickoffaction.h"
#include "../player.h"

using namespace soccer;
using namespace ai;


cTeamKickoffAction::cTeamKickoffAction(ai::iActorInterface<cTeam> *agent)
	: ai::cAction<cTeam>(agent, "TeamKickoffAction")
	, m_isSendMessage(false)
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

	if (m_isSendMessage)
	{
		// 모든 선수들이 제자리에 도착했다면, 킥오프 액션을 종료한다.
		// Move 액션이 끝나면, 도착한 것으로 간주
		bool isAllPlayerReach = true;
		for each (auto &player in m_agent->m_ptr->m_players)
		{
			if (player->m_ai.IsAction(ACTION_TYPE::MOVE))
			{
				isAllPlayerReach = false;
				break;
			}
		}
		if (isAllPlayerReach)
			return false; // end
	}
	else
	{
		// 팀원들에게 킥오프 메세지를 보낸다.
		sMsg msg;
		msg.msg = PLAYER_AI_MSG::KICKOFF;
		m_agent->m_ptr->DispatchMessage(msg);
		m_isSendMessage = true;
	}

	return true;
}


bool cTeamKickoffAction::MessageProccess(const ai::sMsg &msg)
{
	__super::MessageProccess(msg);
	return true;
}
