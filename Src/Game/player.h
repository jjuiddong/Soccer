//
// 2016-05-01, jjuiddong
//
#pragma once

namespace soccer
{

	class cPlayer : public graphic::cCharacter
	{
	public:
		cPlayer();
		virtual ~cPlayer();

		bool Init(const sPlayerData &data);
		virtual bool Move(const float elapseSeconds) override;


	public:
		sPlayerData m_data;
	};

}
