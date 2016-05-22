//
// 2016-05-22, jjuiddong
// 포메이션 정보를 토대로, 경기 중 포메이션 위치를 계산한다.
//
// Formation 좌표계
//    y axis
//  1 |-----|---------|------
//     |       |    0,1    |        |
//     |        ----------        |
//     |                               |
//     |                               |
//     |----------|----------|
//     |          (0, 0.5)         |
//     |                               |
//     |        ----------        |
//     |       |    0,0    |        |
//     |-----|---------|------    x axis -->
//  -1                             +1
//
// 자신의 팀의 골대 중심 위치를 x,y=(0,0), 상대팀 골대 중심위치를 (0,1)로 하는 좌표계.
// 경기 장 중심 위치는 x,y=(0, 0.5) 다.
//
#pragma once


namespace soccer
{

	class cFormation
	{
	public:
		cFormation();
		virtual ~cFormation();

		bool Init(const MATCH::TYPE match, const cField &field);
		bool Read(const string &fileName);
		void Update(const float deltaSeconds, const Vector3 &ballPos);
		//bool Write(const string &fileName);

		bool GetPlayerLocation(const Vector3 &ballPos, OUT vector<Vector2> &out);
		Vector2 FieldToFormation(const Vector3 &pos);
		Vector2 HalfToFormation(const Vector2 &pos);
		Vector2 FormationToField(const Vector2 &pos);


	public:
		MATCH::TYPE m_match;
		const cField *m_field;
		enum { PLAYER_COUNT = 11 };
		Vector2 m_halfLoc[PLAYER_COUNT];// HalfFormation 좌표계
		Vector2 m_loc[PLAYER_COUNT];// Formation 좌표계
	};

}