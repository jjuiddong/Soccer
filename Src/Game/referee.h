//
// 2016-05-14, jjuiddong
//
// 심판 객체, 게임을 진행하고, 전체 흐름을 판단한다.
//	 구현된 내용 없음.
//
#pragma once


namespace soccer
{

	class cReferee 
	{
	public:
		cReferee();
		virtual ~cReferee();

		bool Init();
		bool Update(const float deltaSeconds);


	};

}
