#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

int load()
{
	int ret = 0;
	for (int i = 0; i < 5; i++)
	{
		int a;
		cin >> a;
		ret += a;
	}

	return ret;
}

int main()
{
	int a = load();
	int b = load();

	cout << (a >= b ? "Blue" : "Red") << endl;
}