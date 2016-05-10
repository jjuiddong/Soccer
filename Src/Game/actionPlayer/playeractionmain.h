//
// 2016-05-10, jjuiddong
//
// 플레어의 모든 행동을 판단하는 액션 객체
//
#pragma once


namespace soccer
{

	class cPlayerActionMain : public ai::cAction
	{
	public:
		cPlayerActionMain();
		virtual ~cPlayerActionMain();

		// override
		virtual void Start(ai::cAction *prevAction) override;
		virtual void Resume(ai::cAction *prevAction) override;
		virtual void End() override;
		virtual bool ActionThrough(const float deltaSeconds) override;
		virtual bool ActionExecute(const float deltaSeconds) override;
		virtual bool MessageProccess(const ai::sMsg &msg) override;
	};
	
}
