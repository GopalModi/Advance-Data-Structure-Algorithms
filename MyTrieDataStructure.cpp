#include<bits/stdc++.h>
#include<malloc.h>
#define ALPHBET 256
using namespace std;
struct trie
{
	trie *data[ALPHBET];
	int isleaf;
};
struct trie * getnewnode()
{
    struct trie *newnode =  new trie;
	newnode->isleaf=0;
	for(int i=0;i<ALPHBET;i++)
	     newnode->data[i]=NULL;
	return newnode;
}
void insert(struct trie **root,string str)
{
	  struct trie *local_root=*root;
	  int i=0;
	  while(str[i])
	  {
	  	   if(local_root->data[str[i]]==NULL)
	  	   {
	  	      local_root->data[str[i]]=getnewnode();    	
		   }
		   	local_root=local_root->data[str[i]];
		   	i++;
	  }
	  local_root->isleaf=1;
}
string search(struct trie **root,string str)
{
	struct trie *local_root=*root;
	int i=0;
	while(str[i])
	{
		if(local_root->data[str[i]]==NULL)
		       return "NO";
		local_root=local_root->data[str[i]];
		i++;
	}
	if(local_root->isleaf==1)
	    return "YES";
	return "NO";
}
void display(struct trie *root,char *str,int level)
{
	int i;
	if(root->isleaf==1)
	{
		str[level]='\0';
		cout<<str<<endl;
	    //str="";
     }
	for(i=0;i<256;i++)
	{
		if(root->data[i]!=NULL)
		{
	       str[level]=char(i);
	       display(root->data[i],str,level+1);
	    }
	}
}
int main()
{
     struct trie *t=getnewnode();
	 insert(&t,"gopal");
	 insert(&t,"modi");
	 insert(&t,"parag");
	 insert(&t,"avanish");
	 insert(&t,"arihant");
	 cout<<search(&t,"gopal");
	 cout<<search(&t,"modi");
	 cout<<search(&t,"parag");
	 cout<<search(&t,"avanish");
	 cout<<search(&t,"arihant"); 
	 char str[30];
	 display(t,str,0);	
}
