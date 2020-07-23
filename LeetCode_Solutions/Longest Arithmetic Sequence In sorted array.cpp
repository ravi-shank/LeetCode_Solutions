#include<bits/stdc++.h>
using namespace std;

/*
* Note the array is sorted
*/
int longestArithSeqLength( vector<int>& A )
{
	if( A.size() <= 2 )
		return A.size();

	int n = A.size();
	int max_len = 2;
	// LIS[i][j] denote the max length of Arithmetic seq that can be made with A[i] as starting 
	// and A[j] as the end term of AP.					
	vector<vector<int> >LIS( n + 1, vector<int>( n + 1, 0 ) );
	
	// LIS[i][n-1] will be 2 as the minimum Ap length that can be made is 2 (A[i] as first and A[n-1]th element as last term of AP)
	for( int i = 0; i < n; i++ )
	{
		LIS[i][n - 1] = 2;
	}

	// Let i, j, k be hte 3 term of AP.
	for( int j = n-2; j >=1 ; j-- )
	{
		int i = j - 1, k = j+1;
		while( i >= 0 and k < n )
		{
			if( A[i] + A[k] == 2 * A[j] )
			{
				LIS[i][j] = LIS[j][k] + 1;
				max_len = max( max_len, LIS[i][j] );
				i--;  k++;
			}
			else if( A[i] + A[k] > 2 * A[j] )
			{
				LIS[i][j] = 2;
				i--;
			}
			else
				k++;
		}

		// when k >n  then LIS[i][j] = 2;
		while( i >= 0 )
		{
			LIS[i][j] = 2;
			i--;
		}
	}

	return max_len;
}

/*
int main()
{
	vector<int>nums = { 1,4,6,2,4,5,2,3,5,4,3,6,7,8,1,2,3,2,4,3,5 };
	cout << longestArithSeqLength( nums ) << endl;
}
*/