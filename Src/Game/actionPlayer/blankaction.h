//
// 2016-05-10, jjuiddong
// 비어 있는 액션을 만들어서, 다른 액션을 만들 때, 템플릿으로 사용한다.
//
#pragma once


namespace soccer
{

	class cBlankAction : public ai::cAction
	{
	public:
		cBlankAction();
		virtual ~cBlankAction();

		// override
		virtual void Start(ai::cAction *prevAction) override;
		virtual void Resume(ai::cAction *prevAction) override;
		virtual void End() override;
		virtual bool ActionThrough(const float deltaSeconds) override;
		virtual bool ActionExecute(const float deltaSeconds) override;
		virtual bool MessageProccess(const ai::sMsg &msg) override;
	};
	
}
