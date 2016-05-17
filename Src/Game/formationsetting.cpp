
#include "stdafx.h"
#include "formationsetting.h"


using namespace soccer;


cFormationSetting::cFormationSetting()
{
}

cFormationSetting::~cFormationSetting()
{
	Clear();
}


bool cFormationSetting::Init(graphic::cRenderer &renderer, const string &fileName)
{
	m_field.Init(renderer);

	vector<Vector2> locs;
	m_formation.Read(fileName);
	m_formation.GetPlayerLocation(MATCH::HOME, g_match->m_field, locs);

	m_players.reserve(11);
	for (int i = 0; i < 11; ++i)
	{
		cPlayer *p = new cPlayer();
		sPlayerData data;
		data.position = POSITION::MF;
		data.location = locs[i];
		data.scale = 0.3f;

		p->Init(renderer, data);

		ai::cMove<cPlayer> *mov = new ai::cMove<cPlayer>(p, Vector3(locs[i].x, 0, locs[i].y), 50.f);
		p->m_ai.PushAction(mov);

		m_players.push_back(p);
	}

	return true;
}


bool cFormationSetting::Update(const float deltaSeconds)
{
	for each (auto &p in m_players)
	{
		p->Update(deltaSeconds);
	}
	return true;
}


void cFormationSetting::Render(graphic::cRenderer &renderer)
{
	m_field.Render(renderer);

	for each (auto &p in m_players)
	{
		p->Render(renderer, Matrix44::Identity);
	}
}


void cFormationSetting::WriteFormation(const string &fileName)
{
	vector<Vector3> locs(m_players.size());
	for (int i = 0; i < (int)m_players.size(); ++i)
		locs[i] = m_players[i]->m_model.GetTransform().GetPosition();

	m_formation.SetPlayerLocation(m_field, locs);
	m_formation.Write(fileName);
}


void cFormationSetting::Clear()
{
	for each (auto &p in m_players)
	{
		delete p;
	}
	m_players.clear();
}
