//
// 2016-05-10, jjuiddong
//
// ÆÀ Å±¿ÀÇÁ ÀÎ°øÁö´É
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
	};

}
