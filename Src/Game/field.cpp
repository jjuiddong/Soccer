
#include "stdafx.h"
#include "field.h"

using namespace soccer;

cField::cField() 
	: m_width(90)
	, m_height(120)
	, m_penaltyWidth(40)
	, m_penaltyHeight(16.5f)
	, m_goalAreaWidth(18.3f)
	 ,m_goalAreaHeight(5.5f)
{
}

cField::~cField()
{
}


bool cField::Init(graphic::cRenderer &renderer)
{
	const float WIDTH = m_width;
	const float HEIGHT = m_height;
	const float PENALTY_W = m_penaltyWidth;
	const float PENALTY_H = m_penaltyHeight;
	const float GOAL_W = m_goalAreaWidth;
	const float GOAL_H = m_goalAreaHeight;
	Vector3 arr[][2] = {
		{Vector3(-WIDTH*0.5f,0,-HEIGHT*0.5f), Vector3(-WIDTH*0.5f,0,HEIGHT*0.5f) }, // left
		{ Vector3(WIDTH*0.5f,0,-HEIGHT*0.5f), Vector3(WIDTH*0.5f,0,HEIGHT*0.5f) }, // right
		{ Vector3(-WIDTH*0.5f,0,HEIGHT*0.5f), Vector3(WIDTH*0.5f,0,HEIGHT*0.5f) }, // top
		{ Vector3(-WIDTH*0.5f,0,-HEIGHT*0.5f), Vector3(WIDTH*0.5f,0,-HEIGHT*0.5f) }, // bottom
		{ Vector3(-WIDTH*0.5f,0,0), Vector3(WIDTH*0.5f,0,0) }, // center

		// penalty
		{ Vector3(-PENALTY_W*0.5f,0,-HEIGHT*0.5f), Vector3(-PENALTY_W*0.5f,0,-HEIGHT*0.5f+PENALTY_H) }, // bottom penalty left
		{ Vector3(PENALTY_W*0.5f,0,-HEIGHT*0.5f), Vector3(PENALTY_W*0.5f,0,-HEIGHT*0.5f + PENALTY_H) }, // bottom penalty right
		{ Vector3(-PENALTY_W*0.5f,0,-HEIGHT*0.5f+ PENALTY_H), Vector3(PENALTY_W*0.5f,0,-HEIGHT*0.5f + PENALTY_H) }, // bottom penalty top
		{ Vector3(-PENALTY_W*0.5f,0,HEIGHT*0.5f), Vector3(-PENALTY_W*0.5f,0,HEIGHT*0.5f - PENALTY_H) }, // top penalty left
		{ Vector3(PENALTY_W*0.5f,0,HEIGHT*0.5f ), Vector3(PENALTY_W*0.5f,0,HEIGHT*0.5f - PENALTY_H) }, // top penalty right
		{ Vector3(-PENALTY_W*0.5f,0,HEIGHT*0.5f - PENALTY_H), Vector3(PENALTY_W*0.5f,0,HEIGHT*0.5f - PENALTY_H) }, // top penalty top

		// goal area
		{ Vector3(-GOAL_W*0.5f,0,-HEIGHT*0.5f), Vector3(-GOAL_W*0.5f,0,-HEIGHT*0.5f + GOAL_H) }, // bottom goal area left
		{ Vector3(GOAL_W*0.5f,0,-HEIGHT*0.5f), Vector3(GOAL_W*0.5f,0,-HEIGHT*0.5f + GOAL_H) }, // bottom goal area right
		{ Vector3(-GOAL_W*0.5f,0,-HEIGHT*0.5f + GOAL_H), Vector3(GOAL_W*0.5f,0,-HEIGHT*0.5f + GOAL_H) }, // bottom goal area top
		{ Vector3(-GOAL_W*0.5f,0,HEIGHT*0.5f), Vector3(-GOAL_W*0.5f,0,HEIGHT*0.5f - GOAL_H) }, // top goal area left
		{ Vector3(GOAL_W*0.5f,0,HEIGHT*0.5f), Vector3(GOAL_W*0.5f,0,HEIGHT*0.5f - GOAL_H) }, // top goal area right
		{ Vector3(-GOAL_W*0.5f,0,HEIGHT*0.5f - GOAL_H), Vector3(GOAL_W*0.5f,0,HEIGHT*0.5f - GOAL_H) }, // top goal area top
	};

	m_circle.Create(renderer, Vector3(0, 0, 0), 9.15f, 0.1f);
	Matrix44 rot;
	rot.SetRotationX(MATH_PI * 0.5f);
	m_circle.MuliplyTransform(rot);	

	for (int i=0; i < LINE_SIZE; ++i)
	{
		m_lines[i].SetLine(renderer, arr[i][0], arr[i][1], 0.1f);
		m_lines[i].GetMaterial().InitBlack();
	}	

	return true;
}


void cField::Render(graphic::cRenderer &renderer)
{
	for (int i = 0; i < LINE_SIZE; ++i)
		m_lines[i].Render(renderer);

	m_circle.Render(renderer);
}
