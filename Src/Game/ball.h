//
// 2016-05-06, jjuiddong
//
// Ãà±¸°ø °´Ã¼
//
#pragma once

namespace soccer
{

	class cBall : public graphic::cCharacter
	{
	public:
		cBall();
		virtual ~cBall();

		bool Init(graphic::cRenderer &renderer);
		virtual bool Update(const float deltaSeconds) override;
		//virtual void Render(graphic::cRenderer &renderer, const Matrix44 &tm = Matrix44::Identity) override;

		virtual void Clear();


	public:
		graphic::cSphere *m_sphere;
	};

}
