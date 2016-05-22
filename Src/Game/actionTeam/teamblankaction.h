//
// 2016-05-22, jjuiddong
// ºó ÆÀ ¾×¼Ç, ÅÛÇÃ¸´ ¿ëÀ¸·Î ¾²ÀÓ
//
#pragma once

#include "../team.h"

namespace soccer
{

	class cTeamBlankAction : public ai::cAction<cTeam>
	{
	public:
		cTeamBlankAction(ai::iActorInterface<cTeam> *agent);
		virtual ~cTeamBlankAction();

		// override
		virtual bool ActionThrough(const float deltaSeconds) override;
		virtual bool ActionExecute(const float deltaSeconds) override;
		virtual bool MessageProccess(const ai::sMsg &msg) override;
	};

}
