//
// 2016-05-21, jjuiddong
// �����̼� ��ġ�� �����ذ���, ���� �߽����� �����δ�.
//
#pragma once

#include "../player.h"

namespace soccer
{

	class cPlayerFormationMoveAction : public ai::cAction<cPlayer>
	{
	public:
		cPlayerFormationMoveAction(ai::iActorInterface<cPlayer> *agent);
		virtual ~cPlayerFormationMoveAction();

		// override
		virtual bool ActionThrough(const float deltaSeconds) override;
		virtual bool ActionExecute(const float deltaSeconds) override;
		virtual bool MessageProccess(const ai::sMsg &msg) override;
		void SetDestination(const Vector3 &dest);


	public:
		float m_incTime;
		Vector3 m_dest;
		float m_speed; // 3.f
		float m_rotateInterval; // ȸ�� ���� �ð�, 0.3��
		float m_distance;
		float m_oldDistance;

		Vector3 m_dir; // �̵� ����
		Quaternion m_fromDir; // �̵� �� ����
		Quaternion m_toDir; // �̵� �� ����
		float m_rotateTime; // ȸ�� ���� �ð�.
		Matrix44 m_R;
		Matrix44 m_S;
	};

}
