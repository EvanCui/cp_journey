#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

struct step
{
	operator bool() const
	{
		return start != 0 || end != 0;
	}

	friend std::istream& operator>>(std::istream& in, step& s)
	{
		in >> s.start >> s.end;

		if (s.start == 0 && s.end == 0)
		{
			return in;
		}

		char d;

		in >> d;

		switch (d)
		{
		case 'U':
			d = 'D';
			break;
		case 'D':
			d = 'U';
			break;
		case 'R':
			d = 'L';
			break;
		case 'L':
			d = 'R';
			break;
		default:
			break;
		}

		s.direction = d;

		return in;
	}

	int start;
	int end;
	char direction;
};

const int N = 100;
int g[N][N];

void walk(std::deque<pair<int, int>>& q, const step& s, int stepnum, int m, int n)
{
	int count = q.size();

	while (count--)
	{
		auto current = q.front();
		q.pop_front();

		for (int i = 1; i <= s.end; i++)
		{
			pair<int, int> next = current;
			switch (s.direction)
			{
			case 'U':
				next.first -= i;
				break;
			case 'D':
				next.first += i;
				break;
			case 'L':
				next.second -= i;
				break;
			case 'R':
				next.second += i;
				break;
			default:
				break;
			}

			if (next.first < 0 || next.second < 0 || next.first >= m || next.second >= n)
			{
				break;
			}

			if (g[next.first][next.second] == 1)
			{
				break;
			}

			if (g[next.first][next.second] == stepnum || i < s.start)
			{
				continue;
			}

			g[next.first][next.second] = stepnum;
			q.push_back(next);
		}
	}
}

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		memset(g, 0, sizeof(g));

		int n, m;
		cin >> m >> n;
		std::deque<std::pair<int, int>> q;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> g[i][j];
				if (g[i][j] == 0)
				{
					q.push_back(pair<int, int>(i, j));
				}
			}
		}

		vector<step> steps;
		step s;

		while (cin >> s && s)
		{
			steps.push_back(s);
		}

		for (int i = steps.size() - 1; i >= 0; i--)
		{
			walk(q, steps[i], i + 2, m, n);
		}

		cout << q.size() << endl;
	}

	return 0;
}