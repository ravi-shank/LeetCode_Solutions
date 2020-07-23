#include<bits/stdc++.h>
using namespace std;
bool isPossibleDivide( vector<int>& nums, int k)
{
	if( nums.size() <= 0 or nums.size() % k != 0 )
		return false;
	map<int, int>freqOfNums;
	for( int i = 0; i < nums.size(); i++ )
		freqOfNums[nums[i]]++;

	int N = nums.size();
	for( int i = 1; i <= N/k; i++ )
	{
		map<int, int>::iterator mit;
		mit = freqOfNums.begin();
		int cnt = 0;
		int lastNum = -1;
		while( cnt < k and mit != freqOfNums.end() )
		{
			if( mit->second > 0 )
			{
				if( lastNum == -1 )
				{
					cnt++;
					lastNum = mit->first;
					mit->second--;
				}
				else
				{
					if( mit->first - lastNum != 1 )
						return false;
					else
					{
						lastNum = mit->first;
						mit->second--;
						cnt++;
					}
				}
			}
			mit++;
		}
		if( cnt != k )
			return false;

	}

	return true;
}
/*
int main()
{
	vector<int>nums = { 1,1,1 };
	int k = 3;
	cout << isPossibleDivide( nums, k ) << endl;;
}
*/