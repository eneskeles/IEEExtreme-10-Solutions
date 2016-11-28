#include <bits/stdc++.h>
#include <cmath>
using namespace std ;

typedef long long unsigned llu ; 

int main()
{
	int T; 
	llu arr[70];

	arr[0] = 1;

	llu k,N;

	cin>>T;

	for ( int i = 1; i <= 63 ; ++i)
		arr[i] = arr[i-1]*2; 

	while (T--)
	{
		
		cin>> N;
		
		int i ;
		for ( i = 0 ; ; ++i)
			if ( arr[i] > N)
				break; 
		
		--i;

		cout << (long long)((N-arr[i])*2+1) << endl;
	
	}

	return 0;
}
