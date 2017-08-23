#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<cmath>
#include<set>
#include<stack>
#define ll long long
#define pb push_back
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))
#define cls(name,x) memset(name,x,sizeof(name))
#define pos first
#define index second
#define mp make_pair
using namespace std;
const int inf=1e9+10;
const ll llinf=1e16+10;
const int maxn=1e5+10;
const int maxm=2e5+10;
const int mod=1e9+7;
int n;
ll dp[maxn][2][2];
vector<int> v[maxn];
vector<int> tv[maxn];
int vis[maxn];
void solve(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int to=v[x][i];
        solve(to);
    }
    dp[x][0][0]=dp[x][1][0]=1;//孤立点
    dp[x][0][1]=dp[x][1][1]=0;//非孤立点
    for(int i=0;i<v[x].size();i++)
    {
        int to=v[x][i];
        dp[x][1][0]=(dp[x][1][0]*dp[to][0][1])%mod;
        dp[x][0][0]=(dp[x][0][0]*dp[to][1][1])%mod;
    }//若为孤立点,则子节点都为颜色相异的非孤立点
    ll t1=1,t2=1;
    for(int i=0;i<v[x].size();i++)
    {
        int to=v[x][i];
        t1=(t1*(dp[to][1][0]+dp[to][1][1]+dp[to][0][1]))%mod;
    }
    for(int i=0;i<v[x].size();i++)
    {
        int to=v[x][i];
        t2=(t2*dp[to][0][1])%mod;
    }
    dp[x][1][1]=((t1-t2)%mod+mod)%mod;
    //若为非孤立点,则子节点至少存在一个颜色相同的孤立点或者非孤立点，其他子节点必为颜色相异的非孤立点
    t1=1;t2=1;
    for(int i=0;i<v[x].size();i++)
    {
        int to=v[x][i];
        t1=(t1*(dp[to][0][0]+dp[to][0][1]+dp[to][1][1]))%mod;
    }
    for(int i=0;i<v[x].size();i++)
    {
        int to=v[x][i];
        t2=(t2*dp[to][1][1])%mod;
    }
    dp[x][0][1]=((t1-t2)%mod+mod)%mod;
    //若为非孤立点,则子节点至少存在一个颜色相同的孤立点或者非孤立点，其他子节点必为颜色相异的非孤立点
}
void tdfs(int x)
{
    vis[x]=1;
    for(int i=0;i<tv[x].size();i++)
    {
        int to=tv[x][i];
        if(!vis[to])
        {
            v[x].pb(to);
            tdfs(to);
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            tv[a].pb(b);
            tv[b].pb(a);
        }
        cls(vis,0);
        tdfs(1);
        solve(1);
        printf("%lld\n",(dp[1][0][1]+dp[1][1][1])%mod);
    }
    return 0;
}
