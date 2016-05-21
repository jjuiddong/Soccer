
#include "stdafx.h"
#include "strategyscene.h"

using namespace soccer;
using namespace framework;


cStrategyScene::cStrategyScene()
	: cScene(SCENE::STRATEGY, "strategyscene")
	, m_isSelectPlayer(false)
	, m_selectPlayer(NULL)
{
}

cStrategyScene::~cStrategyScene()
{
}


bool cStrategyScene::Init(graphic::cRenderer &renderer)
{
	__super::Init(renderer);
	m_formationSetting.Init(renderer, m_formationFileName);
	m_ground.Create(renderer, 10, 10, 20);
	return true;
}


void cStrategyScene::Show()
{
	__super::Show();

	graphic::GetMainCamera()->SetCamera(Vector3(0, 80, -80), Vector3(0, 24, -50), Vector3(0, 1, 0));
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
	//m_ground.Render(renderer);
}


bool cStrategyScene::MessageProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		const POINT pos = { LOWORD(lParam), HIWORD(lParam) };
		Vector3 orig, dir;
		graphic::cMainCamera::Get()->GetRay(800, 600, pos.x, pos.y, orig, dir);

		if (m_isSelectPlayer)
		{
			Vector3 out;
			if (m_ground.Pick(orig, dir, out))
			{
				Matrix44 tm = m_selectPlayer->m_model.GetTransform();
				tm.SetPosition(out);
				m_selectPlayer->m_model.SetTransform(tm);
			}
		}
		else
		{
			// picking
			for each (auto &player in m_formationSetting.m_players)
			{
				if (player->m_model.Pick(orig, dir))
				{
					m_isSelectPlayer = true;
					m_selectPlayer = player;
					break;
				}
			}
		}
	}
	break;

	case WM_MOUSEMOVE:
	{
		if (m_isSelectPlayer)
		{
			const POINT pos = { LOWORD(lParam), HIWORD(lParam) };
			Vector3 orig, dir;
			graphic::cMainCamera::Get()->GetRay(800, 600, pos.x, pos.y, orig, dir);

			Vector3 out;
			if (m_ground.Pick(orig, dir, out))
			{
				Matrix44 tm = m_selectPlayer->m_model.GetTransform();
				tm.SetPosition(out);
				m_selectPlayer->m_model.SetTransform(tm);
			}
		}
	}
	break;

	case WM_LBUTTONUP:
	{
		if (m_isSelectPlayer)
		{
			const POINT pos = { LOWORD(lParam), HIWORD(lParam) };
			Vector3 orig, dir;
			graphic::cMainCamera::Get()->GetRay(800, 600, pos.x, pos.y, orig, dir);

			Vector3 out;
			if (m_ground.Pick(orig, dir, out))
			{
				Matrix44 tm = m_selectPlayer->m_model.GetTransform();
				tm.SetPosition(out);
				m_selectPlayer->m_model.SetTransform(tm);
				m_isSelectPlayer = false;
				m_selectPlayer = NULL;

				// 정보가 바뀔 때마다, 저장한다.
				m_formationSetting.WriteFormation(m_formationFileName);
			}
		}
	}
	break;
	}

	return __super::MessageProc(message, wParam, lParam);
}
