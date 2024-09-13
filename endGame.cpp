#include<iostream>
#include<queue>
#include<tuple>

using namespace std;
int n,m;
char table[1005][1005];
queue<tuple<int,int,int> > q;
int T_num;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans=0;
void bfs()
{
    while(!q.empty())
    {
        auto [x,y,s]=q.front();
        q.pop();
        if(table[x][y]=='T')
        {
            T_num--;
            ans=max(ans,s);
        }
        else if(table[x][y]=='C') continue;
        for(int i=0;i<4;i++)
        {
            if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m)
            {
                q.push({x+dx[i],y+dy[i],s+1});
            }
        }
        table[x][y]='C';
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>table[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(table[i][j]=='I')
            {
                 q.push({i,j,0});
            }
            else if(table[i][j]=='T')
                T_num++;
        }
    bfs();
    
    if(T_num!=0) ans=-1;
    cout<<ans<<endl;
    return 0;
}
