
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

	for (int i = 0; i < 11; ++i)
	{
		ofs << m_loc[i].x << ", " << m_loc[i].y << endl;
	}

	return true;
}

