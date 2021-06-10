#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 3;

int d[maxn];
int l[maxn];

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> d[i];
	for (int i = 1; i <= n; i++)
		cin >> l[i];

	int maxl = 0;
	int ans = 0;
	int c = 0;
	for (int i = 1; i <= n; i++)
	{
		c += l[i];
		maxl = max(maxl, l[i]);
		while (c < d[i])
		{
			c += maxl;
			ans += k;
		}
		ans += d[i];
		c -= d[i];
	}
	cout << ans;
}