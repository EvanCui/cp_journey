#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

void input(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void compete(int ai, int bi, int& ap)
{
	if (bi - ai == 1)
	{
		ap += ai == 1 ? 6 : (ai + bi);
	}
	else if (ai - bi > 1)
	{
		ap += ai;
	}
}

int main()
{
	int n;
	bool first = true;
	while (cin >> n)
	{
		if (n == 0) break;

		if (!first)
		{
			cout << endl;
		}
		else
		{
			first = false;
		}

		int a[20], b[20];
		input(a, n);
		input(b, n);

		int ap = 0, bp = 0;

		for (int i = 0; i < n; i++)
		{
			if (a[i] == b[i]) continue;
			compete(a[i], b[i], ap);
			compete(b[i], a[i], bp);
		}

		cout << "A has " << ap << " points. B has " << bp << " points." << endl;
	}

	return 0;
}