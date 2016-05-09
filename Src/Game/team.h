//
// 2016-05-01, jjuiddong
//
// 축구 팀을 표현하는 객체
// 순수하게 인공지능 관련된 일만 처리한다.
//
#pragma once


namespace soccer
{
	class cPlayer;

	class cTeam : public ai::cActor
	{
	public:
		cTeam();
		virtual ~cTeam();

		bool Init(graphic::cRenderer &renderer);
		bool Update(const float deltaSeconds);
		void Render(graphic::cRenderer &renderer, const Matrix44 &tm= Matrix44::Identity);
		void Clear();


	public:
		vector<cPlayer*> m_players;
	};

}
