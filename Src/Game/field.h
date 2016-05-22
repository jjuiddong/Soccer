//
// 2016-04-30, jjuiddong
// 축구장을 3차원 좌표계로 표현하는 객체
//
//           /--------------------------/
//      /|/                  /                /|/
//     |/  home       /        away |/
//    /                  /                   /
//  /-------------------------/
//   -z                0              +z
//
//
//      +Z axis (away team)
//       -----------|   |------------
//      |        |                 |          |
//      |         ------------           |
//      |                                      |
//      |                   (0,0)           |
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

	class cField
	{
	public:
		cField();
		virtual ~cField();

		bool Init(graphic::cRenderer &renderer);
		void Render(graphic::cRenderer &renderer);


	public:
		enum {LINE_SIZE = 17 ,};
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
