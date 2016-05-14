//
// 2016-05-10, jjuiddong
//
// 플레어의 모든 행동을 판단하는 액션 객체
//
#pragma once

#include "../player.h"


namespace soccer
{

	class cPlayerActionMain : public ai::cAction<cPlayer>
	{
	public:
		cPlayerActionMain(ai::iActorInterface<cPlayer> *agent);
		virtual ~cPlayerActionMain();

		// override
		virtual bool ActionThrough(const float deltaSeconds) override;
		virtual bool ActionExecute(const float deltaSeconds) override;
		virtual bool MessageProccess(const ai::sMsg &msg) override;
	};
	
}
