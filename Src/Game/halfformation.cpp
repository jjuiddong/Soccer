
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
	while (ifs.getline(buffer, sizeof(buffer)) && (idx < 11))
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

	for (int i = 0; i < 11; ++i)
	{
		ofs << m_loc[i].x << ", " << m_loc[i].y << endl;
	}

	return true;
}

