#include<bits/stdc++.h>
using namespace std;

vector<int>pathEdges;

bool dfs( vector<vector<int>>& gp, vector<bool>&vis , int root, int target )
{
	pathEdges.push_back( root );
	vis[root] = true;

	if( root == target )
		return true;

	for( int i = 0; i < gp[root].size(); i++ )
	{
		int v = gp[root][i];
		if( !vis[v] )
		{
			//pathEdges.push_back( v );
			if( dfs( gp, vis, v, target ) == true )
			{
				return true;
			}
			pathEdges.pop_back();
		}
	}
	return false;
}

void pnt( vector<vector<int>>& gp )
{
	for( int i = 0; i < gp.size(); i++ )
	{
		cout << i << "->";
		for( int j = 0; j < gp[i].size(); j++ )
			cout << gp[i][j] << " ";
		cout << endl;
	}
}
double frogPosition( int n, vector<vector<int>>& edges, int t, int target )
{
	

	vector<vector<int> >gp( n + 1 );
	vector<bool > vis( n + 1, false );
	for( int i = 0; i < edges.size(); i++ )
	{
		int u = edges[i][0];
		int v = edges[i][1];
		gp[u].push_back( v );
		gp[v].push_back( u );
	}
	//pnt( gp );
	bool res = dfs( gp, vis, 1, target );

	cout << "path= "; for( auto x : pathEdges ) cout << x << " "; cout << endl;

	double ans = 0.0;
	int loopcnt = 0;
	if( t < ( pathEdges.size() - 1 ) )
	{
		return 0.0;
	}
	else if( t >= ( pathEdges.size() - 1 ) )
	{
		if( t > pathEdges.size() - 1 and gp[target].size() > 1 )
		{
			return 0.0;
		}
		else
		{
			ans = 1.0;
			for( int i = 0; i < pathEdges.size() - 1; i++ )
			{
				int u, sz;
				u = pathEdges[i];
				sz = gp[u].size();
				if( u != 1 )
					sz = sz - 1;
				double time = ( 1.0 / ( sz * 1.0 ) );
				ans = ans * time;
				loopcnt++;
			}

		}

	}
	if( edges.size() == 0 )
		return 1.0;
	else if( loopcnt > 0  )
		return ans;
	else
		return 0.0;

}

/*
int main()
{
	int n = 9;
	//vector<vector<int>>edges = { {2,1},{3,2},{4,1},{5,1},{6,4}, {7,1},{8,7} };
	//vector<vector<int>>edges = { {1,2}, {1,3}, {1,7}, {2,4}, {2,6}, {3,5} };
	//vector<vector<int>>edges = { {2,1},{3,2},{4,1} };
	vector<vector<int>>edges = { {2,1},{3,2},{4,3},{5,3},{6,5},{7,3},{8,4},{9,5} };
	//vector<vector<int>>edges = { };
	int t = 9;
	int target = 1;

	cout << "ans=" << frogPosition( n, edges, t, target );
}
*/