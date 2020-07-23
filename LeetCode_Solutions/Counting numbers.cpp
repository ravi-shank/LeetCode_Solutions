#include<bits/stdc++.h>
using namespace std;

int countElements( vector<int>& arr )
{
	map<int, int>freq;
	for( int nums : arr )
		freq[nums]++;

	sort( arr.begin(), arr.end() );
	int ans = 0;
	for( int i = 0; i < arr.size(); i++ )
	{
		if( freq.find( arr[i] + 1 ) != freq.end() )
			ans++;
	}

	return ans;
}

/*
int main()
{
	vector<int>v = { 1,1,2 };
	int ans = countElements( v );
	cout << ans << endl;
}
*/