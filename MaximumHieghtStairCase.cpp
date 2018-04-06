#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=1,c=17,prev=0;
	while(1)
	{
		int sum=n*(n+1)/2;
		if(sum>c)
	    {
	    	break;
		}
		prev=n;
		n++;
	}
	cout<<prev<<endl;
	
	int out;
	out=(-1)+sqrt(1+8*c);
	cout<<out/2;
}
