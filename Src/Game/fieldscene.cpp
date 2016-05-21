
#include "stdafx.h"
#include "fieldscene.h"

using namespace soccer;
using namespace graphic;


cFieldScene::cFieldScene()
	: cScene(SCENE::FIELD, "fieldscene")
{
}

cFieldScene::~cFieldScene()
{
}


bool cFieldScene::Init(graphic::cRenderer &renderer)
{
	__super::Init(renderer);
	m_match.Init(renderer);

	return true;
}


void cFieldScene::Show()
{
	__super::Show();
	graphic::GetMainCamera()->SetCamera(Vector3(100, 80, -30), Vector3(0, 0, 0), Vector3(0, 1, 0));
}


bool cFieldScene::Update(const float deltaSeconds)
{
	__super::Update(deltaSeconds);
	m_match.Update(deltaSeconds);
	return true;
}


void cFieldScene::Render(graphic::cRenderer &renderer, const Matrix44 &parentTm)
{
	__super::Render(renderer, parentTm);
	m_match.Render(renderer);
}


bool cFieldScene::MessageProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	return __super::MessageProc(message, wParam, lParam);
}
