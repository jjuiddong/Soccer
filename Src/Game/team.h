//
// 2016-05-01, jjuiddong
//
// 축구 팀을 표현하는 객체
// 순수하게 인공지능 관련된 일만 처리한다.
//
#pragma once

#include "halfformation.h"

namespace soccer
{
	class cPlayer;

	class cTeam : public ai::iActorInterface<cTeam>
						, public ai::cActor<cTeam>
	{
	public:
		cTeam();
		virtual ~cTeam();

		bool Init(graphic::cRenderer &renderer, const MATCH::TYPE match);
		bool Update(const float deltaSeconds);
		void Render(graphic::cRenderer &renderer, const Matrix44 &tm= Matrix44::Identity);
		void Clear();


	public:
		MATCH::TYPE m_match;
		vector<cPlayer*> m_players;
		cHalfFormation m_formation;
	};

}
