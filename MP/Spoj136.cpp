#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int x = n, dem = 0;
	int a[300005];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = n - 1; i >= 0; i--)
	{
		if(a[i] == x) x--;
		else dem++;
	}
	cout << dem;
	return 0;
}