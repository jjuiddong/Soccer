
#include "stdafx.h"
#include "playerformationmoveaction.h"

using namespace ai;
using namespace soccer;


cPlayerFormationMoveAction::cPlayerFormationMoveAction(ai::iActorInterface<cPlayer> *agent)
	: ai::cAction<cPlayer>(agent, "PlayerFormationMoveAction")
	, m_incTime(0)
	, m_rotateTime(0)
	, m_speed(10.f)
	, m_rotateInterval(0.3f)
	, m_distance(0)
{
	const Vector2 pos = m_agent->m_ptr->m_movFieldLoc;
	SetDestination(Vector3(pos.x, 0, pos.y));
}

cPlayerFormationMoveAction::~cPlayerFormationMoveAction()
{
}


bool cPlayerFormationMoveAction::ActionThrough(const float deltaSeconds)
{
	return true;
}


bool cPlayerFormationMoveAction::ActionExecute(const float deltaSeconds)
{
	m_incTime += deltaSeconds;

	if (m_incTime > 0.05f) // 3�� ���� �ѹ���, ��ġ�� �����Ѵ�.
	{
		m_incTime = 0;
		const Vector2 pos = m_agent->m_ptr->m_movFieldLoc;
		SetDestination(Vector3(pos.x, 0, pos.y));
		return true;
	}

	const Vector3 curPos = m_agent->aiGetTransform().GetPosition();

	// ȸ�� ���� ���
	if (m_rotateTime < m_rotateInterval)
	{
		m_rotateTime += deltaSeconds;

		const float alpha = min(1, m_rotateTime / m_rotateInterval);
		const Quaternion q = m_fromDir.Interpolate(m_toDir, alpha);
		m_R = q.GetMatrix();
	}

	const Vector3 pos = curPos + m_dir * m_speed * deltaSeconds;

	// �������� �����ٸ� ����.
	// �������� ���� ��, ����Ǵ� ������ ���� �� �ִ�.
	const float distance = pos.LengthRoughly(m_dest);
	if (pos.LengthRoughly(m_dest) < 0.01f)
		return true; // ������ ����. �׼�����.

	// ������ ���� �ָ� �Դٸ�, �����.
	if (m_oldDistance < distance)
	{
		return true;
	}

	// ĳ���� �̵�.
	m_agent->aiGetTransform() = m_S * m_R;
	m_agent->aiGetTransform().SetPosition(pos);

	m_oldDistance = distance;
	return true;
}


bool cPlayerFormationMoveAction::MessageProccess(const ai::sMsg &msg)
{
	return __super::MessageProccess(msg);
}


void cPlayerFormationMoveAction::SetDestination(const Vector3 &dest)
{
	m_dest = dest;
	m_rotateTime = 0;

	const Vector3 curPos = m_agent->aiGetTransform().GetPosition();
	m_distance = curPos.LengthRoughly(m_dest);
	m_oldDistance = curPos.LengthRoughly(m_dest);
	m_dir = m_dest - curPos;
	m_dir.y = 0;
	m_dir.Normalize();

	Quaternion q;
	q.SetRotationArc(Vector3(0, 0, -1), m_dir);

	m_fromDir = m_agent->aiGetTransform().GetQuaternion();
	m_toDir = q;
	m_rotateTime = 0;

	m_S.SetScale(m_agent->m_ptr->m_model.m_scale);
	m_R = m_fromDir.GetMatrix();
}
