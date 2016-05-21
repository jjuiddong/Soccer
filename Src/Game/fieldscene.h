//
// 2016-05-21, jjuiddong
//
//
#pragma once

#include "match.h"


namespace soccer
{

	class cFieldScene : public framework::cScene
	{
	public:
		cFieldScene();
		virtual ~cFieldScene();

		virtual bool Init(graphic::cRenderer &renderer) override;
		virtual bool Update(const float deltaSeconds) override;
		virtual void Render(graphic::cRenderer &renderer, const Matrix44 &parentTm) override;
		virtual bool MessageProc(UINT message, WPARAM wParam, LPARAM lParam) override;
		virtual void Show() override;


	public:
		soccer::cMatch m_match;
	};

}