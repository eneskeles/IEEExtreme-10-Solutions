#include <bits/stdc++.h> 
using namespace std;

int main()
{
	int T, N, K;
	int arr[100005];	
	
	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d %d",&N, &K); 

		for (int i = 1; i <= N; ++i)	
			cin>>arr[i];		

		priority_queue<pair<int,int> > PQ;
			
		sort(arr + 1, arr+N+1);
		
		for (int i = 2; i <= N; ++i)
			PQ.push(make_pair(arr[i] - arr[i-1], i - 1));

		vector<int> V;

		for (int i = 1; i <= K-1; ++i)
		{
			V.push_back(PQ.top().second); 
			PQ.pop(); 
		}
			
		sort(V.begin(),V.end());
		
		int sum = 0;
		int last = 0;

		for (int i = 0; i < V.size(); ++i )
		{
			sum += arr[V[i]] - arr[last+1];
			last = V[i]; 
		}
	
		sum += arr[N] - arr[last+1];

		cout<<sum<<endl;
	}
	
	return 0;
}
