#include<bits/stdc++.h>
using namespace std;

bool hasValidPath( vector<vector<int>>& grid )
{
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<bool>>vis( row, vector<bool>( col, false ) );
	int r = 0, c = 0, val;
	while( true )
	{
		vis[r][c] = true;
		if( r == row - 1 and c == col - 1 )
			return true;
		val = grid[r][c];
		switch( val )
		{
			case 1:
			{
				if( (c - 1 >= 0 and !vis[r][c-1]) and (grid[r-1][c] == 3 or grid[r-1][c] == 5 ) )
				{

				}

				if( grid[r][c] == 3 || grid[r][c] == 5 )
					continue;
				else
					return false;
			}
			break;

			case 2:
			{
				r--;
				if( grid[r][c] == 3 || grid[r][c] == 4 )
					continue;
				else
					return false;
			}
			break;

			case 3:
			{

			}
				
		}
	}
}

/*
int main()
{
	vector< vector<int> >grid = { {2,4,3}, {6,5,2} };
	bool res = hasValidPath(grid);
	cout << res << endl;
}
*/