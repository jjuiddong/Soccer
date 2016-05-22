//
// 2016-05-01, jjuiddong
//
// �౸ ���� ǥ���ϴ� ��ü
// �����ϰ� �ΰ����� ���õ� �ϸ� ó���Ѵ�.
//
#pragma once

#include "halfformation.h"
#include "formation.h"

namespace soccer
{
	class cPlayer;
	class cBall;
	class cField;

	class cTeam : public ai::iActorInterface<cTeam>
						, public ai::cActor<cTeam>
	{
	public:
		cTeam();
		virtual ~cTeam();

		bool Init(graphic::cRenderer &renderer, const MATCH::TYPE match, cField &field, cBall &ball);
		bool Update(const float deltaSeconds);
		void Render(graphic::cRenderer &renderer, const Matrix44 &tm= Matrix44::Identity);
		void Clear();


	public:
		cBall *m_ball; // reference
		MATCH::TYPE m_match;
		vector<cPlayer*> m_players;
		cHalfFormation m_halfFormation;
		cFormation m_formation;
		vector<Vector2> m_movPlayerLocs;
	};

}
