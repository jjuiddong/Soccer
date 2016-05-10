
#include "stdafx.h"
#include "playeractionmain.h"

using namespace ai;
using namespace soccer;


cPlayerActionMain::cPlayerActionMain()
	: ai::cAction(NULL, "PlayerActionMain")
{
}

cPlayerActionMain::~cPlayerActionMain()
{
}


// override
void cPlayerActionMain::Start(ai::cAction *prevAction)
{
	__super::Start(prevAction);

}


void cPlayerActionMain::Resume(ai::cAction *prevAction)
{
	__super::Resume(prevAction);

}


void cPlayerActionMain::End()
{
	__super::End();

}


bool cPlayerActionMain::ActionThrough(const float deltaSeconds)
{
	return true;
}


bool cPlayerActionMain::ActionExecute(const float deltaSeconds)
{
	
	return true;
}


bool cPlayerActionMain::MessageProccess(const ai::sMsg &msg)
{
	switch (msg.msg)
	{
	case PLAYER_AI_MSG::KICKOFF:
	{
		ai::cMove *p = new ai::cMove();
		p->m_speed = 5.f;
		p->Init(Vector3(50,0,50));
		PushAction(p);
		m_actor->StartAction();
	}
	break;

	default:
		break;
	}

	return __super::MessageProccess(msg);
}
