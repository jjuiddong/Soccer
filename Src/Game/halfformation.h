//
// 2016-05-15, jjuiddong
//
// �����̼��� �����ϴ� Ŭ����
//
// 1  |---------------------|
//     |                               |
//     |        ----------        |
//     |       |    0,0    |        |
//     |-----|---------|------
//  -1                             +1
//  ��Ű�� ��ġ�� 0,0 ���� �ϰ�, �¿�, -1~1, ���������� 1�� �ϴ� ��ǥ��
// �����̼� ������ �а�, �����ϴ� ����� ������.
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
