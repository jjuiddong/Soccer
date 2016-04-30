//
// 2016-04-30, jjuiddong
// √‡±∏¿Â ∞¥√º
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
	};

}