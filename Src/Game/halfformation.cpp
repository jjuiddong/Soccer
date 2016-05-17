
#include "stdafx.h"
#include "halfformation.h"

using namespace soccer;

cHalfFormation::cHalfFormation()
{
}

cHalfFormation::~cHalfFormation()
{
}


// 포메이션 파일 형태
// x,y
// x,y
// 골키퍼를 포함한 총 11 명의 위치 정보를 저장하고 있다.
bool cHalfFormation::Read(const string &fileName)
{
	using namespace std;

	ifstream ifs(fileName);
	if (!ifs.is_open())
		return false;

	int idx = 0;
	char buffer[128];
	while (ifs.getline(buffer, sizeof(buffer)) && (idx < PLAYER_COUNT))
	{
		stringstream ss(buffer);
		string str1, str2, str3;
		ss >> str1 >> str2 >> str3;
		if (str1.empty() && str2.empty() && str3.empty())
			continue;

		if (str3.empty())
		{
			// num, num
			m_loc[idx].x = (float)atof(str1.c_str());
			m_loc[idx].y = (float)atof(str2.c_str());
		}
		else
		{
			// num , num
			m_loc[idx].x = (float)atof(str1.c_str());
			m_loc[idx].y = (float)atof(str3.c_str());
		}
		
		++idx;
	}

	return true;
}


// 포메이션 정보를 텍스트 파일에 저장한다.
// x1, y1
// x2, y2
// ... 
bool cHalfFormation::Write(const string &fileName)
{
	using namespace std;
	std::ofstream ofs(fileName);
	if (!ofs.is_open())
		return false;

	for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		ofs << m_loc[i].x << ", " << m_loc[i].y << endl;
	}

	return true;
}


// 선수의 위치를 리턴한다.
//
//     +Y axis (away team)
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
//     -Y axis (home team)
//
void cHalfFormation::GetPlayerLocation(const MATCH::TYPE match, const cField &field, OUT vector<Vector2> &out)
{
	out.reserve(PLAYER_COUNT);

	for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		Vector2 loc;
		loc.x = m_loc[i].x * field.m_width * 0.5f;
		loc.y = field.m_height * 0.5f - (m_loc[i].y * field.m_height * 0.5f);

		// home
		if (match == MATCH::HOME)
		{
			loc.y = -loc.y;
		}
		else
		{ // away
		}

		out.push_back(loc);
	}
}


// 필드상의 플레어의 위치를 HalfFormation 좌표계로 저장한다.
void cHalfFormation::SetPlayerLocation(const cField &field, const vector<Vector3> &locs)
{
	SetPlayerLocation(field.m_width, field.m_height, locs);
}


void cHalfFormation::SetPlayerLocation(const cHalfField &field, const vector<Vector3> &locs)
{
	SetPlayerLocation(field.m_width, field.m_height, locs);
}


void cHalfFormation::SetPlayerLocation(const float fieldWidth, const float fieldHeight, const vector<Vector3> &locs)
{
	const float hw = fieldWidth * 0.5f;
	const float hh = fieldHeight * 0.5f;
	for (int i = 0; i < (int)locs.size(); ++i)
	{
		Vector2 loc;
		loc.x = locs[i].x  / hw;
		loc.y = (hh + locs[i].z) / hh;
		loc.x = max(-1, loc.x);
		loc.y = max(0, loc.y);
		loc.x = min(1, loc.x);
		loc.y = min(1, loc.y);

		m_loc[i] = loc;
	}
}
