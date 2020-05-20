#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,s,k,l;
		cin>>n>>s>>k;
		set<int> s1;
		for(int j=0;j<k;j++)
		{
			cin>>l;
			s1.insert(l);
		}
		int val=INT_MAX,val1=INT_MAX;
		for(int k=s;k<=n;k++)
		{
			if(s1.find(k)==s1.end())
			{
				val=k-s;
				break;
			}
		}
		for(int k=s-1;k>=1;k--)
		{
			if(s1.find(k)==s1.end())
			{
				val1=s-k;
				break;
			}
		}
		cout<<min(val,val1)<<endl;
	}
}
