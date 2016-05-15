//
// 2016-05-15, jjuiddong
//
// �����̼��� �����ϴ� Ŭ����
//    
//    y axis
// 1  |---------------------|
//     |                               |
//     |        ----------        |
//     |       |    0,0    |        |
//     |-----|---------|------    x axis -->
//  -1                             +1
//  ��Ű�� ��ġ�� 0,0 ���� �ϰ�, �¿�, -1~1, ���������� 1�� �ϴ� ��ǥ��
// �����̼� ������ �а�, �����ϴ� ����� ������.
//
#pragma once

#include "field.h"


namespace soccer
{

	class cHalfFormation
	{
	public:
		cHalfFormation();
		virtual ~cHalfFormation();

		bool Read(const string &fileName);
		bool Write(const string &fileName);
		void GetPlayerLocation(const MATCH::TYPE match, const cField &field, OUT vector<Vector2> &out);


	public:
		enum { PLAYER_COUNT = 11 };
		Vector2 m_loc[PLAYER_COUNT];
	};

}
