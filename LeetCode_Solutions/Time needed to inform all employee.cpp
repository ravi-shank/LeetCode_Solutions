#include<bits/stdc++.h>
using namespace std;

int numOfMinutes( int n, int headID, vector<int>& manager, vector<int>& informTime )
{

    vector<vector<int> > gp( n  );
    vector<int>InformTime( n , INT_MAX );
    vector<bool>vis( n , false );

    for( int i = 0; i < n; i++ )
    {
        int id = manager[i];
        if( id == -1 )
            continue;
        gp[id].push_back( i );
    }

    queue<pair<int, int> >q;
    InformTime[headID] = 0;
    q.push( make_pair( headID, 0 ) );

    while( !q.empty() )
    {
        //cout << "hi" << endl;
        pair<int, int>p = q.front(); q.pop();
        int u = p.first;
        int cost = p.second;
        for( int i = 0; i < gp[u].size(); i++ )
        {
            int v = gp[u][i];
            InformTime[v] = min( cost + informTime[u], InformTime[v] );
            q.push( make_pair( v, min( cost + informTime[u], InformTime[v] ) ) );
        }
    }

    int max_ans = 0;
    for( int i = 0; i < n; i++ )
    {
       // cout << InformTime[i] << " ";
        max_ans = max( max_ans, InformTime[i] );
    }

    return max_ans;//== INT_MAX ? 0 : max_ans;
}
/*
int main()
{
    int n = 1;
    int headID = 0;
    vector<int>manager = { -1};
    vector<int>informTime = { 0};
    int ans = numOfMinutes( n, headID, manager, informTime );
    cout << ans << endl;
}
*/