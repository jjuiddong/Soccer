#pragma once


namespace soccer
{

	class cReferee : public graphic::cCharacter
	{
	public:
		cReferee();
		virtual ~cReferee();

		bool Init();
		bool Move(const float elapseSeconds) override;


	public:
	};

}
