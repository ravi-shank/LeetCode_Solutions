#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode( int x )
	{
		val = x;
		left = NULL;
		right = NULL;
	}
};

string Serialize( TreeNode* root )
{
	string data;
	if( NULL == root )
		return data;

	queue<TreeNode*>q;
	q.push( root );
	int numNodesToTrav = 0;
	int curLevNodesCnt = 1;
	while( !q.empty() )
	{
		numNodesToTrav = curLevNodesCnt;
		curLevNodesCnt = 0;
		for( int i = 1; i <= numNodesToTrav; i++ )
		{
			TreeNode* node = q.front(); q.pop();
			if( node )
			{
				data += to_string( node->val );
				data += ',';
			}
			else
			{
				data += "null";
				data += ',';
				continue;
			}
			
			if( node->left )
			{
				q.push( node->left );
				curLevNodesCnt++;
			}
			else
			{
				q.push( NULL );
				curLevNodesCnt++;
			}
			if( node->right )
			{
				q.push( node->right );
				curLevNodesCnt++;
			}
			else
			{
				q.push( NULL );
				curLevNodesCnt++;
			}
		}
	}
	return data;
}

string getNextNodeVal( string& data, int& dataPos )
{
	string nodeStr;
	while( dataPos < data.length() )
	{
		if( data[dataPos] != ',' )
			nodeStr += data[dataPos++];
		else
		{				
			break;
		}
	}
	dataPos++;
	return nodeStr;
}
TreeNode* DeSerialize( string data )
{
	
	struct TreeNode* root = NULL;
	if( data.length() <= 0 )
		return root;

	int prevNodeCnt = 0;
	int curNodeCnt = 1;
	queue<TreeNode*>q;
	int dataPos = 0;
	string rootNodeStrVal = getNextNodeVal( data, dataPos );
	if(rootNodeStrVal != "null")
		root = new TreeNode( stoi(rootNodeStrVal) );
	q.push( root );
	/* 
	i= 1,2
	prevNodeCnt = 4
	curNodeCnt = 0
	q=  null, null
	1,2,3,-1,-1,4,5,-1,-1,-1,-1,
	        1
		  /  \
		 2    3
		     / \
			4   5
	*/
	while( !q.empty() )
	{
		prevNodeCnt = curNodeCnt;
		curNodeCnt = 0;
		for( int i = 1; i <= prevNodeCnt; i++ )
		{
			TreeNode* node = q.front(); q.pop();			    // 3
			if( !node )
				continue;
			string leftNodeStrVal = getNextNodeVal( data, dataPos );	// 4
			string rightNodeStrVal = getNextNodeVal( data, dataPos );	// 5
			if( leftNodeStrVal == "null" )
			{
				node->left = NULL;
				curNodeCnt++;
				q.push( NULL );
			}
			else
			{
				node->left = new TreeNode( stoi(leftNodeStrVal) );
				curNodeCnt++;
				q.push( node->left );
			}

			if( rightNodeStrVal == "null" )
			{
				node->right = NULL;
				curNodeCnt++;
				q.push( NULL );
			}
			else
			{
				node->right = new TreeNode( stoi(rightNodeStrVal) );
				curNodeCnt++;
				q.push( node->right );
			}
		}
	}
	
	return root;
}
void pntInorder( TreeNode* root )
{
	if( root == NULL )
		return;
	pntInorder( root->left );
	cout << root->val<<" ";
	pntInorder( root->right );
}

/*
		1
	   / \
	  -1   2
	 /	 
	-2 
*/
/*
int main()
{
	TreeNode* root = new TreeNode( 1 );
	root->left = new TreeNode( -1 );
	root->right = new TreeNode( 2 );
	root->left->left = new TreeNode( -2 );
	//root->left->right = new TreeNode( 5 );
	//root->right->left = new TreeNode( 6 );
    //root->right->right = new TreeNode( 7 );
	//TreeNode*root = DeSerialize( Serialize( root ) );
	string data = Serialize( root );
	cout << data << endl;
	TreeNode* head = DeSerialize( data );
	pntInorder( head );



}
*/