#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'


using namespace std;

vector<int> ar[101];
const int maxN = 100;
int level[101] , LCA[101][maxN+1];


void dfs(int node , int lvl , int par)
{
 level[node] = lvl;
 LCA[node][0] = par;

 for(int child : ar[node])
 if(child != par)
  dfs(child , lvl+1 , node);

}


void init(int n)
{
 dfs(1 , 0 , -1);

 for(int i=1;i<=maxN;i++)
 {
  for(int j=1;j<=n;j++)
  if(LCA[j][i-1] != -1)
  {
   int par = LCA[j][i-1];
   LCA[j][i] = LCA[par][i-1];
  }
 }
}

int getLCA(int a , int b)
{
 if(level[b] < level[a]) swap(a , b);

 int d = level[b] - level[a];

 while(d > 0)
 {
  int i = log2(d);
  b = LCA[b][i];
  d -= 1 << i;
 }

 if(a == b) return a;

 for(int i=maxN;i>=0;i--)
 if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
  a = LCA[a][i] , b = LCA[b][i];

 return LCA[a][0];
}


int getDist(int a , int b)
{
 int lca = getLCA(a , b);
 return level[a] + level[b] - 2*level[lca];
}

int main()
{
 int n ,a , b , q, K,D,T;

    cin>>T;
    for(T = 0; T <= 5;T++){
 cin>>n>>q;

 for(int i=1;i<=n;i++)
 {
  for(int j=0;j<=maxN;j++)
  LCA[i][j] = -1;
 }

 for(int i=1;i<n;i++)
     cin>>a>>b , ar[a].pb(b) , ar[b].push_back(a);

 init(n);
    vector<int> answers;

 while(q--)
 {
     cin>>K;
     int query[K];
     int answer=0;
     cin>>D;
     for(int i=0;i<K;i++)
         cin>>query[i];
    for(int i=0;i<K-1;i++)
         for(int j=i+1;j<K;j++)
             if(getDist(query[i],query[j])==D)
                 answer+=1;

    answers.push_back(answer);

 }
 int i;
 for(i=0; i < answers.size(); i++)
        cout << answers.at(i) << endl;
break;
}
}
