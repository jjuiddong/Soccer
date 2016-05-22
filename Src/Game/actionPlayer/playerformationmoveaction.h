//
// 2016-05-21, jjuiddong
// 포메이션 위치를 유지해가며, 볼을 중심으로 움직인다.
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
		float m_rotateInterval; // 회전 보간 시간, 0.3초
		float m_distance;
		float m_oldDistance;

		Vector3 m_dir; // 이동 방향
		Quaternion m_fromDir; // 이동 전 방향
		Quaternion m_toDir; // 이동 후 방향
		float m_rotateTime; // 회전 중인 시간.
		Matrix44 m_R;
		Matrix44 m_S;
	};

}
