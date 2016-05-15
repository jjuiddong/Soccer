
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


bool cTeam::Init(graphic::cRenderer &renderer, const MATCH::TYPE match)
{
	m_match = match;
	m_formation.Read("../media/formation.txt");

	vector<Vector2> locs;
	m_formation.GetPlayerLocation(match, g_match->m_field, locs);

	m_players.reserve(11);
	for (int i = 0; i < 11; ++i)
	{
		cPlayer *p = new cPlayer();
		sPlayerData data;
		data.position = POSITION::MF;
		data.location = locs[i];
		data.scale = 0.1f;

		p->Init(renderer, data);
		AddActor(&p->m_ai);
		m_players.push_back(p);
	}

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
