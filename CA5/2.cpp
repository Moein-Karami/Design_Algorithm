#include<bits/stdc++.h>

using namespace std;
const int maxn = 305;
bool a[maxn];
const int s = 0, t = 301;
vector<int> v[maxn];
bool flow[maxn];
int f[maxn][maxn];
int par[maxn];
void dfs(int u)
{
	flow[u] = true;

	for (auto x : v[u])
	{
		if (!flow[x])
		{
			if(f[u][x] <= 0)
			{
				par[x] = u;
				dfs(x);
			}
			if(f[x][u] > 0)
			{
				par[x] = u;
				dfs(x);
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
	{
		int v1, u1;
		cin >> v1 >> u1;
		v[v1].push_back(u1);
		v[u1].push_back(v1);
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i])
			v[i].push_back(t);
		else
			v[s].push_back(i);
	}
	int ans = 0;
	while (true)
	{
		for (int i = 1; i <= n; i++)
			flow[i] = false;
		flow[s] = false;
		flow[t] = false;

		dfs(s);

		if (flow[t] == false)
			break;
		ans ++;
		int u = t;
		while(u != s)
		{
			int x = par[u];
			f[x][u]++;
			f[u][x]--;
			u = x;
		}
	}
	cout << ans;
}