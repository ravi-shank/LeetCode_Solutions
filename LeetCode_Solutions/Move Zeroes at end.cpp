#include<bits/stdc++.h>
using namespace std;
void MoveZeroes( vector<int>& nums )
{
    int NextZeroPos = 0;
    int NextNonZeroPos = 0;
    while( NextZeroPos < nums.size() and NextNonZeroPos < nums.size() )
    {
        while( NextZeroPos < nums.size() and nums[NextZeroPos] != 0 )
        {
            NextZeroPos++;
        }
        NextNonZeroPos = NextZeroPos;
        while( NextNonZeroPos < nums.size() and nums[NextNonZeroPos] == 0 )
        {
            NextNonZeroPos++;
        }
        if( NextZeroPos < nums.size() and NextNonZeroPos < nums.size() )
            swap( nums[NextNonZeroPos], nums[NextZeroPos] );
    }
}
/*
int main()
{ 
	vector<int>nums = { 1,1,1,0,0,0,1,0,10,10,1 };
	MoveZeroes( nums );
	for( int num : nums )
		cout << num << " ";
}
*/