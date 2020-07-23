#include<bits/stdc++.h>

using namespace std;

bool canVisitAllRooms( vector<vector<int>>& rooms )
{
    int N = rooms.size();
    queue<int>q;
    vector<bool> visited( N, false );
    q.push( 0 );
    while( !q.empty() )
    {
        int curRoom = q.front(); q.pop();
        visited[curRoom] = true;
        for( int i = 0; i < rooms[curRoom].size(); i++ )
        {
            if(!visited[rooms[curRoom][i]])
                q.push( rooms[curRoom][i] );
        }
    }
   
    for( int i = 0; i < N; i++ )
        if( !visited[i] )
            return false;
    return true;

}
/*
int main()
{
    vector<vector<int> > rooms = { {1,3},{3,0,1},{2},{0} };
    bool ans = canVisitAllRooms( rooms );
    cout << ans;
}
*/