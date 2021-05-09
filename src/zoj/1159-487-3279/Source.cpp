#include <iostream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

unordered_map<char, char> mapping = {
	{ 'A', '2' },
	{ 'B', '2' },
	{ 'C', '2' },
	{ 'D', '3' },
	{ 'E', '3' },
	{ 'F', '3' },
	{ 'G', '4' },
	{ 'H', '4' },
	{ 'I', '4' },
	{ 'J', '5' },
	{ 'K', '5' },
	{ 'L', '5' },
	{ 'M', '6' },
	{ 'N', '6' },
	{ 'O', '6' },
	{ 'P', '7' },
	{ 'R', '7' },
	{ 'S', '7' },
	{ 'T', '8' },
	{ 'U', '8' },
	{ 'V', '8' },
	{ 'W', '9' },
	{ 'X', '9' },
	{ 'Y', '9' }
};

char map_char(char c)
{
	auto it = mapping.find(c);
	if (it != mapping.end())
	{
		return it->second;
	}

	return c;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		unordered_map<string, int> m;

		for (int j = 0; j < n; j++)
		{
			string line;
			cin >> line;

			ostringstream oss;
			int count = 0;

			for (auto c : line)
			{
				char c1 = map_char(c);
				if (c1 != '-')
				{
					oss << c1;
					count++;
					if (count == 3)
					{
						oss << '-';
					}
				}
			}

			m[oss.str()] ++;
		}

		if (i != 0)
		{
			cout << endl;
		}

		map<string, int> result;
		bool dup = false;
		for (auto it : m)
		{
			if (it.second > 1)
			{
				dup = true;
				result[it.first] = it.second;
			}
		}

		for (auto it : result)
		{
			cout << it.first << " " << it.second << endl;
		}

		if (!dup)
		{
			cout << "No duplicates." << endl;
		}
	}

	return 0;
}