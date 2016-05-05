
#include "stdafx.h"
#include "player.h"

using namespace graphic;
using namespace soccer;


cPlayer::cPlayer() 
	: cCharacter()
{
}

cPlayer::~cPlayer()
{
}


bool cPlayer::Init(const sPlayerData &data)
{
	m_data = data;
	
	return true;
}


bool cPlayer::Update(const float deltaSeconds)
{
	graphic::cCharacter::Update(deltaSeconds);

	return true;
}
