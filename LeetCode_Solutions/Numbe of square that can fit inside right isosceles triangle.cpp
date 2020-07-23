#include<bits/stdc++.h>
using namespace std;
long long solve( int n )
{
	if( n <= 2 )
		return 0;
	int sq = n / 2;
	sq--;
	return ( sq * ( sq + 1 ) ) / 2;
	
}
/*
int main()
{
	int t;
	cin >> t;
	while( t-- )
	{
		int n;
		cin >> n;
		cout << solve( n ) << endl;
	}

}
*/