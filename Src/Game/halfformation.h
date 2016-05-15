//
// 2016-05-15, jjuiddong
//
// 포메이션을 정의하는 클래스
//
// 1  |---------------------|
//     |                               |
//     |        ----------        |
//     |       |    0,0    |        |
//     |-----|---------|------
//  -1                             +1
//  골키퍼 위치를 0,0 으로 하고, 좌우, -1~1, 하프라인을 1로 하는 좌표계
// 포메이션 정보를 읽고, 저장하는 기능을 가진다.
//
#pragma once


namespace soccer
{

	class cHalfFormation
	{
	public:
		cHalfFormation();
		virtual ~cHalfFormation();

		bool Read(const string &fileName);
		bool Write(const string &fileName);


	public:
		Vector2 m_loc[11];
	};

}
