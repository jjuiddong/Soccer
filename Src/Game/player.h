//
// 2016-05-01, jjuiddong
//
#pragma once


namespace soccer
{

	class cPlayer : public ai::iActorInterface<cPlayer>
	{
	public:
		cPlayer();
		virtual ~cPlayer();

		bool Init(graphic::cRenderer &renderer, const sPlayerData &data);
		bool Update(const float deltaSeconds);
		void Render(graphic::cRenderer &renderer, const Matrix44 &tm = Matrix44::Identity);

		virtual Matrix44& aiGetTransform() override;
		virtual void aiSetAnimation(const string &animationName) override;


	public:
		sPlayerData m_data;
		graphic::cModel m_model;
		ai::cActor<cPlayer> m_ai;
	};

}
