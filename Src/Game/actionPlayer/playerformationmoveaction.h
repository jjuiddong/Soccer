//
// 2016-05-21, jjuiddong
// 포메이션 위치를 유지해가며, 볼을 중심으로 움직인다.
//
#pragma once

#include "../player.h"

namespace soccer
{

	class cPlayerFormationMoveAction : public ai::cAction<cPlayer>
	{
	public:
		cPlayerFormationMoveAction(ai::iActorInterface<cPlayer> *agent);
		virtual ~cPlayerFormationMoveAction();

		// override
		virtual bool ActionThrough(const float deltaSeconds) override;
		virtual bool ActionExecute(const float deltaSeconds) override;
		virtual bool MessageProccess(const ai::sMsg &msg) override;
	};

}
