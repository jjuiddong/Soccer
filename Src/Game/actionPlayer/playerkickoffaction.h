//
// 2016-05-14, jjuiddong
//
// �÷��� ű���� �׼�
//
#pragma once

#include "../player.h"

namespace soccer
{

	class cPlayerKickoffAction : public ai::cAction<cPlayer>
	{
	public:
		cPlayerKickoffAction(ai::iActorInterface<cPlayer> *agent);
		virtual ~cPlayerKickoffAction();

		// override
		virtual bool ActionThrough(const float deltaSeconds) override;
		virtual bool ActionExecute(const float deltaSeconds) override;
		virtual bool MessageProccess(const ai::sMsg &msg) override;
	};

}
