#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int maxn = 1e5 + 5;
const int inf = 1e9 + 10;

int a[maxn];
int ans[maxn];

int32_t main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++)
		cin >> a[i];
	for (int i = 1; i <= k; i++)
		ans [i] = a[i];
	int l = 1;
	for (int i = k + 1; i < n; i++)
	{
		if (i - l > k)
			l++;
		while (ans[i] < a[i] && l < i)
		{
			int t = min (a[i] - ans[i], ans[l]);
			ans[l] -= t;
			ans[i] += t;
			if (ans[l] == 0)
				l++;
			else
				break;
		}
	}
	int answer = 0;
	for(int i = n - k; i < n; i++)
		answer += ans[i];
	cout << answer;
}