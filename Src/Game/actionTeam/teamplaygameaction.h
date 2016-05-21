//
// 2016-05-21, jjuiddong
// �� ������ �ൿ
//
#pragma once

#include "../team.h"

namespace soccer
{

	class cTeamPlayGameAction : public ai::cAction<cTeam>
	{
	public:
		cTeamPlayGameAction(ai::iActorInterface<cTeam> *agent);
		virtual ~cTeamPlayGameAction();

		// override
		virtual bool ActionThrough(const float deltaSeconds) override;
		virtual bool ActionExecute(const float deltaSeconds) override;
		virtual bool MessageProccess(const ai::sMsg &msg) override;
	};

}
