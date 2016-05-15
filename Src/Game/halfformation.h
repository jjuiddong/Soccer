//
// 2016-05-15, jjuiddong
//
// 포메이션을 정의하는 클래스
//    
//    y axis
// 1  |---------------------|
//     |                               |
//     |        ----------        |
//     |       |    0,0    |        |
//     |-----|---------|------    x axis -->
//  -1                             +1
//  골키퍼 위치를 0,0 으로 하고, 좌우, -1~1, 하프라인을 1로 하는 좌표계
// 포메이션 정보를 읽고, 저장하는 기능을 가진다.
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
