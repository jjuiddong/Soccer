//
// 2016-05-10, jjuiddong
//
// 팀 킥오프 인공지능
//
#pragma once

#include "../team.h"

namespace soccer
{

	class cTeamKickoffAction : public ai::cAction<cTeam>
	{
	public:
		cTeamKickoffAction(ai::iActorInterface<cTeam> *agent);
		virtual ~cTeamKickoffAction();

		// override
		virtual bool ActionThrough(const float deltaSeconds) override;
		virtual bool ActionExecute(const float deltaSeconds) override;
		virtual bool MessageProccess(const ai::sMsg &msg) override;


	public:
		bool m_isSendMessage; // 선수들에게 kickoff 메세지를 보냈다면 true
	};

}
