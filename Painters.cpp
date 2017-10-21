#include <cstdio>
#include <iostream>
#define INF 1<<30
using namespace std;

int DP[25][25][505];
int n, arr[505];

int solve(int c1, int c2, int i)
{
	if (DP[c1][c2][i] != -1)
		return DP[c1][c2][i];

	if (c1 != arr[i] && c2 != arr[i])
		return DP[c1][c2][i] = 1 + min(solve(arr[i], c2, i + 1), solve(c1, arr[i], i + 1));

	else if (c1 == arr[i] || c2 == arr[i]) 
		return DP[c1][c2][i] = solve(c1, c2, i + 1);
	
	return -1 ;
}

int main()
{
	int T;

	cin>>T;

	while (T--)
	{
		cin>>n;

		for (int i = 1; i <= n; ++i)
			cin>>arr[i];
		
		for (int i = 0; i < 25; ++i)
			for (int j =0; j < 25; ++j)
				for (int k = 0; k < 505; ++k)
				{
					DP[i][j][k] = -1;
					
					if (k == n+1) 
						DP[i][j][k] = 0;
				}
		
		cout<<solve(21, 21, 1)<<endl; 
	}
	
	return 0;
}
