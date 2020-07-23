#include<bits/stdc++.h>
using namespace std;
bool PartitionAndCheck( int start, vector<int>& nums, int k, vector<bool>& vis, int curBucketSum, int targetSum )
{
	if( k == 1 )
		return true;
	if( curBucketSum == targetSum )
	{
		return PartitionAndCheck( 0, nums, k - 1, vis, 0, targetSum );
	}
	if( curBucketSum > targetSum )
		return false;
	for( int i = start; i < nums.size(); i++ )
	{
		cout << "k= " << k << " start = " << i << endl;
		if( !vis[i] )
		{
			vis[i] = true;
			if( PartitionAndCheck( start + 1, nums, k, vis, curBucketSum + nums[i], targetSum ) )
			{
				return true;
			}
			vis[i] = false;
		}
	}
	return false;
}	

bool canPartitionKSubsets( vector<int>& nums, int k )
{
	int totalSum = 0;
	for( int num : nums )
		totalSum += num;
	if( k <=0 || totalSum%k != 0)
		return false;
	int numSize = nums.size();
	vector<bool>vis( numSize, false );
	return PartitionAndCheck( 0, nums, k, vis, 0, totalSum/k );
}

/*
int main()
{
	vector<int>nums = { 129,17,74,57,1421,99,92,285,1276,218,1588,215,369,117,153,22 };
	int k = 3;
	cout << canPartitionKSubsets( nums, k );
}
*/