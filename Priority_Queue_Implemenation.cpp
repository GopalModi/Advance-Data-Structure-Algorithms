#include<iostream>
#include<bits\stdc++.h>
using namespace std;
int main()
{
	 string str = "aaab";   // Input 1
    int k = 2,i=0,count[26]={0};
	while(str[i])
	{
		count[str[i]-'a']++;
		i++;
	}
	priority_queue<int> pq;
	for(i=0;i<26;i++)
	    if(count[i])
	    pq.push(count[i]);
	while(k--)
	{
		int q=pq.top();
		pq.pop();
		q--;
		pq.push(q);
	}
	int sum=0;
	while(!pq.empty())
	{
		int l=pq.top();
		sum+=l*l;
		pq.pop();
	}
	cout<<sum;
}
