#include <bits/stdc++.h>
#define sqr(aa) ((aa)*(aa))
#define dis(aa, bb, cc, dd) ( sqrt(sqr(aa - cc) + sqr(bb - dd))
using namespace std;

int main()
{
	int T; 
	
	cin>>T;
	
	while (T--)
	{
		int x1[50], x2[50], y1[50], y2[50], r[50];
		int n; 

		cin>>n;

		for (int i = 1; i <= n; ++i)
			cin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>r[i];
	
		int count = 0;

		for (double i = -50.0 ; i <= 50.0 ; i += 0.1)
			for (double j = -50; j <= 50.0 ; j += 0.1)
			{
				int k;
				for (k = 1; k <= n; ++k)
					if( (dis(i, j, x1[k], y1[k]) + dis(i, j, x2[k], y2[k]) ) <= r[k])
						break; 
				
				if (k == n+1)
					count++; 
			}

		cout<<(int)round((double)count/10000)<<"%"<<endl; 
	}
}
