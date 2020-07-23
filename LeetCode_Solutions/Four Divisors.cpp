#include<bits/stdc++.h>
using namespace std;
int IsFourDivisors( int n )
{
	int sumOfDivisors = 0;
	int totalDivisors = 0;
	for( int i = 1; i * i <= n; i++ )
	{
		if( n % i == 0 )
		{
			if( n / i == i )
			{
				totalDivisors++;
				sumOfDivisors += i;
			}
			else
			{
				totalDivisors += 2;
				sumOfDivisors += i;
				sumOfDivisors += ( n / i );
			}
		}

		if( totalDivisors > 4 )
			return -1;
	}

	return (totalDivisors==4 ? sumOfDivisors:-1 );
}
int sumFourDivisors( vector<int>& nums )
{
	int totalSum = 0;
	for( int i = 0; i < nums.size(); i++ )
	{
		int res = IsFourDivisors( nums[i] );
		if( res != -1 )
			totalSum += res;
	}

	return totalSum;
}
/*
int main()
{
	vector<int>nums = { 21,4,7 };
	int ans = sumFourDivisors( nums );
	cout << ans << endl;
}
*/