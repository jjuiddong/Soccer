
#include "stdafx.h"
#include "halfformation.h"

using namespace soccer;

cHalfFormation::cHalfFormation()
{
}

cHalfFormation::~cHalfFormation()
{
}


// �����̼� ���� ����
// x,y
// x,y
// ��Ű�۸� ������ �� 11 ���� ��ġ ������ �����ϰ� �ִ�.
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


// �����̼� ������ �ؽ�Ʈ ���Ͽ� �����Ѵ�.
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


// ������ ��ġ�� �����Ѵ�.
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


// �ʵ���� �÷����� ��ġ�� HalfFormation ��ǥ��� �����Ѵ�.
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
