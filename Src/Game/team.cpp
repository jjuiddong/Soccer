
#include "stdafx.h"
#include "team.h"
#include "player.h"

using namespace soccer;


cTeam::cTeam()
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
		m_players.push_back(p);
	}

	return true;
}


bool cTeam::Update(const float deltaSeconds)
{
	for each (auto &p in m_players)
	{
		p->Move(deltaSeconds);
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
