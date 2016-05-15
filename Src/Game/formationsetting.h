//
// 2016-05-15, jjuiddong
//
// 포메이션 설정 객체
// 화면에 홈팀 필드와 팀을 출력하고, 마우스로 클릭해 선수들의
// 포메이션을 설정할 수 있게 한다.
//
#pragma once

#include "halffield.h"
#include "halfformation.h"

namespace soccer
{
	class cPlayer;

	class cFormationSetting
	{
	public:
		cFormationSetting();
		virtual ~cFormationSetting();

		bool Init(graphic::cRenderer &renderer);
		bool Update(const float deltaSeconds);
		void Render(graphic::cRenderer &renderer);
		void Clear();


	public:
		cHalfField m_field;
		cHalfFormation m_formation;
		vector<cPlayer*> m_players;
	};

}