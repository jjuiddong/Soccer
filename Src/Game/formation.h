//
// 2016-05-22, jjuiddong
// �����̼� ������ ����, ��� �� �����̼� ��ġ�� ����Ѵ�.
//
// Formation ��ǥ��
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
// �ڽ��� ���� ��� �߽� ��ġ�� x,y=(0,0), ����� ��� �߽���ġ�� (0,1)�� �ϴ� ��ǥ��.
// ��� �� �߽� ��ġ�� x,y=(0, 0.5) ��.
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
		Vector2 m_halfLoc[PLAYER_COUNT];// HalfFormation ��ǥ��
		Vector2 m_loc[PLAYER_COUNT];// Formation ��ǥ��
	};

}