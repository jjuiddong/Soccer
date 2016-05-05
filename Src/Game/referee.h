#pragma once


namespace soccer
{

	class cReferee : public graphic::cCharacter
	{
	public:
		cReferee();
		virtual ~cReferee();

		bool Init();
		bool Update(const float deltaSeconds) override;


	public:
	};

}
