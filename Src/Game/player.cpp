
#include "stdafx.h"
#include "player.h"
#include "actionPlayer/playeractionmain.h"

using namespace graphic;
using namespace soccer;


cPlayer::cPlayer() 
	: ai::iActorInterface<cPlayer>(this)
	, m_ai(this)
	, m_model(GenerateId())
{
 	cPlayerActionMain *mainAction = new cPlayerActionMain(this);
 	m_ai.PushAction(mainAction);
}

cPlayer::~cPlayer()
{
}


bool cPlayer::Init(graphic::cRenderer &renderer, const sPlayerData &data)
{
	m_data = data;

	m_model.Create(renderer, "cube.dat");
	const float scale = 0.1f;
	Matrix44 tm;
	tm.SetScale(Vector3(scale, scale, scale));
	m_model.SetTransform(tm);

	return true;
}


bool cPlayer::Update(const float deltaSeconds)
{
	m_ai.Update(deltaSeconds);
	m_model.Update(deltaSeconds);
	return true;
}


void cPlayer::Render(graphic::cRenderer &renderer, const Matrix44 &tm)
{
	m_model.Render(renderer, tm);
}


Matrix44& cPlayer::aiGetTransform()
{
	return m_model.m_TM;
}


void cPlayer::aiSetAnimation(const string &animationName)
{
	// nothing~
}
