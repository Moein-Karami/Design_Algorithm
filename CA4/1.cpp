#include<bits/stdc++.h>
#define int long long int
#define f first
#define s second

using namespace std;
const int maxn = 1e5 + 5;

typedef pair<int, int> pii;

vector<int> v[maxn];
pii a[maxn];
int par[maxn];
int s[maxn];

int find_par(int x)
{
	if (par[x] == x)
		return x;
	return par[x] = find_par(par[x]);
}

void merge(int x, int y)
{
	par[x] = y;
	s[y] += s[x];
}

int32_t main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].f;
		a[i].s = i;
		a[i].f *= -1;
	}
	for (int i = 1 ; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	sort(a + 1, a + 1 + n);
	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		int x = a[i].s, w = -a[i].f;
		par[x] = x;
		s[x] = 1;
		for (auto u : v[x])
		{
			if (par[u])
			{
				int px = find_par(x), pu = find_par(u);
				if (px != pu)
				{
					ans += s[px] * s[pu] * w;
					merge(px, pu);
				}
			}
		}
	}

	cout << ans;
}
