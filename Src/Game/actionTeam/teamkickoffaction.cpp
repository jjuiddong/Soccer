
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
		// ��� �������� ���ڸ��� �����ߴٸ�, ű���� �׼��� �����Ѵ�.
		// Move �׼��� ������, ������ ������ ����
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
		// �����鿡�� ű���� �޼����� ������.
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
