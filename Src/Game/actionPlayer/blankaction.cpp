
#include "stdafx.h"
#include "blankaction.h"

using namespace ai;
using namespace soccer;


cBlankAction::cBlankAction()
{
}

cBlankAction::~cBlankAction()
{
}


// override
void cBlankAction::Start(ai::cAction *prevAction)
{
	__super::Start(prevAction);
}


void cBlankAction::Resume(ai::cAction *prevAction)
{
	__super::Resume(prevAction);
}


void cBlankAction::End()
{
	__super::End();
}


bool cBlankAction::ActionThrough(const float deltaSeconds)
{
	return true;
}


bool cBlankAction::ActionExecute(const float deltaSeconds)
{
	return true;
}


bool cBlankAction::MessageProccess(const ai::sMsg &msg)
{
	return __super::MessageProccess(msg);
}

