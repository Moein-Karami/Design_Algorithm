#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int d[maxn];
vector<int> v[maxn];

void dfs(int par, int x)
{
	d[x] = d[par] + 1;
	for (auto u : v[x])
		if (u != par)
			dfs(x, u);
}

int32_t main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	d[0] = -1;
	dfs(0, 1);

	int root = 1;
	for (int i = 1; i <= n; i++)
		if (d[i] > d[root])
			root = i;
	dfs(0, root);

	int ans = 0;

	for (int i = 1; i <= n; i++)
		ans += d[i];
	cout << ans;
}