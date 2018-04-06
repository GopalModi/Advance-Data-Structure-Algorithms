#include<iostream>
using namespace std;
int min(int a,int b)
{
	if (a>b)
	    return b;
	return a;
}
int buildTree(int *a, int start,int end, int *tree,int index)
{
	if(start==end)
	{
		tree[index]=a[start];
		return a[start]; 
	}
	int mid=(start+end)/2;
	tree[index]=min(buildTree(a,start,mid,tree,2*index+1),buildTree(a,mid+1,end,tree,2*index+2));
	return tree[index];
}
int search_min(int *tree,int root,int s,int end)
{
	if(root>s && root < end)
	     return tree[root];
	else if((root<s&&root<end)||(root>s&&root>end))
	      return 99999;
	else
	{
		int mid=(s+end)/2;
       return min(search_min(tree,root*2+1,s,mid),search_min(tree,root*2+2,mid+1,end));
    }
}
int main()
{
	int A[6]={-2,4,2,-1,7,5};
	int n=6;
	int tree[20];
	int root=buildTree(A,0,5,tree,0);
	cout<<root<<endl;
	int i=0;
	for(i=0;i<6;i++)
	    cout<<tree[i]<<" ";
	cin>>i;
	int a,b;
	while(i--)
	{
		cin>>a>>b;
		cout<<search_min(tree,0,a,b);
	}
}
