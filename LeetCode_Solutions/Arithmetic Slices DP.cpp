#include<bits/stdc++.h>
using namespace std;
//  0 1 2 3 4 5
// [1,2,3,4,5,6]
int numberOfArithmeticSlices( vector<int>& A )
{
	int n = A.size();
	if( n < 3 )
		return 0;
	int i, j, k,cnt=0;
	for( i = 0; i < A.size()-2; i++ )
	{
		int dif = A[i + 1] - A[i];
		for(  j = i+2; j < A.size(); j++ )
		{
			for(  k = i + 1; k <= j; k++ )
			{
				if( A[k] - A[k - 1] != dif )
					break;
			}
			if( k > j )
				cnt++;
		}
	}
	return cnt;
}

/*
int main()
{
	vector<int>A = { 1,2,3,4,5,6 };
	cout << numberOfArithmeticSlices( A );
}
*/