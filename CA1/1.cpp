#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int maxn = 5e3 + 3;
const int inf = 1e9;
int a[maxn];

int solve (int l, int r, int h)
{
	if (l + 1 == r && a[l] > h)
		return 1;
	if (l >= r)
		return 0;
	int mini = inf;
	int ans = r - l;

	for (int i = l; i < r; i++)
		mini = min(mini, a[i]);

	int new_ans = mini - h;
	while (a[l] == mini && l < r)
		l++;

	for (int i = l + 1; i < r; i++)
	{
		if (a[i] == mini)
		{
			new_ans += solve(l, i, mini);
			while (a[i] == mini && i < r)
				i++;
			l = i;
		}
	}
	new_ans += solve (l, r, mini);
	return min(new_ans, ans);
}

int32_t main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << solve(0, n, 0);
}