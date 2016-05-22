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
	m_ball.Init(renderer);
	m_field.Init(renderer);
//	m_referee.Init();
	m_teams[0].Init(renderer, MATCH::HOME, m_field, m_ball);
	m_teams[1].Init(renderer, MATCH::AWAY, m_field, m_ball);

	return true;
}


bool cMatch::Update(const float deltaSeconds)
{
//	m_referee.Update(deltaSeconds);
	m_teams[0].Update(deltaSeconds);
	m_teams[1].Update(deltaSeconds);
	m_ball.Update(deltaSeconds);

	return true;
}


void cMatch::Render(graphic::cRenderer &renderer)
{
	m_field.Render(renderer);
	m_teams[0].Render(renderer);
	m_teams[1].Render(renderer);
	m_ball.Render(renderer, Matrix44::Identity);
}
