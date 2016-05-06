
#include "stdafx.h"
#include "ball.h"


using namespace soccer;

cBall::cBall()
{
}

cBall::~cBall()
{
}


bool cBall::Init(graphic::cRenderer &renderer)
{
	m_sphere.Create(renderer, 0.5f, 10, 10);
	return true;
}


bool cBall::Update(const float deltaSeconds)
{
	graphic::cCharacter::Update(deltaSeconds);
	return true;
}


void cBall::Render(graphic::cRenderer &renderer, const Matrix44 &tm)
{
	graphic::cCharacter::Render(renderer, tm);
	m_sphere.Render(renderer, tm);
}


void cBall::Clear()
{
	graphic::cCharacter::Clear();

}
