#include<bits/stdc++.h>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int maxLevelSum( TreeNode* root )
{


    long long max_sum = INT_MIN;
    int min_level = 0;
    int totalNodesAtIthLevel = 0, totalNodesPushedIntoQ = 1;
    int cur_level = 1;
    queue<TreeNode*>q;
    q.push( root );   // src node

    while( !q.empty() )
    {
        totalNodesAtIthLevel = totalNodesPushedIntoQ;
        totalNodesPushedIntoQ = 0;
        long long sumAtIthLevel = 0;
        for( int iCnt = 1; iCnt <= totalNodesAtIthLevel; iCnt++ )
        {
            TreeNode* node = q.front(); q.pop();
            sumAtIthLevel += node->val;
            if( node->left )
            {
                q.push( node->left );
                totalNodesPushedIntoQ++;
            }

            if( node->right )
            {
                q.push( node->right );
                totalNodesPushedIntoQ++;
            }
        }

        if( sumAtIthLevel > max_sum )
        {
            max_sum = sumAtIthLevel;
            min_level = cur_level;
        }

        cur_level++;
    }

    return min_level;

}