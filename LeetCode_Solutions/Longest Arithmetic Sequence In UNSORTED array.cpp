#include<bits/stdc++.h>
using namespace std;

/*
* Note the array is NOT sorted
* j,i,k
* i-j = k-i
  k = 2i - j
*/


int longestArithSeqLength2( vector<int>& A )
{
	int n = A.size();
	if( n <= 2 )
		return n;
	vector<vector<int> >LIS( n + 1, vector<int>( n + 1, 0 ) );
	map<int, int>pos;
	int max_len = 2;
	for( int i = 0; i < n; i++ )
	{
		for( int j = i + 1; j < n; j++ )
		{
			LIS[i][j] = 2;
			int dif = A[j] - A[i];
			int req = 2 * A[i] - A[j];
			if( pos.count(req) ==0)
				continue;
			LIS[i][j] = max( LIS[i][j], LIS[pos[req]][i] + 1 );
			max_len = max( max_len, LIS[i][j] );
		}
		pos[A[i]] = i;
	}
	return max_len;
}

/*
int main()
{
	vector<int>nums = { 3,6,9,12 };
	cout << longestArithSeqLength2( nums ) << endl;
}
*/
