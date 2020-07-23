#include<bits/stdc++.h>
using namespace  std;

struct cmp
{
	bool operator()( pair< pair<int,int>, pair<int, int>>& a, pair< pair<int,int>, pair<int, int>>& b )
	{
		int x = a.first.first;
		int y = a.first.second;

		int u = b.first.first;
		int v = b.first.second;
		return ( x + y ) > ( u + v );
	}
};
vector<vector<int>> kSmallestPairs( vector<int>& nums1, vector<int>& nums2, int k )
{
	vector<vector<int>>ans;

	if( nums1.size() <= 0 or nums2.size() <= 0 )
		return ans;

	//  < pair<num1,num2> , pair<indexOfNums1,indexOfNums1> >
	priority_queue<  pair< pair<int,int>, pair<int, int> >, vector< pair< pair <int,int>, pair<int, int>> >, cmp >pq;
	map< pair<int, int>, int >mp_pair;
	pq.push( make_pair( make_pair(nums1[0] , nums2[0]), make_pair( 0, 0 ) ) );
	mp_pair[make_pair( 0, 0 )]++;

	for(int i=0; i<k; i++)
	{
		if( pq.size() <= 0 )
			break;
		const pair< pair<int,int>, pair<int, int> >p = pq.top(); pq.pop();
		int a, b, c, d;
		
		vector<int>vPair ;
		
		vPair.push_back( p.first.first );
		vPair.push_back( p.first.second );
		ans.push_back( vPair );

		a = p.second.first;
		b = p.second.second + 1;

		c = p.second.first+1;
		d = p.second.second;

		if( a < nums1.size() and b<nums2.size() and (mp_pair.find( make_pair( a, b ) )  == mp_pair.end())  )
		{
			mp_pair[make_pair( a, b )]++;
			pq.push( make_pair( make_pair( nums1[a], nums2[b] ), make_pair( a, b ) ) );
		}

		if( c < nums1.size() and d < nums2.size() and ( mp_pair.find( make_pair( c, d ) ) == mp_pair.end()) )
		{
			mp_pair[make_pair( c, d )]++;
			pq.push( make_pair( make_pair(nums1[c] , nums2[d]), make_pair( c, d ) ) );
		}
	}
	return ans;
}
/*
int main()
{
	vector<int>u = { 1,2 };
	vector<int>v = { 3};
	int k = 3;
	vector<vector<int>>ans = kSmallestPairs( u, v, k );
	for( int i = 0; i < ans.size(); i++ )
	{
		for( int j = 0; j < ans[i].size(); j++ )
			cout << ans[i][j] << " ";
		cout << endl;
	}
}
*/
/*
[1,1,2]
[1,2,3]

1,1
1,2
*/