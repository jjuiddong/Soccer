//
// 2016-05-15, jjuiddong 
//
// 필드의 반을 출력하는 클래스
// 포메이션 설정용이다.
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
