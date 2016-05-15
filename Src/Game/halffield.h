//
// 2016-05-15, jjuiddong 
//
// �ʵ��� ���� ����ϴ� Ŭ����
// �����̼� �������̴�.
//
//
//      +Z axis (away team)
//                         (0,0)           
//       ------------|------------> +X axis
//      |                                      |
//      |                                      |
//      |         ------------           |
//      |        |                 |          |
//       -----------|   |------------
//      -Z axis (home team)
//
#pragma once


namespace soccer
{

	class cHalfField
	{
	public:
		cHalfField();
		virtual ~cHalfField();
		
		bool Init(graphic::cRenderer &renderer);
		void Render(graphic::cRenderer &renderer);


	public:
		enum { LINE_SIZE = 11, };
		graphic::cLine m_lines[LINE_SIZE];
		graphic::cCircleLine m_circle;
		float m_width;
		float m_height;
		float m_penaltyWidth;
		float m_penaltyHeight;
		float m_goalAreaWidth;
		float m_goalAreaHeight;
	};

}
