#include "stdafx.h"
#include "match.h"

using namespace soccer;


cMatch::cMatch()
{
}

cMatch::~cMatch()
{
}


bool cMatch::Init(graphic::cRenderer &renderer)
{
	m_field.Init(renderer);
	m_referee.Init();
	m_teams[0].Init(renderer);
//	m_teams[1].Init(renderer);

	return true;
}


bool cMatch::Update(const float deltaSeconds)
{
	m_referee.Update(deltaSeconds);
	m_teams[0].Update(deltaSeconds);
//	m_teams[1].Update(deltaSeconds);

	return true;
}


void cMatch::Render(graphic::cRenderer &renderer)
{
	m_field.Render(renderer);
	m_teams[0].Render(renderer);
//	m_teams[1].Render(renderer);
}
