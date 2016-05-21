//
// 2016-05-16, jjuiddong
//
// 전략,전술을 설정하는 씬
//
#pragma once

#include "formationsetting.h"


namespace soccer
{

	class cStrategyScene : public framework::cScene
	{
	public:
		cStrategyScene();
		virtual ~cStrategyScene();

		virtual bool Init(graphic::cRenderer &renderer) override;
		virtual bool Update(const float deltaSeconds) override;
		virtual void Render(graphic::cRenderer &renderer, const Matrix44 &parentTm) override;
		virtual bool MessageProc(UINT message, WPARAM wParam, LPARAM lParam) override;
		virtual void Show() override;


	public:
		soccer::cFormationSetting m_formationSetting;
		graphic::cGrid2 m_ground; // picking 용 오브젝트
		bool m_isSelectPlayer;
		cPlayer *m_selectPlayer;
		const string m_formationFileName = "../media/formation.txt";
	};

}
