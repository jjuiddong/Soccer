//
// 2016-05-10, jjuiddong
//
// �÷����� ��� �ൿ�� �Ǵ��ϴ� �׼� ��ü
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
