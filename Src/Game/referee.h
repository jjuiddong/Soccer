//
// 2016-05-14, jjuiddong
//
// ���� ��ü, ������ �����ϰ�, ��ü �帧�� �Ǵ��Ѵ�.
//	 ������ ���� ����.
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
