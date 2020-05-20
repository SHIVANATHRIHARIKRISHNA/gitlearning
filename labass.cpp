#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >g1,g2;
vector<bool>vis;
vector<set<int> >first,last; 

int fnd(vector<char>&arr,char ch)
{
for(int i=0;i<arr.size();i++)
{
 if(arr[i]==ch)
{
 return i;
}
}
cout<<"hi"<<endl;
}


int func1(char ch) 
{ 
if((ch>='A') && (ch<='Z'))
{
 return 1; 
}
else 
{
return 0;
}
}


void func2(int root,int operators)
{
    vis[root]=true;
int n=g1[root].size();
for(int i=0;i<n;i++)
    {
        int v=g1[root][i];
        if(vis[v]==false)
        {
            first[v].insert(operators);
            func2(v,operators);
        }
    }
}
void func3(int root,int operators)
{
    vis[root]=true;
int n=g2[root].size();
for(int i=0;i<n;i++)
    {
        int v=g2[root][i];
        if(vis[v]==false)
        {
            last[v].insert(operators);
            func3(v,operators);
        }
    }
}

int main()
{
  int c1,c2,i,j,k,lx;
  char ch;
   cout<<"Enter non terminals:"<<endl;
cin>>c1;
cout<<"Enter terminals:"<<endl;
cin>>c2;
  g1.resize(c1+c2);
  g2.resize(c1+c2);
  vector<char>op(c1+c2);
  for(i=0;i<c1+c2;i++)  
  {
    cin>>op[i];
  }
   first.resize(c1);
   last.resize(c1);
  int n;
cout<<"Enter no of rules:"<<endl;
cin>>n;
  vector<pair<char,string> >values(n);
  string s1;
cout<<"Enter rules:"<<endl;
for(int a=0;a<n;a++)
  {
cin>>values[a].first>>values[a].second;
    char ch=values[a].first;
    string s1=values[a].second;
    int lx=a;
    bool st=true;
    for(i=0;i<s1.length();i++)
    {
      lx=fnd(op,s1[i]);
       if(st)
       {
          if(func1(s1[i])==0)
          {
              g1[lx].push_back(a);
          }
          else
          {
            g1[lx].push_back(a);
              if(i+1<s1.length() &&s1[i+1]!='|')
            {
                 lx=fnd(op,s1[i+1]);
                g1[lx].push_back(a);
            }
          }
       st=false;
       }
       else if(s1[i]=='|') st=true;
     }
     reverse(s1.begin(),s1.end());
         st=true;
    for(i=0;i<s1.length();i++)
    {
      lx=fnd(op,s1[i]);
       if(st)
       {
          if(!func1(s1[i]))
            g2[lx].push_back(a);
          else
          {
            g2[lx].push_back(a);
     if(i+1<s1.length() &&s1[i+1]!='|')
            {
     lx=fnd(op,s1[i+1]);
                g2[lx].push_back(a);
            }
          }
st=false;
       }
       else if(s1 [i]=='|') st=true;
     }
  }
	  for(i=c1;i<c1+c2;i++)
	  {
	vis.resize(c1+c2);
	      func2(i,i);
	vis.clear();
	vis.resize(c1+c2);
	      func3(i,i);
	vis.clear();
	  }
  vector<vector<char> >tab(c2,vector<char>(c2,'.'));
  for(i=0;i<n;i++)
  {
      string rhs=values[i].second;
      char ch=values [i].first;
      reverse(rhs.begin(),rhs.end());
      int len=rhs.length();
      for(j=0;j<len;j++)
      {
     if(j+1<len && !func1(rhs[j]) && func1(rhs[j+1]) &&rhs[j]!='|' &&rhs[j+1]!='|')
          {
             set<int>&s=first[fnd(op,rhs[j+1])];
             set<int>::iterator it=s.begin();
             int idx=fnd(op,rhs[j]);
             for(;it!=s.end();it++)
             {
                 k=*it;
                 tab[idx-c1][k-c1]='<';
             }
          }
   if(j+1<len && func1(rhs[j]) && !func1(rhs[j+1]) &&rhs[j]!='|' &&rhs[j+1]!='|')
          {
              set<int>&s=last[fnd(op,rhs[j])];
             set<int>::iterator it=s.begin();
             int idx=fnd(op,rhs[j+1]);
             for(;it!=s.end();it++)
             {
                 k=*it;
                 tab[k-c1][idx-c1]='>';
             }
          }
          if(j+2<len && !func1(rhs[j]) && func1(rhs[j+1]) && !func1(rhs[j+2]) &&rhs[j]!='|' &&rhs[j+1]!='|' &&rhs[j+2]!='|')
          {
              int idx1=fnd(op,rhs[j]);
              int idx2=fnd(op,rhs[j+2]);
              tab[idx1-c1][idx2-c1]='=';
          }
      }
  }
cout<<"  ";
  for(j=0;j<c2;j++)
  {
      tab[0][j]='<',tab[j][0]='>';
      if(op[c1+j]==')' || op[c1+j]=='$') tab[0][j]='.';
      if(op[c1+j]=='(') tab[j][0]='.';
  }
  for(i=c1;i<c1+c2;i++) cout<<op[i]<<" ";
cout<<endl;
  for(i=0;i<tab.size();i++)
  {
cout<<op[c1+i]<<" ";
      for(j=0;j<tab[i].size();j++) cout<<tab[i][j]<<" ";
cout<<endl;
  }
}

