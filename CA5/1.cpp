#include<bits/stdc++.h>
#define int long long int
#define f first
#define s second

using namespace std;
typedef pair<int, int> pii;

const int maxn = 105, inf = 1e9;

int a[maxn][maxn];
int f[2* maxn][2 * maxn];
bool flow[2 * maxn];
int par[2 * maxn];
vector<int> v[2 * maxn];
vector<int> rev[2 * maxn];
void dfs(int u)
{
	flow[u] = true;
	// cerr << "u : " << u << " " <<v[u].size() << " " << rev[u].size()<< endl;
	for (auto x : v[u])
	{
		if (flow[x] == false && f[u][x] <= 0)
		{
			par[x] = u;
			dfs(x);
		}
	}
	for (auto x : rev[u])
	{
		if (flow[x] == false && f[x][u] > 0)
		{
			par[x] = u;
			dfs(x);
		}
	}
}

int32_t main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	int r = 1e15, l = 0, mid;

	while(l + 1 < r)
	{
		mid = (l + r) / 2;
		// cerr << mid << endl;
		for (int i = 0; i < 2 * maxn; i++)
			v[i].clear(), rev[i].clear();
		int s = 0, t = 2 * n + 1;
		for (int i = 1; i <= n ; i++)
		{
			v[s].push_back(i);
			rev[i].push_back(s);
			for (int j = 1; j <= n; j++)
				if (a[i][j] <= mid)
					v[i].push_back(n + j), rev[n + j].push_back(i);
		}
		for (int j = n + 1; j <= 2 * n; j++)
			v[j].push_back(t), rev[t].push_back(j);

		for (int i = 0; i < 2 * maxn; i++)
			for (int j = 0; j < 2 * maxn; j++)
				f[i][j] = 0;
		int ans = 0;
		while (true)
		{
			for (int i = 0; i < 2 * maxn; i++)
				flow[i] = false;
			// queue<pii> q;
			// q.push(pii(s, inf));
			// while(q.size())
			// {
			// 	//// cerr << "damn" << endl;
			// 	int u = q.front().f, w = q.front().s;
			// 	q.pop();
			// 	for (auto x : v[u])
			// 	{
			// 		if (flow[x] == 0 && f[u][x] == 0)
			// 		{
			// 			par[x] = u;
			// 			flow[x] = 1;queue<pii> q;
			// q.push(pii(s, inf));
			// while(q.size())
			// {
			// 	//// cerr << "damn" << endl;
			// 	int u = q.front().f, w = q.front().s;
			// 	q.pop();
			// 	for (auto x : v[u])
			// 	{
			// 		if (flow[x] == 0 && f[u][x] == 0)
			// 		{
			// 			par[x] = u;
			// 			flow[x] = 1;
			// 			q.push(pii(x, 1));
			// 		}
			// 	}
			// 	for (auto x : rev[u])
			// 	{
			// 		if (flow[x] == 0 && f[x][u] > 0)
			// 		{
			// 			par[x] = u;
			// 			flow[x] = 1;
			// 			q.push(pii(u, 1));
			// 		}
			// 	}
			// }
			// 			q.push(pii(x, 1));
			// 		}
			// 	}
			// 	for (auto x : rev[u])
			// 	{
			// 		if (flow[x] == 0 && f[x][u] > 0)
			// 		{
			// 			par[x] = u;
			// 			flow[x] = 1;
			// 			q.push(pii(u, 1));
			// 		}
			// 	}
			// }

			dfs(s);

			int u = t;
			// cerr << "flow : " << flow[u] << endl;
			if(flow[u] == false)
				break;
			ans++;
			while(u != s)
			{
				//// cerr << "u : " << u << endl;
				int x = par[u];
				f[x][u] += 1;
				f[u][x] -= 1;
				u = x;
			}
		}
		// cerr << "ans : " << ans << " " << n << endl;
		if (ans == n)
			r = mid;
		else
			l = mid;
	}
	cout << r;
}