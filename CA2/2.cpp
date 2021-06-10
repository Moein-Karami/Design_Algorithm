#include<iostream>
#include<string>

#define int long long int

using namespace std;

const int maxn = 3e2 + 3;
const int inf = 1e9;

int dp[maxn][maxn][30][3];

string s, t;

int solve(int x, int y, int c, int dir)
{
	if (x < 0 || y < 0)
		return inf;
	if (x >= s.size())
		return inf;
	if (y == t.size())
		return 0;
	if (dp[x][y][c][dir])
		return dp[x][y][c][dir];

	dp[x][y][c][dir] = 1 + solve(x + 1 + 2 * dir * (-1), y, c, dir);

	int& ret = dp[x][y][c][dir];

	if (s[x] - 'a' == c)
	{
		if (x > 0)
			if (s[x - 1] == t[y])
				ret = min(ret, 1 + min(solve(x - 1, y + 1, t[y] - 'a', 0), solve(x - 1, y + 1, t[y] - 'a', 1)));

		if (x + 1 < s.size())
			if (s[x + 1] == t[y])
				ret = min(ret, 1 + min(solve(x + 1, y + 1, t[y] - 'a', 0), solve(x + 1, y + 1, t[y] - 'a', 1)));
	}

	return ret;
}

int32_t main()
{
	int n, m;
	cin >> n >> m;
	cin >> s >> t;
	int ans = inf;

	for (int i = 0; i < s.size(); i++)
		if (s[i] == t[0])
			ans = min(ans, min(solve(i, 1, s[i] - 'a', 0), solve(i, 1, s[i] - 'a', 1)));

	if (ans == inf)
		ans = -1;

	cout << ans;
}