//
// 2016-05-10, jjuiddong
//
// Soccer Action 전역 선언
//
#pragma once



namespace TEAM_AI_MSG {
	enum TYPE {
		KICKOFF,

		MAX,
	};
}


namespace PLAYER_AI_MSG {
	enum  TYPE {
		KICKOFF = TEAM_AI_MSG::MAX,

	};

}



// team
#include "actionTeam/teamkickoffaction.h"


// player
#include "actionPlayer/playeractionmain.h"
#include "actionPlayer/playerkickoffaction.h"
