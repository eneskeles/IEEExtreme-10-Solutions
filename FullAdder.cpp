#include <bits/stdc++.h>
using namespace std ;

int main()
{
	int N;
	string a, b, c, d, sym; 
	int hash[400];
	char t ;

	cin>>N>>sym; 

	for (int i = 0; i < sym.size(); ++i)
		hash[sym[i]] = i;
	
	cin>>a>>t; 
	cin>>b;
	cin>>c>>d;

	int carry = 0; 
	string tempp, sum = "";

	int i = a.size() - 1;
	int j = b.size() - 1;
	
	while (i >= 0 || j >= 0)
	{
		if (i < 0)
		{
			sum += (char)sym[ (carry + hash[b[j]])%N]; 
			carry = (carry + hash[b[j]])/N; 
		}
		else if (j < 0)
		{
			sum += (char)sym[(carry + hash[a[i]])%N];
			carry = (carry + hash[a[i]])/N;
		}
		else 
		{
			sum += (char)sym[ (carry + hash[a[i]] + hash[b[j]])% N];
			carry = (carry + hash[a[i]] + hash[b[j]])/N;  
		}
		i--; j--;
	}

	reverse(sum.begin(),sum.end());
	
	cout<<N<<" "<<sym<<endl;
	cout.width(c.size()); 
	cout<<right<<a<<endl;
	cout<<"+";
	cout.width(c.size() - 1);
	cout<<right<<b<<endl;
	cout<<c<<endl;
	cout.width(c.size());
	cout<<right<<sum<<endl;

	return 0;
}
