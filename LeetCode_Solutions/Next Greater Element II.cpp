#include<bits/stdc++.h>
using namespace std;
//			                             i
//                                   j
//           k                                 
//			[1,9,6,6,2,1,5,4,2,3,3,1,4][3,9,6,6,2,1,5,4,2,3,3,1,2]
// [9,]
// ans=     [9,-1,9,9,5,5,9,9,3,4,4,4,9]
// [L2R] =                             [  ]
// [R2L]=	[   9                 ]
vector<int> Next_Greater_Element( vector<int>& nums )
{
	vector<int>ans(nums.size());
	stack<int> rightToLeft;
	stack<int> leftToRight;
	for( int i = nums.size() - 1; i >= 0; i-- )
		leftToRight.push( nums[i] );

	for( int i = nums.size() - 1; i >= 0; i-- )
	{
		if( !rightToLeft.empty() )
		{
			while( !rightToLeft.empty() and rightToLeft.top() <= nums[i] )
			{
				rightToLeft.pop();
			}
			if( !rightToLeft.empty() )
			{
				ans[i] = rightToLeft.top();
			}

		}
		if(rightToLeft.empty())
		{
			while( !leftToRight.empty() and leftToRight.top() <= nums[i] )
			{
				leftToRight.pop();
			}
			if( leftToRight.empty() )
				ans[i] = -1;
			else
				ans[i] = leftToRight.top();
		}
		rightToLeft.push( nums[i] );
	}
	return ans;
}
