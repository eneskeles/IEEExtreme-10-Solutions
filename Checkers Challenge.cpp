#include <bits/stdc++.h>

#define ctrl(aa, bb) ( aa >= 0 && aa < 8 && bb >= 0 && bb < 8)

using namespace std;


char arr[10][10];

int DFS(int x, int y, bool king, int numBlack, int forbidden)
{
	if ( !king && x == 0)
		return DFS(x, y, 1, numBlack, 1);

	if ( numBlack == 0)
		return 1;
	
	int sum = 0; 

	if ( king )
	{
		if ( forbidden != 2)
			for ( int i = x-1; i > 0 ; --i)
				if ( arr[i][y] == 'x' && arr[i-1][y] == '.')
				{
					arr[i][y] = '.'; 
					for ( int j =  i-1; j >= 0 && arr[j][y] == '.'; --j)
					{	
						if ( arr[j][y] == 'x') break;
						sum += DFS( j, y, king, numBlack - 1, 1);
					}
					arr[i][y] = 'x';
					break; 
				}
		
		if ( forbidden != 1)
			for ( int i = x+1; i < 7 ; ++i)
				if ( arr[i][y] == 'x' && arr[i+1][y] == '.')
				{
					arr[i][y] = '.';
					for ( int j = i+1; j < 8 && arr[j][y] == '.'; ++j)
						sum += DFS( j, y, king, numBlack - 1, 2);
					arr[i][y] = 'x';
					break; 
				}
	
		if ( forbidden != 4 )
			for ( int i = y-1; i > 0 ; --i)
				if ( arr[x][i] == 'x' && arr[x][i-1] == '.' )
				{
					arr[x][i] = '.'; 
					for ( int j = i-1; j >= 0 && arr[x][j] == '.'; --j)
						sum += DFS( x, j, king, numBlack - 1, 3);
					arr[x][i] = 'x';
					break;
				}

		if ( forbidden != 3)
			for ( int i = y+1; i < 7 ; ++i)
				if ( arr[x][i] == 'x' && arr[x][i+1] == '.' )
				{
					arr[x][i] = '.'; 
					for ( int j = i+1; j < 8 && arr[x][j] == '.'; ++j)
						sum += DFS(x, j, king, numBlack - 1, 4);			
					arr[x][i] = 'x';
					break; 
				}
	}
	else 
	{
		if ( ctrl(x-1,y) && arr[x-1][y] == 'x' && ctrl(x-2,y)  && arr[x-2][y] == '.')
		{
			arr[x-1][y] = '.'; 
			sum += DFS(x-2, y, king, numBlack -1, forbidden);
			arr[x-1][y] = 'x';
		}
		
		if ( ctrl(x,y+1) && arr[x][y+1] == 'x' && ctrl(x,y+2)  && arr[x][y+2] == '.')
		{
			arr[x][y+1] = '.'; 
			sum += DFS(x, y+2, king, numBlack -1, forbidden);
			arr[x][y+1] = 'x';
		}
		
		if ( ctrl(x,y-1) && arr[x][y-1] == 'x' && ctrl(x,y-2)  && arr[x][y-2] == '.')
		{
			arr[x][y-1] = '.'; 
			sum += DFS(x, y-2, king, numBlack -1, forbidden);
			arr[x][y-1] = 'x';
		}
	}

	return sum; 
}
int main()
{
	int T; 

	cin>>T;
	
	while( T--)
	{

		for ( int i = 0; i < 8; ++i)
			scanf("%s",arr[i]); 
		
		int numB = 0;

		for ( int i = 0; i < 8; ++i)
			for ( int j = 0; j < 8; ++j)
				if ( arr[i][j] == 'x')
					numB++; 
		
		for ( int i = 0; i < 8; ++i)
			for ( int j = 0; j < 8; ++j)
				if ( arr[i][j]== 'o')
				{
					arr[i][j] = '.';
					cout<<DFS(i, j, (i == 0), numB, -1) <<endl;
				}
	}
	return 0;
}
