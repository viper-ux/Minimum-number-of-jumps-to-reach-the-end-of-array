#include<bits/stdc++.h>
#include <chrono>
#define ll long long int
#define ull unsigned long long int
#define fix fixed<<setprecision(10)
#define maxn 1000001

using namespace std;
using namespace std::chrono;

int minJumps(int arr[], int n)
{


	if (n == 1)
		return 0;


	int res = INT_MAX;
	for (int i = n - 2; i >= 0; i--) {
		if (i + arr[i] >= n - 1) {
			int sub_res = minJumps(arr, i + 1);
			if (sub_res != INT_MAX)
				res = min(res, sub_res + 1);
		}
	}

	return res;
}




int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << minJumps(a, n) << endl;


	}
	return 0;
}

