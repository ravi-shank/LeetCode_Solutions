#include<bits/stdc++.h>
using namespace std;

int numOfDigits( long long n )
{
	int cntDigits = 0;
	while( n > 0 )
	{
		cntDigits++;
		n = n / 10;
	}

	return cntDigits;
}
bool IsNumbOfDigitsSame( long long a, long long b )
{
	int digitsInA = numOfDigits( a );
	int digitsInB = numOfDigits( b );
	return digitsInA == digitsInB; 
}
/*
int main()
{
	int t;
	cin >> t;
	while( t-- )
	{
		long long m, n, ans = 0;
		cin >> m >> n;
		if( IsNumbOfDigitsSame( m + n, n ) )
			ans = n;
		else
			ans = m + n;
		cout << ans << endl;
	}
}
*/