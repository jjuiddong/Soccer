//
// 2016-05-15, jjuiddong
//
// 포메이션을 정의하는 클래스
// 
// HalfFormation 좌표계
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
#include "halffield.h"


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
		void SetPlayerLocation(const cField &field, const vector<Vector3> &locs);
		void SetPlayerLocation(const cHalfField &field, const vector<Vector3> &locs);
		void SetPlayerLocation(const float fieldWidth, const float fieldHeight, const vector<Vector3> &locs);


	public:
		enum { PLAYER_COUNT = 11 };
		Vector2 m_loc[PLAYER_COUNT]; // halfformation 좌표계
	};

}
