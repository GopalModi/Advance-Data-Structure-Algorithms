#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
struct Interval
{
    int buy;
    int sell;
};
void stockBuySell(int price[], int n)
{
     int count=0;
	 Interval order[10];
	 int i,j;
	 int sum=0;
	 for(i=0;i<n-1;i++)
	 {
	 	while(i<n-1&&price[i]>price[i+1])
	 	      i++;
	 	order[count].buy=i++;
	 	while(i<n-1&&price[i]<price[i+1])
	 	     i++;
	    order[count].sell=i;
	    
	    sum+=price[order[count].sell]-price[order[count].buy];
	    count++;
	 }	
	 cout<<sum;
}
int main()
{
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price)/sizeof(price[0]);
    stockBuySell(price, n);
    return 0;
}
