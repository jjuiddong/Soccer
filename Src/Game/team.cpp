
#include "stdafx.h"
#include "team.h"
#include "player.h"

using namespace soccer;


cTeam::cTeam()
	: ai::cActor()
{
}

cTeam::~cTeam()
{
	Clear();
}


bool cTeam::Init(graphic::cRenderer &renderer)
{
	m_players.reserve(11);
	for (int i = 0; i < 11; ++i)
	{
		cPlayer *p = new cPlayer();
		p->Create(renderer, "cube.dat");
		const float scale = 0.1f;
		Matrix44 tm;
		tm.SetScale(Vector3(scale, scale, scale));
		p->SetTransform(tm);
		p->Init({ POSITION::MF });

		cPlayerActionMain *mainAction = new cPlayerActionMain();
		p->m_ai.PushAction(mainAction);		

		AddActor(&p->m_ai);
		m_players.push_back(p);
	}


// 	Vector3 pos[] = {
// 		Vector3(-10, 0, -10),
// 		Vector3(10, 0, -10),
// 
// 		Vector3(-20, 0, -20),
// 		Vector3(-5, 0, -20),
// 		Vector3(5, 0, -20),
// 		Vector3(20, 0, -20),
// 
// 		Vector3(-20, 0, -30),
// 		Vector3(-5, 0, -30),
// 		Vector3(5, 0, -30),
// 		Vector3(20, 0, -30),
// 
// 		Vector3(0, 0, -60),
// 	};
// 
// 	for (int i = 0; i < 11; ++i)
// 	{
// 		ai::cMove *p = new ai::cMove();
// 		p->m_speed = 5.f;
// 		p->Init(pos[i]);
// 		m_players[i]->m_ai.PushAction(p);
// 		m_players[i]->m_ai.StartAction();
// 	}

	cTeamKickoffAction *kickoffAction = new cTeamKickoffAction();
	PushAction(kickoffAction);
	StartAction();

	return true;
}


bool cTeam::Update(const float deltaSeconds)
{
	__super::Update(deltaSeconds);

	for each (auto &p in m_players)
	{
		p->Update(deltaSeconds);
	}

	return true;
}


void cTeam::Render(graphic::cRenderer &renderer, const Matrix44 &tm)
{
	for each (auto &p in m_players)
	{
		p->Render(renderer, tm);
	}
}


void cTeam::Clear()
{
	for each (auto &p in m_players)
	{
		delete p;
	}
	m_players.clear();
}
