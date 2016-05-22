//
// 2016-05-10, jjuiddong
//
// Soccer Action 전역 선언
//
#pragma once



namespace TEAM_AI_MSG {
	enum TYPE {
		KICKOFF,
		PLAYGAME,

		MAX,
	};
}


namespace PLAYER_AI_MSG {
	enum  TYPE {
		KICKOFF = TEAM_AI_MSG::MAX,
		PLAYGAME,
		FORMATION_MOVE,
	};

}



// team
#include "actionTeam/teamkickoffaction.h"
#include "actionTeam/teamplaygameaction.h"
#include "actionTeam/teamoffenseaction.h"


// player
#include "actionPlayer/playeractionmain.h"
#include "actionPlayer/playerkickoffaction.h"
#include "actionPlayer/playerformationmoveaction.h"
