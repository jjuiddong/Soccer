
#include "stdafx.h"
#include "field.h"

using namespace soccer;

cField::cField()
{
}

cField::~cField()
{
}


bool cField::Init(graphic::cRenderer &renderer)
{
	const float WIDTH = 90;
	const float HEIGHT = 120;
	const float PENALTY_W = 40;
	const float PENALTY_H = 16.5f;
	const float GOAL_W = 18.3f;
	const float GOAL_H = 5.5f;
	Vector3 arr[][2] = {
		{Vector3(-WIDTH*0.5f,0,-HEIGHT*0.5f), Vector3(-WIDTH*0.5f,0,HEIGHT*0.5f) }, // left
		{ Vector3(WIDTH*0.5f,0,-HEIGHT*0.5f), Vector3(WIDTH*0.5f,0,HEIGHT*0.5f) }, // right
		{ Vector3(-WIDTH*0.5f,0,HEIGHT*0.5f), Vector3(WIDTH*0.5f,0,HEIGHT*0.5f) }, // top
		{ Vector3(-WIDTH*0.5f,0,-HEIGHT*0.5f), Vector3(WIDTH*0.5f,0,-HEIGHT*0.5f) }, // bottom
		{ Vector3(-WIDTH*0.5f,0,0), Vector3(WIDTH*0.5f,0,0) }, // center

		{ Vector3(-PENALTY_W*0.5f,0,-HEIGHT*0.5f), Vector3(-PENALTY_W*0.5f,0,-HEIGHT*0.5f+PENALTY_H) }, // bottom penalty left
		{ Vector3(PENALTY_W*0.5f,0,-HEIGHT*0.5f), Vector3(PENALTY_W*0.5f,0,-HEIGHT*0.5f + PENALTY_H) }, // bottom penalty right
		{ Vector3(-PENALTY_W*0.5f,0,-HEIGHT*0.5f+ PENALTY_H), Vector3(PENALTY_W*0.5f,0,-HEIGHT*0.5f + PENALTY_H) }, // bottom penalty top
		{ Vector3(-PENALTY_W*0.5f,0,HEIGHT*0.5f), Vector3(-PENALTY_W*0.5f,0,HEIGHT*0.5f - PENALTY_H) }, // top penalty left
		{ Vector3(PENALTY_W*0.5f,0,HEIGHT*0.5f ), Vector3(PENALTY_W*0.5f,0,HEIGHT*0.5f - PENALTY_H) }, // top penalty right
		{ Vector3(-PENALTY_W*0.5f,0,HEIGHT*0.5f - PENALTY_H), Vector3(PENALTY_W*0.5f,0,HEIGHT*0.5f - PENALTY_H) }, // top penalty top

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
	for (int i = 0; i < 17; ++i)
		m_lines[i].Render(renderer);

	m_circle.Render(renderer);
}
