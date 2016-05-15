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


	namespace MATCH
	{
		enum TYPE {
			HOME,
			AWAY,
		};
	}


	struct sPlayerData
	{
		POSITION::TYPE position;
		Vector2 location;
		float scale;
	};

}
