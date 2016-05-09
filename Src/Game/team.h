//
// 2016-05-01, jjuiddong
//
// �౸ ���� ǥ���ϴ� ��ü
// �����ϰ� �ΰ����� ���õ� �ϸ� ó���Ѵ�.
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
