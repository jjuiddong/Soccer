
#include "stdafx.h"
#include "formation.h"
#include "halfformation.h"

using namespace soccer;


cFormation::cFormation()
	: m_field(NULL)
	, m_match(MATCH::HOME)
{
}

cFormation::~cFormation()
{
}


// 초기화
bool cFormation::Init(const MATCH::TYPE match, const cField &field)
{
	m_match = match;
	m_field = &field;
	return true;
}


// 포메이션 파일을 읽어서 초기화 한다.
bool cFormation::Read(const string &fileName)
{
	cHalfFormation half;
	if (!half.Read(fileName))
		return false;

	for (int i = 0; i < PLAYER_COUNT; ++i)
		m_halfLoc[i] = half.m_loc[i];

	return true;
}


// 포메이션 정보를 저장한다.
// bool cFormation::Write(const string &fileName)
// {
// 	cHalfFormation half;
// 	for (int i = 0; i < PLAYER_COUNT; ++i)
// 		half.m_loc[i] = m_loc[i];
// 
// 	if (!half.Write(fileName))
// 		return false;
// 
// 	return true;
// }


// 볼 위치를 기준으로 선수들 위치를 계산하고, m_loc에 저장한다.
void cFormation::Update(const float deltaSeconds, const Vector3 &ballPos)
{
	RET(!m_field);

	const Vector2 ballLocalPos = FieldToFormation(ballPos);

	for (int i = 0; i < PLAYER_COUNT; ++i)
		m_loc[i] = HalfToFormation(m_halfLoc[i]);

	// 오프셋 적용, 골키퍼 제외
	Vector2 offset(0, 0);
	offset.y = ballLocalPos.y * 0.5f;
	for (int i = 1; i < PLAYER_COUNT; ++i)
		m_loc[i] += offset;
}


// 볼 위치에 따라, 선수들의 위치를 계산해 리턴한다.
bool cFormation::GetPlayerLocation(const Vector3 &ballPos, OUT vector<Vector2> &out)
{
	RETV(!m_field, false);

	const Vector2 ballLocalPos = FieldToFormation(ballPos);

	for (int i = 0; i < PLAYER_COUNT; ++i)
		m_loc[i] = HalfToFormation(m_halfLoc[i]);

	// 오프셋 적용, 골키퍼 제외
	Vector2 offset(0, 0);
	offset.y = ballLocalPos.y * 0.5f;
	for (int i = 1; i < PLAYER_COUNT; ++i)
	{
		m_loc[i] += offset;
	}

	// Field 좌표계로 변환
	out.reserve(PLAYER_COUNT);
	for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		out.push_back(FormationToField(m_loc[i]));
	}

	return true;
}


// Field 좌표를 Formaiton 좌표로 바꾼다.
Vector2 cFormation::FieldToFormation(const Vector3 &pos)
{
	RETV(!m_field, Vector2(0, 0));

	const float x = pos.x / (m_field->m_width * 0.5f);
	const float y = (pos.z / m_field->m_height) + 0.5f;
	return Vector2(x, y);
}


// HalfFormation 좌표계를 Formation 좌표계로 바꾼다.
Vector2 cFormation::HalfToFormation(const Vector2 &pos)
{
	const float x = pos.x;
	const float y = pos.y * 0.5f;
	return Vector2(x, y);
}


// Formation 좌표계에서 Field 좌표계로 변환한다.
Vector2 cFormation::FormationToField(const Vector2 &pos)
{
	RETV(!m_field, Vector2(0, 0));

	const float x = pos.x * m_field->m_width * 0.5f;
	const float y = pos.y * m_field->m_height - (m_field->m_height * 0.5f);
	return Vector2(x, y);
}
