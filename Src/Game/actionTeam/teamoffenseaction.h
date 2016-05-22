//
// 2016-05-22, jjuiddong
// �� ���ݽ� �׼�
//
#pragma once

#include "../team.h"

namespace soccer
{

	class cTeamOffenseAction : public ai::cAction<cTeam>
	{
	public:
		cTeamOffenseAction(ai::iActorInterface<cTeam> *agent);
		virtual ~cTeamOffenseAction();

		// override
		virtual bool ActionThrough(const float deltaSeconds) override;
		virtual bool ActionExecute(const float deltaSeconds) override;
		virtual bool MessageProccess(const ai::sMsg &msg) override;
	};

}
