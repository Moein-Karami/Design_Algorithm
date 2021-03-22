#include<iostream>

#define int long long int

using namespace std;

const int maxn = 5e2 + 5, inf = 1e9;

int a[maxn][maxn];
int dp[maxn][maxn];

int32_t main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j], dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + a[i][j] - dp[i - 1][j - 1];

	int ans = inf;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int q = j; q <= m; q++)
			{
				int len = q - j + 1;
				int h = k / len + ((k % len) != 0) - 1;
				if (i + h > n)
					continue;
				len--;

				ans = min(ans, dp[i + h][j + len] - dp[i + h][j - 1] - dp[i - 1][j + len] + dp[i - 1][j - 1]);
			}
		}
	}

	cout << ans;
}