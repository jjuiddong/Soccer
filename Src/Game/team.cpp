
#include "stdafx.h"
#include "team.h"
#include "player.h"
#include "actionTeam/teamkickoffaction.h"

using namespace soccer;


cTeam::cTeam()
	: ai::cActor<cTeam>(this)
	, ai::iActorInterface<cTeam>(this)
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
		p->Init(renderer, { POSITION::MF });
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

	m_formation.Read("../media/formation.txt");

 	cTeamKickoffAction *kickoffAction = new cTeamKickoffAction(this);
 	PushAction(kickoffAction);

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
