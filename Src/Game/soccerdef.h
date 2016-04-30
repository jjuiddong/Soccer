//
// 2016-05-01, jjuiddong
//
#pragma once


namespace soccer
{

	namespace POSITION
	{
		enum TYPE {
			FW, MF, DF, GK,
		};
	}


	struct sPlayerData
	{
		POSITION::TYPE m_position;

	};


}

