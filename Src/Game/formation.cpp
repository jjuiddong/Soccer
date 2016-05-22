
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


// �ʱ�ȭ
bool cFormation::Init(const MATCH::TYPE match, const cField &field)
{
	m_match = match;
	m_field = &field;
	return true;
}


// �����̼� ������ �о �ʱ�ȭ �Ѵ�.
bool cFormation::Read(const string &fileName)
{
	cHalfFormation half;
	if (!half.Read(fileName))
		return false;

	for (int i = 0; i < PLAYER_COUNT; ++i)
		m_halfLoc[i] = half.m_loc[i];

	return true;
}


// �����̼� ������ �����Ѵ�.
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


// �� ��ġ�� �������� ������ ��ġ�� ����ϰ�, m_loc�� �����Ѵ�.
void cFormation::Update(const float deltaSeconds, const Vector3 &ballPos)
{
	RET(!m_field);

	const Vector2 ballLocalPos = FieldToFormation(ballPos);

	for (int i = 0; i < PLAYER_COUNT; ++i)
		m_loc[i] = HalfToFormation(m_halfLoc[i]);

	// ������ ����, ��Ű�� ����
	Vector2 offset(0, 0);
	offset.y = ballLocalPos.y * 0.5f;
	for (int i = 1; i < PLAYER_COUNT; ++i)
		m_loc[i] += offset;
}


// �� ��ġ�� ����, �������� ��ġ�� ����� �����Ѵ�.
bool cFormation::GetPlayerLocation(const Vector3 &ballPos, OUT vector<Vector2> &out)
{
	RETV(!m_field, false);

	const Vector2 ballLocalPos = FieldToFormation(ballPos);

	for (int i = 0; i < PLAYER_COUNT; ++i)
		m_loc[i] = HalfToFormation(m_halfLoc[i]);

	// ������ ����, ��Ű�� ����
	Vector2 offset(0, 0);
	offset.y = ballLocalPos.y * 0.5f;
	for (int i = 1; i < PLAYER_COUNT; ++i)
	{
		m_loc[i] += offset;
	}

	// Field ��ǥ��� ��ȯ
	out.reserve(PLAYER_COUNT);
	for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		out.push_back(FormationToField(m_loc[i]));
	}

	return true;
}


// Field ��ǥ�� Formaiton ��ǥ�� �ٲ۴�.
Vector2 cFormation::FieldToFormation(const Vector3 &pos)
{
	RETV(!m_field, Vector2(0, 0));

	const float x = pos.x / (m_field->m_width * 0.5f);
	const float y = (pos.z / m_field->m_height) + 0.5f;
	return Vector2(x, y);
}


// HalfFormation ��ǥ�踦 Formation ��ǥ��� �ٲ۴�.
Vector2 cFormation::HalfToFormation(const Vector2 &pos)
{
	const float x = pos.x;
	const float y = pos.y * 0.5f;
	return Vector2(x, y);
}


// Formation ��ǥ�迡�� Field ��ǥ��� ��ȯ�Ѵ�.
Vector2 cFormation::FormationToField(const Vector2 &pos)
{
	RETV(!m_field, Vector2(0, 0));

	const float x = pos.x * m_field->m_width * 0.5f;
	const float y = pos.y * m_field->m_height - (m_field->m_height * 0.5f);
	return Vector2(x, y);
}
