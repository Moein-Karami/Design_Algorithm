#include<iostream>
#include<unordered_map>
#include<map>

using namespace std;

const int inf = 1e5;
const int maxn = 1e4 + 100;
//map<int ,map<int, int>> dp[maxn];
int dp[2][maxn * 3];
int m[maxn], v[maxn];
int n;
int k;
// int solve(int t, int y, int z)
// {
// 	if (t > n)
// 	{
// 		if (double(y) / double(z) == k)
// 			return 0;
// 		return -inf;
// 	}
// 	if (dp[x][y].find(z) != dp[x][y].end())
// 		return dp[x][y][z];
// 	return dp[x][y][z] = max(solve(x + 1, y, z), (int)m[x] + solve(x + 1, y + 1, ((double)y * z + a[x]) / double(y + 1)));
// }

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> m[i] >> v[i];
		v[i] *= k;
	}
	int tmp = 1 - n % 2;

	for (int i = 0; i < 3 * maxn; i++)
		dp[tmp][i] = -inf;
	dp[tmp][maxn] = 0;

	for(int i = n; i >= 1; i--)
	{
		tmp = i % 2;
		int val = m[i] - v[i];
		for (int j = 0; j < maxn*3; j++)
		{
			dp[tmp][j] = dp[1 - tmp][j];
			if ( j + val <0 || j + val >= maxn * 3)
				continue;
			dp[tmp][j] = max(dp[tmp][j], m[i] + dp[1 - tmp][j + val]);
		}
	}

	cout << dp[1][maxn];
}