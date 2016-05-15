//
// 2016-05-15, jjuiddong
//
// �����̼� ���� ��ü
// ȭ�鿡 Ȩ�� �ʵ�� ���� ����ϰ�, ���콺�� Ŭ���� ��������
// �����̼��� ������ �� �ְ� �Ѵ�.
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