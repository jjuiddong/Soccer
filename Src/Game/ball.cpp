
#include "stdafx.h"
#include "ball.h"


using namespace soccer;

cBall::cBall() :
	m_sphere(NULL)
{
}

cBall::~cBall()
{
	Clear();
}


bool cBall::Init(graphic::cRenderer &renderer)
{
	m_sphere = new graphic::cSphere();
	m_sphere->Create(renderer, 0.5f, 10, 10);
	InsertChild(m_sphere);
	return true;
}


bool cBall::Update(const float deltaSeconds)
{
	__super::Update(deltaSeconds);
	return true;
}


// void cBall::Render(graphic::cRenderer &renderer, const Matrix44 &tm)
// {
// 	graphic::cCharacter::Render(renderer, tm);
// 	m_sphere.Render(renderer, tm);
// }


void cBall::Clear()
{
	__super::Clear();
}
