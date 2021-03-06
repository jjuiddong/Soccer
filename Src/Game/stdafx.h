#pragma once


#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "../../../Common/Common/Common.h"
#include "../../../Common/Network/Network.h"
#include "../../../Common/Graphic/Graphic.h"
#include "../../../Common/Framework/framework.h"

#include "soccerdef.h"
#include "soccerai.h"
#include "match.h"

namespace soccer { class cMatch; }
extern soccer::cMatch *g_match;


namespace SCENE {
	enum TYPE {
		FIELD,
		STRATEGY,
		FORMATION,
	};
}
