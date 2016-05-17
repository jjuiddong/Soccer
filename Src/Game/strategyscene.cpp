
#include "stdafx.h"
#include "strategyscene.h"

using namespace soccer;
using namespace framework;


cStrategyScene::cStrategyScene()
	: cWindow(NULL, 0, "strategyscene")
{
}

cStrategyScene::~cStrategyScene()
{
}


bool cStrategyScene::Init(graphic::cRenderer &renderer)
{
	__super::Init(renderer);

	m_formationSetting.Init(renderer);

	return true;
}


bool cStrategyScene::Update(const float deltaSeconds)
{
	__super::Update(deltaSeconds);
	m_formationSetting.Update(deltaSeconds);
	return true;
}


void cStrategyScene::Render(graphic::cRenderer &renderer, const Matrix44 &parentTm)
{
	__super::Render(renderer, parentTm);
	m_formationSetting.Render(renderer);
}


bool cStrategyScene::MessageProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		// picking
		for each (auto &player in m_formationSetting.m_players)
		{
			//player->m_model->Pick()
		}
	}
	break;
	}

	return __super::MessageProc(message, wParam, lParam);
}
