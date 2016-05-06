#pragma once

#include "field.h"
#include "referee.h"
#include "team.h"
#include "ball.h"


namespace soccer
{

	class cMatch
	{
	public:
		cMatch();
		virtual ~cMatch();

		bool Init(graphic::cRenderer &renderer);
		bool Update(const float deltaSeconds);
		void Render(graphic::cRenderer &renderer);


	public:
		cField m_field;
		cReferee m_referee;
		cTeam m_teams[2]; // home, away team
		cBall m_ball;
	};
	
}
