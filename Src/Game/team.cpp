
#include "stdafx.h"
#include "team.h"
#include "player.h"
#include "ball.h"
#include "actionTeam/teamkickoffaction.h"

using namespace soccer;


cTeam::cTeam()
	: ai::cActor<cTeam>(this)
	, ai::iActorInterface<cTeam>(this)
	, m_ball(NULL)
{
}

cTeam::~cTeam()
{
	Clear();
}


bool cTeam::Init(graphic::cRenderer &renderer, const MATCH::TYPE match, cField &field, cBall &ball)
{
	m_ball = &ball;
	m_match = match;
	if (!m_halfFormation.Read("../media/formation.txt"))
	{
		dbg::ErrLog("Error!! Team Initialize, not found formation file\n");
		return false;
	}
	
	if (!m_formation.Init(match, field))
	{
		dbg::ErrLog("Error!! Team Initialize, init formaiton object error \n");
		return false;
	}

	if (!m_formation.Read("../media/formation.txt"))
	{
		dbg::ErrLog("Error!! Team Initialize, init formaiton read error \n");
		return false;
	}

	vector<Vector2> locs;
	m_halfFormation.GetPlayerLocation(match, field, locs);

	m_players.reserve(11);
	for (int i = 0; i < 11; ++i)
	{
		cPlayer *p = new cPlayer();
		sPlayerData data;
		data.position = POSITION::MF;
		data.location = locs[i];
		data.scale = 0.1f;

		p->Init(renderer, data, *this);
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

	// 볼 위치에 따라, 선수들의 위치를 계산한다.
	m_formation.Update(deltaSeconds, m_ball->GetTransform().GetPosition());
	for (int i = 0; i < cFormation::PLAYER_COUNT; ++i)
		m_players[i]->m_movFieldLoc = m_formation.FormationToField(m_formation.m_loc[i]);

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
