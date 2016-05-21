//
// 2016-05-21, jjuiddong
//	 선수들 움직임을 테스트하는 씬
//
#pragma once


namespace soccer
{

	class cFormationMoveScene : public framework::cScene
	{
	public:
		cFormationMoveScene();
		virtual ~cFormationMoveScene();

		virtual bool Init(graphic::cRenderer &renderer) override;
		virtual bool Update(const float deltaSeconds) override;
		virtual void Render(graphic::cRenderer &renderer, const Matrix44 &parentTm) override;
		virtual bool MessageProc(UINT message, WPARAM wParam, LPARAM lParam) override;
		virtual void Show() override;


	public:
		cField m_field;
		cTeam m_team; // home team
		cBall m_ball;
	};

}