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

	// Base case: when source and
	// destination are same
	if (n == 1)
		return 0;

	// Traverse through all the points
	// reachable from arr[l]
	// Recursivel, get the minimum number
	// of jumps needed to reach arr[h] from
	// these reachable points
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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int arr[] = { 1, 3, 6, 3, 2,
	              3, 6, 8, 9, 5
	            };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum number of jumps to";
	cout << " reach the end is " << minJumps(arr, n);
	return 0;
}

