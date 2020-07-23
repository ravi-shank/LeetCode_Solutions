#include<bits/stdc++.h>
using namespace  std;

int nthSuperUglyNumber( int n, vector<int>& primes )
{

    priority_queue< long long, vector<long long>, greater<long long> >pq;
    map<long long, int>numInserted;

    for( int i = 0; i < primes.size(); i++ )
    {
        pq.push( primes[i] );
    }

    if( n == 1 )
        return 1;

    for( int i = 2; i < n; i++ )
    {
        long long num = pq.top(); pq.pop();
        for( int j = 0; j < primes.size(); j++ )
        {
            if( !numInserted[num * primes[j]] )
            {
                numInserted[num * primes[j]]++;
                pq.push( num * primes[j] );
            }
        }
    }
    return pq.top();
}

/*
int main()
{
    while( 1 )
    {
        vector<int > primes = { 2,7,13,19 };
        int n;

        cin >> n;
        cout << nthSuperUglyNumber( n, primes ) << endl;
    }
}
*/