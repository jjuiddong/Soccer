//
// 2016-05-01, jjuiddong
//
#pragma once


namespace soccer
{
	class cTeam;
	class cPlayer : public ai::iActorInterface<cPlayer>
	{
	public:
		cPlayer();
		virtual ~cPlayer();

		bool Init(graphic::cRenderer &renderer, const sPlayerData &data, cTeam &team);
		bool Update(const float deltaSeconds);
		void Render(graphic::cRenderer &renderer, const Matrix44 &tm = Matrix44::Identity);

		virtual Matrix44& aiGetTransform() override;
		virtual void aiSetAnimation(const string &animationName) override;


	public:
		sPlayerData m_data;
		graphic::cModel m_model;
		ai::cActor<cPlayer> m_ai;
		cTeam *m_team; // own team, reference
		Vector2 m_movFieldLoc;	// 포메이션 상에서 위치해야 될 필드 내 위치, cTeam에서 계산해서 업데이트 함.
	};

}
