
#include "stdafx.h"
#include "formationmovescene.h"


using namespace soccer;
using namespace framework;


cFormationMoveScene::cFormationMoveScene()
	: cScene(SCENE::FORMATION, "formationmovescene")
{
}

cFormationMoveScene::~cFormationMoveScene()
{
}


bool cFormationMoveScene::Init(graphic::cRenderer &renderer)
{
	__super::Init(renderer);

	m_field.Init(renderer);
	m_team.Init(renderer, MATCH::HOME);
	m_ball.Init(renderer);

	m_team.PushFrontAction(new cTeamPlayGameAction(&m_team));

	return true;
}


void cFormationMoveScene::Show()
{
	__super::Show();
	graphic::GetMainCamera()->SetCamera(Vector3(100, 80, -30), Vector3(0, 0, 0), Vector3(0, 1, 0));
}


bool cFormationMoveScene::Update(const float deltaSeconds)
{
	__super::Update(deltaSeconds);
	m_ball.Update(deltaSeconds);
	m_team.Update(deltaSeconds);
	return true;
}


void cFormationMoveScene::Render(graphic::cRenderer &renderer, const Matrix44 &parentTm)
{
	__super::Render(renderer, parentTm);
	m_field.Render(renderer);
	m_ball.Render(renderer);
	m_team.Render(renderer);
}


bool cFormationMoveScene::MessageProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	return __super::MessageProc(message, wParam, lParam);
}
