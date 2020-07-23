#include<bits/stdc++.h>
using namespace std;


int nthUglyNumber( int k )
{

    priority_queue< long long, vector<long long>, greater<long long> >pq;
    map<long long, int>numInserted;
    long long a = 2, b = 3, c = 5;
    pq.push( 2);
    pq.push( 3);
    pq.push( 5);
    numInserted[2]++;
    numInserted[3]++;
    numInserted[5]++;

    if( k == 1 )
        return 1;

    for( int i = 2; i < k; i++ )
    {
        long long num = pq.top(); pq.pop();
        if( !numInserted[num * 2] )
        {
            pq.push( num * 2 );
            numInserted[num * 2]++;
        }
        if( !numInserted[num * 3] )
        {         
            pq.push( num * 3 );
            numInserted[num * 3]++;
        }
        if( !numInserted[num * 5] )
        {
            pq.push( num * 5 );
            numInserted[num * 5]++;
        }
    }
    return pq.top();
}
/*
int main()
{
    while( 1 )
    {
        int n;
        cin >> n;
        cout << nthUglyNumber( n ) << endl;
    }
}

*/