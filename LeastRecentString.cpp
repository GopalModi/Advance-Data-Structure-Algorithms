#include<bits/stdc++.h>
using namespace std;
void add(list<string> &l,string str)
{
	list<string>::iterator it;
	for(it=l.begin();it!=l.end();it++)
	{
		if((*it).compare(str)==0)
		{
			l.erase(it);
			break;
		}
	}
	l.push_back(str);
}
int main()
{
    list<string> l;
    int i;
	add(l,"m1");
	add(l,"m2");
	add(l,"m3");
	add(l,"m4");
	add(l,"m2");
	add(l,"m3");
	add(l,"m1");
	add(l,"m5");	
	cout<<endl;
    list<string>::iterator it;
	for(it=l.begin();it!=l.end();it++)
	{
		 cout<<*it<<" ";
    }
    cout<<l.front();
    l.pop_front();
    cout<<l.front();
    
}
