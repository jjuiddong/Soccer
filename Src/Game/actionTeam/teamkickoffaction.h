//
// 2016-05-10, jjuiddong
//
// ÆÀ Å±¿ÀÇÁ ÀÎ°øÁö´É
//
#pragma once


namespace soccer
{

	class cTeamKickoffAction : public ai::cAction
	{
	public:
		cTeamKickoffAction();
		virtual ~cTeamKickoffAction();

		// override
		virtual void Start(ai::cAction *prevAction) override;
		virtual void Resume(ai::cAction *prevAction) override;
		virtual void End() override;
		virtual bool ActionThrough(const float deltaSeconds) override;
		virtual bool ActionExecute(const float deltaSeconds) override;
		virtual bool MessageProccess(const ai::sMsg &msg) override;


	public:
	};

}
