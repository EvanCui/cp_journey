#include <iostream>
#include <map>
#include <string.h>
#include <algorithm>

using namespace std;

// score matrix
map<char, map<char, int>> m = {
	{ 'A', {
		{ 'A', 5 },
		{ 'C', -1 },
		{ 'G', -2 },
		{ 'T', -1 },
		{ ' ', -3 },
	} },
	{ 'C', {
		{ 'A', -1 },
		{ 'C', 5 },
		{ 'G', -3 },
		{ 'T', -2 },
		{ ' ', -4 },
	} },
	{ 'G', {
		{ 'A', -2 },
		{ 'C', -3 },
		{ 'G', 5 },
		{ 'T', -2 },
		{ ' ', -2 },
	} },
	{ 'T', {
		{ 'A', -1 },
		{ 'C', -2 },
		{ 'G', -2 },
		{ 'T', 5 },
		{ ' ', -1 },
	} },
	{ ' ', {
		{ 'A', -3 },
		{ 'C', -4 },
		{ 'G', -2 },
		{ 'T', -1 },
	} },
};

// the score function
int score(char c1, char c2)
{
	return m[c1][c2];
}

int similarity(int l1, char* g1, int l2, char* g2)
{
	// DP state transition equation:
	// dp[i][j] = max(dp[i-1][j-1] + score(i,j), dp[i-1][j] + score(i,' '), dp[i][j-1] + score(' ',j))
	// 2 dimensions DP simplified to 1 dimension DP

	int dp[101];
	memset(dp, 0, sizeof(dp));

	// first line initialization
	for (int j = 1; j <= l2; j++)
	{
		dp[j] = dp[j - 1] + score(' ', g2[j]);
	}

	for (int i = 1; i <= l1; i++)
	{
		// old is dp[i-1][j-1]
		int old = dp[0];
		dp[0] = old + score(' ', g1[i]);

		for (int j = 1; j <= l2; j++)
		{
			// result1 is dp[i-1][j-1] + score(i, j)
			int result1 = old + score(g1[i], g2[j]);

			// save old
			old = dp[j];

			// shortcut for i == j
			if (g1[i] != g2[j])
			{
				// result2 is dp[i][j-1] + score(' ',j)
				int result2 = dp[j - 1] + score(' ', g2[j]);
				// result3 is dp[i-1][j] + score(i,' ')
				int result3 = dp[j] + score(' ', g1[i]);
				result1 = max(result1, result2);
				result1 = max(result1, result3);
			}

			dp[j] = result1;
		}
	}

	return dp[l2];
}

int main()
{
	const int N = 102;
	int t;

	cin >> t;

	while (t--)
	{
		char g1[N];
		char g2[N];

		int l1, l2;
		cin >> l1;
		cin.getline(g1, N);
		cin >> l2;
		cin.getline(g2, N);

		cout << similarity(l1, g1, l2, g2) << endl;
	}

	return 0;
}