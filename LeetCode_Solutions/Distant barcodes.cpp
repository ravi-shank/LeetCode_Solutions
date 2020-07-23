#include<bits/stdc++.h>
using namespace std;


vector<int> solve( vector<int>& barcodes )
{
    map<int, int>mp;
    vector<int>ans;

    priority_queue< pair<int,int> >max_pq;   // cnt ,  num
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >min_pq;
    int total = barcodes.size();

    for( int i = 0; i < barcodes.size(); i++ )
    {
        mp[barcodes[i]]++;
    }
    vector<pair<int, int> >freq;
    for( auto it = mp.begin(); it != mp.end(); it++ )
    {
        freq.push_back( make_pair( it->second, it->first ) );
    }
    sort( freq.begin(), freq.end(), greater<pair<int, int>>() );
    int sum = 0;
    int ptr = 0;
    while(sum<total/2 and ptr<freq.size())
    {
        sum += freq[ptr].first;
        max_pq.push( make_pair( freq[ptr].first, freq[ptr].second ) );
        ptr++;
    }
    
    while( ptr<freq.size())
    {
        min_pq.push( make_pair( freq[ptr].first, freq[ptr].second ) );
        ptr++;
    }

    while( max_pq.size() and min_pq.size() )
    {
        pair<int, int>a = max_pq.top(); max_pq.pop();
        pair<int, int>b = min_pq.top(); min_pq.pop();
        ans.push_back( a.second );
        ans.push_back( b.second );
        if(a.first-1>=1)
            max_pq.push( make_pair( a.first-1, a.second ) );
        if( b.first - 1 >= 1 )
            min_pq.push( make_pair( b.first-1, b.second ) );
    }
    
    while( max_pq.size() )
    {
        pair<int, int>a = max_pq.top(); max_pq.pop();
        ans.push_back( a.second );
        if(a.first-1>=1)
            max_pq.push( make_pair( a.first-1, a.second ) );
    }

    while(  min_pq.size() )
    {
        pair<int, int>b = min_pq.top(); min_pq.pop();
        ans.push_back( b.second );
        if( b.first - 1 >= 1 )
            min_pq.push( make_pair( b.first-1, b.second ) );
    }

    return ans;
    
}
/*
int main()
{
    vector<int>v = {1,2,1,2,1 };
    vector<int>ans = solve( v );
    for( auto x : ans )
        cout << x << " ";

}
*/