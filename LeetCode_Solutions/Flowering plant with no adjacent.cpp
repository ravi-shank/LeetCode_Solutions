#include<bits/stdc++.h>
using namespace std;

void pntgp( vector<vector<int>>& gp )
{
    for( int i = 0; i < gp.size(); i++ )
    {
        cout << i << "->";
        for( int j = 0; j < gp[i].size(); j++ )
            cout << gp[i][j] << " ";
        cout << endl;

    }
}
vector<int> gardenNoAdj( int N, vector<vector<int>>& paths )
{

    vector<vector<int> >gp( N + 1 );
    vector<int>color( N, -1 );

    for( int i = 0; i < paths.size(); i++ )
    {
        gp[paths[i][0]].push_back( paths[i][1] );
        gp[paths[i][1]].push_back( paths[i][0] );
    }
    pntgp( gp );
    for( int k = 1; k <= N; k++ )
    {
        if( color[k - 1] != -1 )
            continue;
        color[k-1] = 1;
        queue<pair<int, int> >q; // <node, color>
        q.push( make_pair( k, 1 ) );

        while( !q.empty() )
        {
            pair<int, int>node = q.front(); q.pop();
            // finding
            int u = node.first;
            for( int i = 0; i < gp[u].size(); i++ )
            {
                int a = 0, b = 0, c = 0, d = 0;
                int v = gp[u][i];
                if( color[v - 1] != -1 )
                    continue;
                for( int j = 0; j < gp[v].size(); j++ )
                {
                    int w = gp[v][j];
                    if( color[w - 1] != -1 )
                    {
                        if( color[w - 1] == 1 )
                            a++;
                        else if( color[w - 1] == 2 )
                            b++;
                        else if( color[w - 1] == 3 )
                            c++;
                        else
                            d++;
                    }
                }
                if( a == 0 )
                    color[v - 1] = 1;
                else if( b == 0 )
                    color[v - 1] = 2;
                else if( c == 0 )
                    color[v - 1] = 3;
                else
                    color[v - 1] = 4;
                q.push( make_pair( v, color[v - 1] ) );

            }
        }
    }
    return color;
}
/*
int main()
{
    int N = 4;
    vector<vector<int> >paths = { {1,2} };
    //vector<vector<int> >paths = { {1,2},{3,4} };
    vector<int>ans = gardenNoAdj( N, paths );
    for( auto x : ans )
        cout << x << " ";
} 
*/